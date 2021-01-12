import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { WidgetsService } from '../../../Services/widgets/widgets.service';
import { OauthgoogleService } from 'src/app/Services/oauthGoogle/oauthgoogle.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-youtube',
  templateUrl: './youtube.component.html',
  styleUrls: ['./youtube.component.css']
})
export class YoutubeComponent implements OnInit {

  Likes = 0;
  Dislikes = 0;
  videoViews = 0;
  commentCount = 0;
  totalVideo = 0;
  videoId: string;
  Top5Comments = [];
  
  private channelId = "UCP46_MXP_WG_auH88FnfS1A";
  private apiKey = "AIzaSyD42Jy8DsixDRJmdhAorxeBcPZw2RWVCVQ";
  
  constructor(private http: HttpClient,
              private widgetsService: WidgetsService,
              private googleauth: OauthgoogleService,
              public rooter: Router
) { 

    // On récupère l'ID de la derniere vidéo de Nota Bene
   
    let url = 'https://www.googleapis.com/youtube/v3/search?key=' + this.apiKey + '&channelId=' + this.channelId + '&order=date&part=snippet &type=video,id&maxResults=1';
    this.http.get(url)
      .subscribe(((res:{items:any}) => {
        this.videoId = res.items[0].id.videoId;

        // Likes / Dislikes / Nb Views / comments
       this.getStats();
       }))
      

  }

  ngOnInit(): void {
 
  }

  getStats(){
        
    // Likes / displikes/ comments
    let url2 = " https://www.googleapis.com/youtube/v3/videos?part=statistics&id=" + this.videoId +"&key="+ this.apiKey;
    this.http.get(url2)
      .subscribe(((res:{items:any}) => {
        this.Likes = +res.items[0].statistics.likeCount;
        this.Dislikes = +res.items[0].statistics.dislikeCount;
        this.commentCount = res.items[0].statistics.commentCount;
        
      }));
      
    if (this.Top5Comments.length == 0){
      // comments text
      let url3 = "https://www.googleapis.com/youtube/v3/commentThreads?key="+this.apiKey+"&textFormat=plainText&part=snippet&videoId="+ this.videoId+"&maxResults=5"
      this.http.get(url3)
      .subscribe(((res:{items:any}) => {
        for( let i =0; i < 5; i++){
          this.Top5Comments.push(res.items[i].snippet.topLevelComment.snippet.authorDisplayName  + " : " + res.items[i].snippet.topLevelComment.snippet.textDisplay);
        };
      }))
    }

    }

    like(){
      // on verifie si le client est co pour pouvoir liker
      if (this.widgetsService.getGoogleauth() == "true"){
        let url4 = "https://www.googleapis.com/youtube/v3/videos/rate?key="+this.apiKey+"&videoId="+ this.videoId+"&like";
        this.http.post(url4,'like');
        this.getStats();
        this.Likes += 1;
      }
      // Si il ne l'est pas, il se co
      else {
        this.googleauth.startAuth();
      }
    }
 
    dislike(){
      // on verifie si le client est co pour pouvoir disliker
      if (this.widgetsService.getGoogleauth() == "true"){
        let url5 = "https://www.googleapis.com/youtube/v3/videos/rate?key="+this.apiKey+"&videoId="+ this.videoId+"&dislike";
        this.http.post(url5, 'dislike');
        this.getStats();
        this.Dislikes += 1;  
      }
      // Si il ne l'est pas, il se co
      else {
        this.googleauth.startAuth();
      }
    }

    remove_widget(event: any){
      this.widgetsService.remove_service(event);
    }

    isDisplay(name){
      return localStorage.getItem(name)
    }
}
