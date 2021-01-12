import { Component, OnInit, ChangeDetectorRef } from '@angular/core';
import { UsernameService } from './Services/username.service';
import { ChanelService } from './Services/chanel.service';
import { SocketService} from './Services/socket.service';
import { HttpClient } from '@angular/common/http';
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})

export class AppComponent{
  title = 'TchatCheur';
  chanels = [];  
  socket;
  users= [];
  log = {};

  constructor(private usernamesevice: UsernameService,
    private chanelservice: ChanelService,
    private socketservice: SocketService,
    private http: HttpClient,
    private cdr: ChangeDetectorRef
    ) {  

      this.socket = this.socketservice.getSocket();
      var username = this.usernamesevice.getUsername();

      this.socket.on('room-list', data => {
        this.chanels=data 
        if ( this.chanels.length != 0)  {
            this.socket.emit('new-user',this.chanels[0] , username );
        }
      });

        this.socket.on('room-created', data => {
            this.log[data] = {messages: {}, users: []};
            this.chanels.push(data);
            this.cdr.detectChanges();
        });

      this.socket.on('chat-message-log', data =>{
        this.log[this.chanelservice.getchanelName()] = {
          messages: data.messages,
          users: [],
        };

        for (var key in data.users){
          this.log[this.chanelservice.getchanelName()].users.push(data.users[key]);
        }
      })
      

      this.socket.on('user-connected', data =>{
        console.log('ICI');
          this.log[data.room].users.push(data.user);
          console.log("ICI")
        this.users = this.log[this.chanelservice.getchanelName()].users;
        console.log(this.users);
        this.cdr.detectChanges();
      })

      this.socket.on('user-disconnected', data =>{
          var index = this.log[data.room].users.indexOf(data.user)
          if (index != -1)
              this.log[data.room].users.splice(index, 1)
        this.users = this.log[this.chanelservice.getchanelName()].users;
        this.cdr.detectChanges();
      })

      this.socket.on('room-deleted', room => {
        this.users = [];
        const index: number = this.chanels.indexOf(room);
        if (index != -1)
            this.chanels.splice(index,1);
        delete this.log[room];
        if (this.chanels.length == 0 || this.chanelservice.getchanelName() == room) {
          this.chanelservice.setMessagestoZero();
        }
        this.cdr.detectChanges();
      })

      this.users = chanelservice.getUsers();
  }  

  delete_room(room) {
    var verif = confirm('Etes-vous sûr de vouloir supprimer ce chanel ?');
    
    if ( verif == true){
      fetch(`http://localhost:3000/delete/${room}`, {
        method: 'DELETE',
        headers: {'Access-Control-Allow-Origin':'*',
        'Content-type': 'application/json; charset=UTF-8'}   
      })
    }


  }

  onSelect(chanel) {
    this.chanelservice.setchanelName(chanel);
    this.users = this.log[this.chanelservice.getchanelName()].users;
    this.cdr.detectChanges();
    }
}