package com.dashboard.service.service;

import com.dashboard.model.Service;
import com.dashboard.model.User;
import com.dashboard.tool.Kurl;
import com.mashape.unirest.http.HttpResponse;
import com.mashape.unirest.http.JsonNode;
import com.mashape.unirest.http.Unirest;
import com.mashape.unirest.http.exceptions.UnirestException;
import org.json.JSONObject;
import org.springframework.context.annotation.Description;

import java.util.Optional;

@org.springframework.stereotype.Service
public class RapidApiService extends AbstractService {

    public RapidApiService(Optional<Service> service, Optional<User> user) {
        super(service, user);
    }

    @Description("Display weather data for a specific city")
    public JSONObject weather(String cityName, String cityAbbreviation) throws UnirestException {
        HttpResponse<String> response = Unirest.get("https://community-open-weather-map.p.rapidapi.com/weather?q={city}%2C{abbreviation}&lat=0&lon=0&callback=test&id=2172797&lang=null&units=%22metric%22%20or%20%22imperial%22&mode=xml%2C%20html")
                .header("x-rapidapi-key", "4b98948290msh3ca5db10bafc5a4p103407jsnc08bdfa07302")
                .header("x-rapidapi-host", "community-open-weather-map.p.rapidapi.com")
                .routeParam("city", cityName)
                .routeParam("abbreviation", cityAbbreviation)
                .asString();
        return new JSONObject(Kurl.format(response));
    }

    @Description("Get a fact about a day of year")
    public JSONObject historicalFacts(Integer month, Integer day) throws UnirestException {
        HttpResponse<String> response = Unirest.get("https://numbersapi.p.rapidapi.com/{month}/{day}/date?fragment=true&json=true")
                .header("x-rapidapi-key", "4b98948290msh3ca5db10bafc5a4p103407jsnc08bdfa07302")
                .header("x-rapidapi-host", "numbersapi.p.rapidapi.com")
                .routeParam("month", month.toString())
                .routeParam("day", day.toString())
                .asString();
        return new JSONObject(response);
    }

    @Description("Create new short URL from a long URL")
    public JSONObject shortUrl(String url) throws UnirestException {
        HttpResponse<JsonNode> response = Unirest.post("https://url-shortener-service.p.rapidapi.com/shorten")
                .header("content-type", "application/x-www-form-urlencoded")
                .header("x-rapidapi-key", "4b98948290msh3ca5db10bafc5a4p103407jsnc08bdfa07302")
                .header("x-rapidapi-host", "url-shortener-service.p.rapidapi.com")
                .body("url=" + url)
                .asJson();
        return response.getBody().getObject();
    }

    @Description("Get all current statistics for a specific country")
    public JSONObject covid(String country) throws UnirestException {
        HttpResponse<JsonNode> response = Unirest.get("https://covid-193.p.rapidapi.com/statistics?country={country}")
                .header("x-rapidapi-key", "4b98948290msh3ca5db10bafc5a4p103407jsnc08bdfa07302")
                .header("x-rapidapi-host", "covid-193.p.rapidapi.com")
                .routeParam("country", country)
                .asJson();
        return response.getBody().getObject();
    }

    @Description("Service that converts the entered exchange rate to other currencies")
    public JSONObject currencyToAll(String currency) throws UnirestException {
        HttpResponse<JsonNode> response = Unirest.get("https://currency23.p.rapidapi.com/currencyToAll?base={currency}&int=1")
                .header("x-rapidapi-key", "4b98948290msh3ca5db10bafc5a4p103407jsnc08bdfa07302")
                .header("x-rapidapi-host", "currency23.p.rapidapi.com")
                .routeParam("currency", currency)
                .asJson();
        return response.getBody().getObject();
    }

    @Description("List available live matches at request time")
    public JSONObject liveMatches(String sport) throws UnirestException { // Args soccer|cricket|basketball|tennis|hockey
        HttpResponse<JsonNode> response = Unirest.get("https://livescore6.p.rapidapi.com/matches/v2/list-live?Category={sport}")
                .header("x-rapidapi-key", "4b98948290msh3ca5db10bafc5a4p103407jsnc08bdfa07302")
                .header("x-rapidapi-host", "livescore6.p.rapidapi.com")
                .routeParam("sport", sport)
                .asJson();
        return response.getBody().getObject();
    }

    @Description("Search tracks")
    public JSONObject deezer(String toSearch) throws UnirestException {
        HttpResponse<JsonNode> response = Unirest.get("https://deezerdevs-deezer.p.rapidapi.com/search?q={toSearch}")
                .header("x-rapidapi-key", "4b98948290msh3ca5db10bafc5a4p103407jsnc08bdfa07302")
                .header("x-rapidapi-host", "deezerdevs-deezer.p.rapidapi.com")
                .routeParam("toSearch", toSearch)
                .asJson();
        return response.getBody().getObject();
    }

    @Description("Get love percentage beetween 2 names")
    public JSONObject loveCalculator(String name_1, String name_2) throws UnirestException {
        HttpResponse<JsonNode> response = Unirest.get("https://love-calculator.p.rapidapi.com/getPercentage?fname={name_1}&sname={name_2}")
                .header("x-rapidapi-key", "4b98948290msh3ca5db10bafc5a4p103407jsnc08bdfa07302")
                .header("x-rapidapi-host", "love-calculator.p.rapidapi.com")
                .routeParam("name_1", name_1)
                .routeParam("name_2", name_2)
                .asJson();
        return response.getBody().getObject();
    }

    @Description("Get a joke")
    public JSONObject joke(String category) throws UnirestException { // "Any", "Miscellaneous", "Programming", "Dark", "Pun", "Spooky", "Christmas"
        HttpResponse<JsonNode> response = Unirest.get("https://jokeapi-v2.p.rapidapi.com/joke/{category}?contains=C%2523&format=json&blacklistFlags=nsfw%2Cracist&idRange=0-150&type=single%2Ctwopart")
                .header("x-rapidapi-key", "4b98948290msh3ca5db10bafc5a4p103407jsnc08bdfa07302")
                .header("x-rapidapi-host", "jokeapi-v2.p.rapidapi.com")
                .routeParam("category", category)
                .asJson();
        return response.getBody().getObject();
    }
}
