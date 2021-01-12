package com.dashboard.controller.OAuth;

import com.mashape.unirest.http.HttpResponse;
import com.mashape.unirest.http.JsonNode;
import com.mashape.unirest.http.Unirest;
import com.mashape.unirest.http.exceptions.UnirestException;
import org.json.JSONException;
import org.json.JSONObject;
import org.springframework.context.annotation.Description;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class YammerController extends AbstractController {

    @GetMapping (path = "${oauth.yammer.callback}", produces = "application/json")
    public ResponseEntity<String> callback(@RequestParam String code,
                                           @RequestParam(required = false, defaultValue = "") String userToken) throws UnirestException {
        HttpResponse<JsonNode> response = Unirest.get("https://www.yammer.com/oauth2/access_token.json?client_id={client_id}&client_secret={client_secret}&code={code}")
                .routeParam("client_id", config.get("oauth.yammer.client_id"))
                .routeParam("client_secret", config.get("oauth.yammer.client_secret"))
                .routeParam("code", code)
                .asJson();
        String email = response.getBody().getObject().getJSONObject("user").get("email").toString();
        String tokenAccess = response.getBody().getObject().getJSONObject("access_token").get("token").toString();

        userToken = setServiceAndUser("yammer", email, userToken, tokenAccess, null);
        return new ResponseEntity<String>(new JSONObject().put("token", userToken).toString(), HttpStatus.UNPROCESSABLE_ENTITY);
    }
}
