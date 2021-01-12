import { BrowserModule } from '@angular/platform-browser';
import { RouterModule, Routes } from '@angular/router';
import { HttpClientModule } from '@angular/common/http';
import { HttpModule } from '@angular/http';
import { NgModule } from '@angular/core';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { ServiceComponent } from './Components/service/service.component';
import { AuthModule } from './auth/auth.module';
import { HomePageComponent } from './Components/home/home-page.component';
import { WidgetsComponent } from './Components/widgets/widgets.component';
import { GoogleMapsComponent } from './Components/widgets/google-maps/google-maps.component';
import { YoutubeComponent } from './Components/widgets/youtube/youtube.component';
import { AgmCoreModule } from '@agm/core';
import { NgxYoutubePlayerModule } from 'ngx-youtube-player';
import { SteamComponent } from './Components/widgets/steam/steam.component';
import { FormsModule } from '@angular/forms';
import { SpotifyComponent } from './Components/widgets/spotify/spotify.component';
import { CookieService } from 'ngx-cookie-service';

@NgModule({
  declarations: [
    AppComponent,
    ServiceComponent,
    HomePageComponent,
    WidgetsComponent,
    GoogleMapsComponent,
    YoutubeComponent,
    SteamComponent,
    SpotifyComponent,
  ],
  imports: [
    BrowserModule,
    FormsModule,
    NgxYoutubePlayerModule.forRoot(),
    AgmCoreModule.forRoot({
      apiKey: 'AIzaSyD42Jy8DsixDRJmdhAorxeBcPZw2RWVCVQ'
    }),  
    AppRoutingModule,
    HttpClientModule,
    AuthModule,
    HttpModule,
  ],
  providers: [CookieService],
  bootstrap: [AppComponent]
})
export class AppModule { 
  
}
