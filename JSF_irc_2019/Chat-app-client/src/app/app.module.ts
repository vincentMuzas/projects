import { BrowserModule } from '@angular/platform-browser';
import { NgModule } from '@angular/core';

import { SocketIoModule, SocketIoConfig } from 'ngx-socket-io';
import { HttpClientModule } from '@angular/common/http';
import { AppRoutingModule } from './app-routing.module';

import { AppComponent } from './app.component';
import { NbThemeModule, NbLayoutModule, NbSidebarModule, NbButtonModule, NbChatModule, NbCardModule, NbListModule, NbInputModule } from '@nebular/theme';
import { NbEvaIconsModule } from '@nebular/eva-icons';
import { ChanelsComponent } from './Components/chanels/chanels.component';
import { UsernameService } from './Services/username.service';
import { ChanelService } from './Services/chanel.service';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';
const config: SocketIoConfig = { url: 'http://localhost:3000', options: {} };

@NgModule({
  declarations: [
    AppComponent,
    ChanelsComponent,    
  ],
  imports: [
    BrowserModule,
    BrowserAnimationsModule,
    HttpClientModule,
    SocketIoModule.forRoot(config),
    AppRoutingModule,
    NbThemeModule.forRoot(),

    NbLayoutModule,
    NbSidebarModule.forRoot(), // NbSidebarModule.forRoot(), //if this is your app.module
    NbButtonModule, NbThemeModule.forRoot({ name: 'dark' }), 
    NbEvaIconsModule,
    NbChatModule.forRoot(),
    NbCardModule,
    NbListModule,
    NbInputModule,
  ],
  
  providers: [
    UsernameService,
    ChanelService
    ],
  bootstrap: [AppComponent]
})
export class AppModule { 
  
}
