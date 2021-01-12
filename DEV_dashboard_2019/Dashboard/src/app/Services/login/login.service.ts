import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})
export class LoginService {
  username: string;
  password: string;
  
  constructor() { 
    
  }

  setUsername(new_username) {
    this.username =  new_username;
  }

  getUsername() {
    return this.username;
  }

  setPassword(new_password) {
    this.password =  new_password;
  }

  getPassword() {
    return this.password;
  }

  getIsLogged(){
    if (localStorage.getItem("isLogged") === null){
      return false;
    } else {
      return localStorage.getItem('isLogged')
    }
    ;    
  }

  setIslogged(){
    localStorage.setItem('isLogged', 'true');
  }

  logout(){
    localStorage.setItem('isLogged', 'false');
  }
}
