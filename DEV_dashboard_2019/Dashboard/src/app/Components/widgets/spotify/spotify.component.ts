import { Component, OnInit } from '@angular/core';
import { WidgetsService } from '../../../Services/widgets/widgets.service';
import { SpotifyService } from '../../../Services/spotify/spotify.service';
import { HttpClient } from '@angular/common/http';
import { Router } from '@angular/router';
@Component({
  selector: 'app-spotify',
  templateUrl: './spotify.component.html',
  styleUrls: ['./spotify.component.css']
})
export class SpotifyComponent implements OnInit {

  Artiste1;
  Artiste2;

  img_card1;
  img_card2;


  constructor(private widgetsService: WidgetsService,
              private spotify: SpotifyService,
              public rooter: Router) {
                localStorage.setItem('card1', 'true')
                localStorage.setItem('card2', 'true')

                spotify.connect();
               }

  ngOnInit(): void {
    fetch("https://api.spotify.com/v1/me/top/artists?time_range=medium_term&limit=10&offset=5", {
      headers: {
        Accept: "application/json",
        Authorization: "Bearer BQDs7Ru5iNaKktubeaHLYxebPizgEqOPu0v3A9DXDFYtcIFZOUHTgru_CbQO0Xmtzf3Rl5319yER16ltxY5rBtIXuvAjwocTyYxdmTV9_u68N3HuNqyKVZq2gGn-N2Umbxq0oT4ywUFH_CaMuOo",
        "Content-Type": "application/json"
      }
    }).then(res=>{
     // console.log(res.json())
    })
  
  }


  connectSpotify(){
    var url = "https://accounts.spotify.com/authorize?client_id=671b934038634cea956d82f5c5368770&response_type=token&redirect_uri=http://localhost:4200/spotify&scope=user-read-private user-read-email user-follow-read&state=spotify";
    window.location.href = url;
    var access_token = this.getParameterByName('access_token',window.location.href);
    localStorage.setItem('access_token',access_token)
  }

  getParameterByName(name: string, url: string): string {
    name = name.replace(/[\[\]]/g, "\\$&");
    let regex = new RegExp("[?&#]" + name + "(=([^&#]*)|&|#|$)"),
                results = regex.exec(url);
    if (!results) return null;
    if (!results[2]) return '';
        return decodeURIComponent(results[2].replace(/\+/g, " "));
}

  remove_widget(event: any){
    this.widgetsService.remove_service(event);
  }
  
  isDisplay(name){
    return localStorage.getItem(name)
  }
}
