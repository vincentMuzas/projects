import { Component, OnInit } from '@angular/core';
import { LoginService } from '../../Services/login/login.service';
import { HttpClient } from '@angular/common/http';
import { WidgetsService } from '../../Services/widgets/widgets.service';
@Component({
  selector: 'app-service',
  templateUrl: './service.component.html',
  styleUrls: ['./service.component.css']
})
export class ServiceComponent implements OnInit {
  
  services = {service: '', params: ''};
  AllServices = [];
  username: string;

  constructor(private loginservice: LoginService,
              private http:HttpClient,
              private widgetService:WidgetsService )
  { 
    this.username = loginservice.getUsername();

    // Va chercher les services deja choisi avant dans la bdd
    fetch('http://localhost:8080/user_widgets', {
      method: 'GET',
      headers: {'Access-Control-Allow-Origin':'*',
      'Content-type': 'application/json'},
      credentials: 'include'
    }).then(res => {
      res.json().then(serv =>{
        for (let j = 0; j < serv.length; j++){
          this.AllServices.push(serv[j])
            let elem =  serv[j].name;
            localStorage.setItem(elem, 'true');
            let followed_service = <HTMLInputElement>document.getElementById(elem);
            followed_service.innerHTML = 'Followed';
            followed_service.className = "btn btn-success";
        }
      });
    })
  }

  ngOnInit(): void {

  }

  follow(event: any) {
    var button_id = event.target.id;
    localStorage.setItem(button_id, 'true');
    var follow_button = <HTMLInputElement>document.getElementById(button_id);
    if (follow_button.innerHTML == "Follow"){
      follow_button.innerHTML = 'Followed';
      follow_button.className = "btn btn-success";      
      this.AllServices.push({service: button_id, params: 'default'});
    } else {
      localStorage.setItem(button_id, 'false');
      follow_button.innerHTML = 'Follow';
      follow_button.className = "btn btn-outline-primary";
      for (let i = 0; i < this.AllServices.length; i++){
        if ( this.AllServices[i].service == button_id){
          var index = i;
        } 
      }
      this.AllServices.splice(index, 1);
    }
  }

  Submit(){
    
      // Envoi les services choisi par l'utilisateurs à la bdd
      this.AllServices.forEach(element => {
        var my_object = {}
        my_object[element.service] =  element.params
        fetch(`http://localhost:8080/widget_update`, {
          method: 'POST',
          headers: {'Access-Control-Allow-Origin':'*',
          'Content-type': 'application/json; charset=UTF-8'} ,
          credentials:'include',
          body: JSON.stringify(my_object) 
        })
      });
  }
}
