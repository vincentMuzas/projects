import { Component, OnInit } from '@angular/core';
import { WidgetsService } from '../../Services/widgets/widgets.service';
@Component({
  selector: 'app-widgets',
  templateUrl: './widgets.component.html',
  styleUrls: ['./widgets.component.css']
})
export class WidgetsComponent implements OnInit {

  WeatherData:any;
  constructor(private widgetsService: WidgetsService) { }
  
  ngOnInit() {
    this.WeatherData = {
      main : {},
      isDay: true
    };
    this.getWeatherData();
  }
  
  remove_widget(event: any){
    this.widgetsService.remove_service(event);
  }

  closeNote(){
    let notepad = <HTMLInputElement>document.getElementById("note");
    notepad.className ="toast fade hidden";
  }

  getWeatherData(){
    fetch('https://api.openweathermap.org/data/2.5/weather?q=toulouse&appid=bd199ed9452b6dc2f6c0f8e2878aab75')
    .then(response=>response.json())
    .then(data=>{this.setWeatherData(data);})

  }

  setWeatherData(data){
    this.WeatherData = data;
    let sunsetTime = new Date(this.WeatherData.sys.sunset * 1000);
    this.WeatherData.sunset_time = sunsetTime.toLocaleTimeString();
    let currentDate = new Date();
    this.WeatherData.isDay = (currentDate.getTime() < sunsetTime.getTime());
    this.WeatherData.temp_celcius = (this.WeatherData.main.temp - 273.15).toFixed(0);
    this.WeatherData.temp_min = (this.WeatherData.main.temp_min - 273.15).toFixed(0);
    this.WeatherData.temp_max = (this.WeatherData.main.temp_max - 273.15).toFixed(0);
    this.WeatherData.temp_feels_like = (this.WeatherData.main.feels_like - 273.15).toFixed(0);
  }


  isDisplay(name){
    return localStorage.getItem(name)
  }
}
