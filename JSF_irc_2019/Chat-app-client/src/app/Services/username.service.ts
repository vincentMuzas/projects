import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root'
})

export class UsernameService {

  pseudo: string;

  constructor() {
  
  }

  getUsername(): string {
    while (this.pseudo === undefined || this.pseudo === "") {
      this.pseudo = prompt("Pseudo")
    }
    return this.pseudo;
  }
}
