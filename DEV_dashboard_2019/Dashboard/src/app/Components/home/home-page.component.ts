import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { WidgetsService } from '../../Services/widgets/widgets.service';
@Component({
  selector: 'app-home-page',
  templateUrl: './home-page.component.html',
  styleUrls: ['./home-page.component.css']
})
export class HomePageComponent implements OnInit {
  
  // Client ID et Secret ID Spotify
  redirect_uri = "/home";
  client_id_spotify = "671b934038634cea956d82f5c5368770";
  client_secret_spotify = "53a4f0b6eb2c425aad00d07c7fc4a731";
  user_playlist = "GET https://api.spotify.com/v1/users/{user_id}/playlists"
  refresh_timer:string;
  timer;
  services = [];


  constructor(private http: HttpClient,
              private widgetService: WidgetsService) {

                this.services = this.widgetService.getServicesAvailable();

              }


  ngOnInit() {


    if (localStorage.getItem('timer') === null) {
      this.refresh_timer = prompt('Time before general refreshing (s) ?');
      this.timer = parseInt(this.refresh_timer);
      localStorage.set('timer', this.refresh_timer)
    } else {
      this.timer = parseInt(localStorage.getItem('timer'));
    }

    setTimeout(
      function(){ 
      location.reload(); 
      }, 1000*this.timer); 
   }

  isDisplay(name){
    for ( let i = 0; i < this.services.length; i++){
      if ( this.services[i].name == name){
        return true;
      }
    }
    return false;
  }
}
