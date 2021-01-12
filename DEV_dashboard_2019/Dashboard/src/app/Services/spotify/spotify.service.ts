import { Injectable } from '@angular/core';
import { HttpClient } from '@angular/common/http';
import { Http } from '@angular/http';
import 'rxjs/add/operator/map';

@Injectable({
  providedIn: 'root'
})
export class SpotifyService {
  private artistUrl: string;
  private albumsUrl: string;
  private albumUrl: string;
  constructor(private http:HttpClient) { }


connect(){
  
}

//   getArtist(id:string){
//     this.artistUrl = 'https://api.spotify.com/v1/artists/'+id;
//     return this._http.get(this.artistUrl)
//         .map(res => res.json());
// }

// getAlbums(artistId:string){
//     this.albumsUrl = 'https://api.spotify.com/v1/artists/'+artistId+'/albums';
//     return this._http.get(this.albumsUrl)
//         .map(res => res.json());
// }

// getAlbum(id:string){
//     this.albumUrl = 'https://api.spotify.com/v1/albums/'+id;
//     return this._http.get(this.albumUrl)
//         .map(res => res.json());
// }
}
