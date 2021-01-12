const express = require('express')
const cors = require('cors')
const app = express()
const server = require('http').Server(app)
const crypto = require('crypto')
const uuid = require('node-uuid')
const cookie_parser = require('cookie-parser')
const bodyParser = require('body-parser')

app.use(cors({
    preflightContinue: true,
    credentials: true,
    origin: "http://localhost:4200"
  }));
app.use(cookie_parser())
app.use(express.static('public'))
app.use(express.urlencoded({ extended: true }))
app.use(bodyParser.urlencoded({ extended: true }))
app.use(bodyParser.json())


var mysql = require('mysql');
var con = mysql.createConnection({
    host: "127.0.0.1",
    database: "dashboard",
    user: "dashboard",
    password: "dashboard"
})

sql = "SELECT * FROM widget"
widgets = {}
con.query(sql, function(err, result) {
    if (err) throw err
    result.forEach(line => {
        widgets[line.name] = line.id
    })
})

const user_list = []

app.post('/login', (req, res) => {
    sql = 'SELECT * FROM users WHERE username = ? AND passwd = ?'
    hash = false
    user = false
    con.query(sql, [req.body.username, req.body.password], function(err, result) {
        if (err) throw err
        result.forEach(line => {
            user = line.username
            id_user = line.id
            if (line.hash != "") 
                hash = line.uuid
            else {
                hash = generate_uid()
                sql = "UPDATE `users` SET `uuid` = ? WHERE `users`.`id` = ?;"
                con.query(sql, [hash, line.id])
            }
        })
        if (hash == false) {
            res.status(400).send("invalid login")
        }
        else {
            res.cookie('uuid', hash,  {expires: new Date(Date.now() + 86400000)})
            res.status(200).json({hash: hash})
            user_list.push({id: id_user, name: user, uuid: hash})
        }
    })
})



app.post('/register', (req, res) => {
    sql = "SELECT * FROM `users` WHERE `username` = ?"
    con.query(sql, [req.body.username], function(err, result) {
        if (err) throw err
        if (!result.length)
        {
            sql = "INSERT INTO `users` (`username`, `passwd`, `uuid`) VALUES (?, ?, ?);"
            con.query(sql, [req.body.username, req.body.password, generate_uid()])
            res.status(200).json({username: req.body.username})
        }
        else {
            res.status(400).send("user already exist")
        }
    })
})

app.get('/user_widgets', (req, res) => {
    user_list.forEach(user => {
        if (user.uuid == req.cookies.uuid) {
            sql = "SELECT user_widgets.widget_id, widget.name, user_widgets.params FROM `user_widgets` JOIN `users` ON users.uuid = ? JOIN `widget` ON user_widgets.widget_id = widget.id WHERE users.id = user_widgets.id_user"
            con.query(sql, [req.cookies.uuid], function(err, result) {
                if (err) throw err
                res.json(result)
            })
        }
    })
})

app.post('/widget_update', (req, res) => {

    user_list.forEach(user => {
        if (user.uuid == req.cookies.uuid) {
            sql = "SELECT * FROM `user_widgets` JOIN `users` ON users.uuid = ? JOIN `widget` ON user_widgets.widget_id = widget.id WHERE users.id = user_widgets.id_user"
            var user_widgets = {}
            con.query(sql, [req.cookies.uuid], function(err, result) {
                if (err) throw err
                var user_widgets = {}
                result.forEach(line => {
                    user_widgets[line.name] = line.params
                })
                for (var key in req.body) {
                    if (widgets[key] == undefined)
                        continue
                    if (user_widgets[key] == undefined) {
                        sql = "INSERT INTO user_widgets (id_user, widget_id, params) VALUES (?, ?, ?)"
                        con.query(sql, [user.id, widgets[key], req.body[key]])
                    } else {
                        sql = "UPDATE user_widgets SET params = ? WHERE id_user = ? AND widget_id = ?"
                        con.query(sql, [req.body[key], user.id, widgets[key]])
                    }
                    
                }
            })
            res.status(200).send()
        } else {
            res.status(400).send()
        }
    })
})

app.get('/about.json', (req, res) => {
    object = {"customer": {"host": req.ip}, "server": {"current_time": Date.now(), "services": []}}
    sql = "SELECT * FROM `widget`"
    con.query(sql, function(err, result) {
        if (err) throw err;
        result.forEach(line => {
            var wid = {"name": line.name, "description": line.description, "params": [{"name": "param", "type": "string"}]}
            object.server["services"].push({"name": line.name, "widgets": [wid]})
        })
        res.json(object);
    })
})

server.listen(8080)


function generate_uid() {
    return (uuid.v1())
}