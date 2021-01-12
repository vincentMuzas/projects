import { Injectable } from '@angular/core';
import { UsernameService } from './username.service';
import { SocketService } from './socket.service';

@Injectable({
  providedIn: 'root'
})

export class ChanelService {
    socket;
    data: string;
    ChanelList: [];
    my_string: string;
    messages: any[];
    users = [];
    log = {};

  constructor(private socketservice: SocketService,
     private usernameservice:UsernameService) { 
     this.socket = socketservice.getSocket();

    // Récupère tous les utilisateurs de la room
    this.socket.on('chat-message-log', data => {
      var tmp = [];
      for( var key in data.users) {
        tmp.push(data.users[key]);
      }
      this.users = tmp;
    })

    // Ajoute les utilisateurs qui vienne de se connecté a la room
    this.socket.on('user-connected', data =>{
      if (data.room == this.my_string){ 
        this.add_User(data.user);
      }
    })

    // Supprime les utilisateurs déconnecté de la room
    this.socket.on('user-disconnected', data =>{
      this.remove_User(data.user);
    })

  }
  
  getChanels() {
    return this.ChanelList;
  }

  setchanelName(new_chanelName) {
    this.my_string = new_chanelName;
    this.messages = []; // modifier l'affectation Ã  "log[new_channelName].messages" de channel component
    this.socket.emit('new-user',this.my_string , this.usernameservice.getUsername());
     
    // if (this.log[new_chanelName] == null) {
    //     this.log[new_chanelName] = []
    //     this.socket.emit('new-user',this.my_string , this.usernameservice.getUsername());
    // }
    // else{
    //     this.messages = this.log[new_chanelName].messages;
    // }

}
  
  getchanelName(): string {
    return this.my_string;
  }
  
  getMessages(){
    return this.messages;
  }

  setMessagestoZero()
  {
    this.messages=  [];
  }

  add_User(user){
    this.users.push(user);
  }

  getlog(){
    return this.log;
  }

  remove_User(user){
    const index: number = this.users.indexOf(user);
    if (index != -1){
      this.users.splice(index,1);
    }
}

  setLog(log_obj){
    this.log = log_obj;
  }

  getUsers(){
    return this.users;
  }
}
 

