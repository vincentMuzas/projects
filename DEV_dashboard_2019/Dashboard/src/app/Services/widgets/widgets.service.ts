import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
@Injectable({
  providedIn: 'root'
})
export class WidgetsService {
  services = [];
  constructor(private http: HttpClient) {
    localStorage.setItem('isLoggedWithGoogle', "false");
   }

  remove_service(event:any){
    // Route pour delete un widget 
    var button_id = event.target.id;
    localStorage.setItem(button_id, 'false');
  }

  getGoogleauth(){
    return localStorage.getItem('isLoggedWithGoogle');
  }

  setGoogleauth(val:string){
    localStorage.setItem('isLoggedWithGoogle', val);
  }

  getServicesAvailable(): any{
   

    // Va chercher les services deja choisi avant dans la bdd
    fetch('http://localhost:8080/user_widgets', {
      method: 'GET',
      headers: {'Access-Control-Allow-Origin':'*',
      'Content-type': 'application/json'},
      credentials: 'include'
    }).then(res => {
      res.json().then(serv =>{
        for (let j = 0; j < serv.length; j++){
          this.services.push(serv[j])
        }

        return this.services;
      });
    })
    return this.services;

  }
}