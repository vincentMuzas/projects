import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class RegisterService {
  username: string;
  password: string;

  constructor() { }

  setUsername(new_username) {
    this.username =  new_username;
  }

  setPassword(new_password) {
    this.password =  new_password;
  }

  getUsername() {
    return this.username;
  }

  getPassword() {
    return this.password;
  }
  
}
