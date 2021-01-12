import { NgModule } from '@angular/core';
import { Routes, RouterModule } from '@angular/router';
import { ServiceComponent } from './Components/service/service.component';
import { HomePageComponent } from './Components/home/home-page.component';
import { SteamComponent } from './Components/widgets/steam/steam.component';
import { YoutubeComponent } from './Components/widgets/youtube/youtube.component';
import { GoogleMapsComponent } from './Components/widgets/google-maps/google-maps.component';
import { SpotifyComponent } from './Components/widgets/spotify/spotify.component';

const routes: Routes = [
{
  path: 'home',
  component: HomePageComponent,
  pathMatch: 'full',
},
{
  path: 'service',
  component: ServiceComponent,
  pathMatch: 'full',
},
{
  path: 'youtube',
  component: YoutubeComponent,
  pathMatch: 'full',
},
{
  path: 'rss',
  component: SteamComponent,
  pathMatch: 'full',
},
{
  path: 'spotify',
  component: SpotifyComponent,
  pathMatch: 'full',
},
{
  path: 'google-maps',
  component: GoogleMapsComponent,
  pathMatch: 'full',
},
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { 
}
