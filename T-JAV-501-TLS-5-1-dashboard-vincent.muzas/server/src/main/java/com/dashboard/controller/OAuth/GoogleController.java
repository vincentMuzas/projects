package com.dashboard.controller.OAuth;

import com.mashape.unirest.http.HttpResponse;
import com.mashape.unirest.http.JsonNode;
import com.mashape.unirest.http.Unirest;
import com.mashape.unirest.http.exceptions.UnirestException;
import org.json.JSONException;
import org.json.JSONObject;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

import java.io.UnsupportedEncodingException;
import java.net.URLDecoder;
import java.nio.charset.StandardCharsets;

@RestController
public class GoogleController extends AbstractController {

    @GetMapping(path = "${oauth.google.callback}", produces = "application/json")
    public ResponseEntity<String> callback(@RequestParam String code,
                                           @RequestParam(defaultValue = "{}", required = false) String state) throws UnirestException {
        String userToken;
        HttpResponse<JsonNode> response_1 = Unirest.post("https://oauth2.googleapis.com/token")
                .field("code", code)
                .field("client_id", config.get("oauth.google.client_id"))
                .field("client_secret", config.get("oauth.google.client_secret"))
                .field("grant_type", "authorization_code")
                .field("scopes", config.get("oauth.google.scopes"))
                .field("redirect_uri", config.get("app_url_2") + config.get("oauth.google.callback"))
                .asJson();

        try {
             userToken = new JSONObject(URLDecoder.decode(state, StandardCharsets.UTF_8.toString())).get("userToken").toString();
        }
        catch (JSONException | UnsupportedEncodingException e) {
            userToken = null;
        }

        HttpResponse<JsonNode> response_2 = Unirest.get("https://www.googleapis.com/oauth2/v2/userinfo?access_token={access_token}")
                .routeParam("access_token", response_1.getBody().getObject().get("access_token").toString())
                .asJson();

        userToken = setServiceAndUser("google", response_2.getBody().getObject().get("email").toString(),
                userToken,
                response_1.getBody().getObject().get("access_token").toString(),
                response_1.getBody().getObject().get("refresh_token").toString());
        return new ResponseEntity<String>(new JSONObject().put("token", userToken).toString(), HttpStatus.UNPROCESSABLE_ENTITY);
    }
}
