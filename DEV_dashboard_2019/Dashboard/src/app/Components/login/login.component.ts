import { Component, OnInit } from '@angular/core';
import { LoginService } from '../../Services/login/login.service';
import { Router } from '@angular/router';
import { HttpClient } from '@angular/common/http';
@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {

  username: string;
  password: string;
  services = [];
  constructor(public loginservice: LoginService,
              private router: Router,
              private http: HttpClient) { 
              }

  ngOnInit(): void {

  }

  usernameLogin(event: any) {
    this.username = event.target.value;
  }

  passwordLogin(event: any) {
    this.password = event.target.value;
  }

  login(){
    
    var logs = { username: this.username, password: this.password};
      
    fetch(`http://localhost:8080/login`,{
      method: 'POST',
      headers: {'Access-Control-Allow-Origin':'*',
      'Content-type': 'application/json'},
      credentials: 'include',
      body: JSON.stringify(logs)
    }).then(res => {
      let code = res.status;

      if (this.username === undefined || this.password === undefined){
        alert("Username / Password cannot be empty.");
      } else {
         if ( code == 200 ) {
          this.loginservice.setPassword(this.password);
          this.loginservice.setUsername(this.username);
          if (this.services.length == 0){
            this.loginservice.setIslogged();
            this.router.navigate(['/service']);
            }         
          } else {
         alert("Username / Password invalid.")
          }
        }
      });
  }
}
