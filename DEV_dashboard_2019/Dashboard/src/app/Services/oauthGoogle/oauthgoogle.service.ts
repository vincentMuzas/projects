import { Injectable } from '@angular/core';
import { WidgetsService} from '../widgets/widgets.service';
import { HttpClient } from '@angular/common/http'; 

@Injectable({
  providedIn: 'root'
})
export class OauthgoogleService {

  url;

  constructor(private widgetservice: WidgetsService,
              private http: HttpClient) { 

    localStorage.setItem('GoogleclientSecret', "uDd0aPyc8jccv7JROQGz-Im9");
    localStorage.setItem('GoogleclientId', "332824167900-v5n4nmdf27b0l5aaa8u8l156cjgik1vh.apps.googleusercontent.com");
  }

  startAuth(){
    // Popup pour se connecter a google

      this.widgetservice.setGoogleauth("true");
  
  }  


  Saveresponse(responce) {
    this.url = 'http://localhost:4200/Api/Login/Savesresponse';
    return this.http.post(this.url, responce);
  }

}
