const express = require('express')
const cors = require('cors')
const app = express()
const server = require('http').Server(app)
const io = require('socket.io')(server)

app.set('views', './views')
app.set('view engine', 'ejs')
app.use(cors())
app.use(express.static('public'))
app.use(express.urlencoded({ extended: true }))

var mysql = require('mysql');
var con = mysql.createConnection({
    host: "127.0.0.1",
    database: "IRC",
    user: "irc",
    password: "irc"
})
const rooms = {}
con.connect(function(err) {
    if (err) throw err
    console.log("Connected to DB!")
    sql = "SELECT * FROM messages ORDER BY room, id"
    con.query(sql, function (err, result) {
        if (err) throw err
        result.forEach(line => {
            if (rooms[line.room] == null)
                rooms[line.room] = {users: {}, messages: {}}
            rooms[line.room].messages[line.id] = {user: line.user, message: line.message, date: line.date}
        })
        console.log("Imported chats!");
    });
});

app.get('/', (req, res) => {
    res.render('index', { rooms: rooms })
})

app.get('/home', (req, res) => {
    res.json({rooms: Object.keys(rooms)})
})

app.get('/:room', (req, res) => {
    if (rooms[req.params.room] == null)
        res.status(404).send("404 room not found")
    res.render('room', { roomName: req.params.room })
})

app.post('/room', (req, res) => {
    if (rooms[req.body.room] != null) {
        return res.status(400).send("400 room does not exist")
    }
    rooms[req.body.room] = { users: {}, messages: {}}
    io.emit('room-created', req.body.room)
    res.status(200).send("room created")
})

app.delete('/delete/:room', (req, res) => {
    if (rooms[req.params.room] != null) {
        sql = `DELETE FROM \`messages\` WHERE \`room\` = ?`
        con.query(sql, [req.params.room])
        io.in(req.params.room).emit('room-deleted', req.params.room )
        delete rooms[req.params.room]
        res.status(200).send("room created")
    }
    res.status(404).send("room not found")
})

server.listen(3000)

io.on('connection', socket => {
    io.to(socket.id).emit('room-list', Object.keys(rooms))
    socket.on('new-user', (room, name) => {
        if (rooms[room] != null) {
            socket.join(room)
            rooms[room].users[socket.id] = name
            socket.to(room).broadcast.emit('user-connected', { room: room, user: name })
            io.to(socket.id).emit('chat-message-log', rooms[room])
        }
        else {
            io.to(socket.id).emit('chat-mesaage-log-failed', room)
        }
    })
    socket.on('send-chat-message', (room, message) => {
        if (rooms[room] != null && rooms[room].users[socket.id] != null) {
            socket.to(room).broadcast.emit('chat-message', {message: message, user: rooms[room].users[socket.id], room: room })
            // insere la ligne dans la DB
            sql = `INSERT INTO \`messages\` (\`message\`, \`user\`, \`room\`) VALUES (?, ?, ?);`
            con.query(sql, [message, rooms[room].users[socket.id], room], function (err, result) {
                if (err) throw err
                sql = 'SELECT * FROM messages WHERE id = ' + result.insertId
                con.query(sql, function(err, result) {
                    if (err) throw err
                    result.forEach(line => {
                        rooms[room].messages[line.id] = {user: line.user, message: line.message, date: line.date}
                    })
                })
            })
        }
    })
    socket.on('disconnect', (room, name) => {
        getUserRooms(socket).forEach(room =>{
            socket.to(room).broadcast.emit('user-disconnected', { user: rooms[room].users[socket.id], room: room } )
            delete rooms[room].users[socket.id]
        })
    })
})

function getUserRooms(socket) {
    return (Object.entries(rooms).reduce((names, [name, room]) => {
        if (room.users[socket.id] != null)
            names.push(name)
        return (names)
    }, []))
}