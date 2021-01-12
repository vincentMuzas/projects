import { Component, OnInit } from '@angular/core';
import { LoginService } from './Services/login/login.service';
import { Router } from '@angular/router';
import { WidgetsService } from './Services/widgets/widgets.service';
@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  services = [];
  constructor(private loginservice: LoginService,
              private router: Router,
              private widgetService: WidgetsService){   

              // Pour la navbar, affiche le nom des services choisis
              var services_object = widgetService.getServicesAvailable();
              for ( let i = 0; i < services_object.length; i++){
                this.services.push(services_object[i].service)
              }
            }     

  title = 'Dashboard';

  getIsLogged(){
    return (this.loginservice.getIsLogged());
  }

  logout(){
    this.loginservice.logout();
    this.router.navigate['/login'];
  }
}
