import { Component, OnInit } from '@angular/core';
import { RegisterService } from '../../Services/register/register.service';
import { NgForm } from '@angular/forms';
import { Router } from '@angular/router';
import { HttpClient } from '@angular/common/http';
@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.css']
})
export class RegisterComponent implements OnInit {
  username: string;
  tpm_password: string;
  password: string;

  constructor(private registerservice: RegisterService,
              private router: Router,
              private http: HttpClient) { }

  ngOnInit(): void {
  }

  usernameRegister(event: any) {
    this.username = event.target.value;
    this.registerservice.setUsername(this.username);
  }

  passwordRegister(event: any) {
    this.tpm_password = event.target.value;
  }

  confirmPasswordRegister(event: any) {
    this.password = event.target.value;
  }

  register(){    
    if (this.username === undefined || this.password === undefined){
      alert("Username / Password cannot be empty.");
    } 

    if ( this.password == this.tpm_password && this.username != undefined){
      this.registerservice.setUsername(this.username);
      this.registerservice.setPassword(this.password);

      var logs = { username: this.username, password: this.password};
      
      fetch(`http://localhost:8080/register`,{
        method: 'POST',
        headers: {'Access-Control-Allow-Origin':'*',
        'Content-type': 'application/json'},
        credentials: 'include',
        body: JSON.stringify(logs)
      });
      this.router.navigate(['/login']);
      alert("Account created, you'll be redirected to login.");
    } else {
      alert('Password\'s dosn\'t match !');
    }
  }
}
