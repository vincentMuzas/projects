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

var MongoClient = require("mongodb").MongoClient;
const rooms = {}
var db;
MongoClient.connect("mongodb://localhost/", function(error, client) {
    if (error)
        throw error;
    db = client.db("IRC");
    console.log("Connected to DB!")
    db.collection("messages").find().toArray(function (error, results) {
        if (error) throw error;
        results.forEach(function(obj, i) {
            if (rooms[obj.room] == null)
                rooms[obj.room] = {users: {}, messages: {}}
            rooms[obj.room].messages[obj.id] = {user: obj.user, message: obj.message, date: obj.date}
        });
        console.log("Imported chats!");
        console.log(rooms);
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
    console.log("room " + req.body.room + " created");
})

app.delete('/delete/:room', (req, res) => {
    if (rooms[req.params.room] != null) {
        var objToFind = {room: req.params.room}
        db.collection("messages").deleteMany(objToFind, null, function(error, result) {
            if (error) throw error;   
        });
        io.in(req.params.room).emit('room-deleted', req.params.room )
        delete rooms[req.params.room]
        res.status(200).send("room deleted")
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
            var objNew = {message: message, user: rooms[room].users[socket.id], room: room, date: Date.now()}
            db.collection("messages").insertOne(objNew, null, function (error, results) {
                if (error) throw error;
            });
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