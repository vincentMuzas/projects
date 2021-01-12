import { Injectable } from '@angular/core';
import * as io from 'socket.io-client';

@Injectable({
  providedIn: 'root'
})
export class SocketService {

  socket = io('http://localhost:3000');

  constructor() {
    
   }
   

  deleteRoom(){
    
  }

  modifyRoomName(){

  }

  getSocket(){
    return this.socket;
  }
}
