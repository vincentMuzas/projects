import { Component, OnInit } from '@angular/core';
import { WidgetsService } from '../../../Services/widgets/widgets.service';
import { Router } from '@angular/router';

@Component({
  selector: 'app-google-maps',
  templateUrl: './google-maps.component.html',
  styleUrls: ['./google-maps.component.css']
})
export class GoogleMapsComponent implements OnInit {

  constructor( private widgetsService: WidgetsService,
               public rooter: Router) {

   }

  ngOnInit(): void {
  }

  latitude = 43.600000;
  longitude = 1.433333;
  locationChosen = false;

  onChoseLocation(event) {
    this.latitude = event.coords.lat;
    this.longitude = event.coords.lng;
    this.locationChosen = true;
  }

  remove_widget(event: any){
    this.widgetsService.remove_service(event);
  }

  isDisplay(name){
    return localStorage.getItem(name)
  }

}
