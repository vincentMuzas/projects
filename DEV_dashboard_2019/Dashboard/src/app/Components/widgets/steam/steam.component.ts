import { Component, OnInit } from '@angular/core';
import { WidgetsService } from '../../../Services/widgets/widgets.service';
import { HttpClient } from '@angular/common/http';
import { NewsRss } from './news-rss';
import * as xml2js from "xml2js";
import { Router } from '@angular/router';

@Component({
  selector: 'app-steam',
  templateUrl: './steam.component.html',
  styleUrls: ['./steam.component.css']
})
export class SteamComponent implements OnInit {

  RssData: NewsRss;

  constructor(private widgetsService: WidgetsService,
              private http: HttpClient,
              public rooter: Router) {
              }

  GetRssFeedData() {
    const requestOptions: Object = {
      observe: "body",
      responseType: "text"
    };
    this.http
      .get<any>("https://gadgets.ndtv.com/rss/feeds", requestOptions)
      .subscribe(data => {
        let parseString = xml2js.parseString;
        parseString(data, (err, result: NewsRss) => {
          this.RssData = result;
        });
      });
  }

  ngOnInit(): void {
  }

  remove_widget(event: any){
    this.widgetsService.remove_service(event);
  }

  isDisplay(name){
    return localStorage.getItem(name)
  }
}
