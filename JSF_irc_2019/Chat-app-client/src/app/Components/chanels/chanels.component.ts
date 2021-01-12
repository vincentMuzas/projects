import { Component, OnInit, ChangeDetectorRef } from '@angular/core';
import { ChanelService } from 'src/app/Services/chanel.service';
import { SocketService } from '../../Services/socket.service';
import { UsernameService } from '../../Services/username.service';
@Component({
  selector: 'app-chanels',
  templateUrl: './chanels.component.html',
  styleUrls: ['./chanels.component.css']
}) 

export class ChanelsComponent implements OnInit {
    chanels: [];
    chanelName= "";
    socket;
    username: string;
    messages: any[];
    log: {};
    
    constructor(private chanelservice: ChanelService,
      private socketservice: SocketService,
      private usernameservice: UsernameService,
      private cdr: ChangeDetectorRef) {

      this.socket = socketservice.getSocket();
      this.chanels = chanelservice.getChanels();
      this.username = usernameservice.getUsername();
      
      // Messages des autres utilisateurs de la room actuelle
      this.socket.on('chat-message', data => {
        this.other_messages(data);
        this.cdr.detectChanges();
      })
      
      // Ancien messages à recuperer de la room actuelle
      this.socket.on('chat-message-log', data =>{
          var loc = [];
          for(var key in data.messages){
            loc.push({
                text:data.messages[key].message,
                reply: data.messages[key].user == this.username ? true: false,
                date: data.date,
                sender: data.messages[key].user
              })
          }
          this.messages = loc;
          this.cdr.detectChanges();
        })

        this.socket.on('room-deleted', room => {
            if (room == this.chanelName) {
                this.messages = [];
                this.chanelName = "";
            }
            delete this.log[room];
            this.chanelservice.setLog(this.log);
            this.cdr.detectChanges();
        })

        this.socket.on('user-connected', data =>{
            if (data.room == this.getChanelName()) {
                var tmp;
                tmp.messages[0].message = `${data.name} joined the chat`;
                tmp.messages[0].sender = "AutoBot";
                this.appendMessage(0, tmp);
                this.cdr.detectChanges();
            }
          })
    
        this.socket.on('user-disconnected', data =>{
            if (data.room == this.getChanelName()) {
                var tmp;
                tmp.messages[0].message = `${data.name} left the chat`;
                tmp.messages[0].sender = "AutoBot";
                this.appendMessage(0, tmp);
                this.cdr.detectChanges();
            }
        })
  }

  // Envoi d'un message 
  send_message(message, event){
    this.chanelName = this.chanelservice.getchanelName();
    //this.setChanelName();
    this.messages.push({
      text: event.message,
      reply: true,
      date: new Date(),
      sender: this.username
    })
    this.socket.emit('send-chat-message', this.getChanelName(), event.message);
  }

  // Logs des anciens message de la room actuelle
  appendMessage(key, data) {
    this.messages.push({
      text:data.messages[key].message,
      reply: false,
      date: data.date,
      sender: data.messages[key].user
    })
}

  // Messages recu des autres utilisateurs
  other_messages(data){
      var obj = {
        text: data.message,
        reply: false,
        date: new Date(),
        sender: data.user
      }
    if ( data.room == this.chanelName){
        this.messages.push(obj)
    if (this.log[data.room] == null)
        this.log[data.room] == {messages: []}
    this.log[data.room].messages.push(obj)
    this.chanelservice.setLog(this.log);
  }
  }

  ngOnInit(): void {
  }

  getChanelName() {
    return this.chanelName;

  }

  getname(){
    return this.chanelservice.getchanelName();
  }

  setChanelName(){
    this.chanelName = this.chanelservice.getchanelName();
    this.messages = this.chanelservice.getlog()[this.chanelName].messages;
    this.cdr.detectChanges();
  }
}
