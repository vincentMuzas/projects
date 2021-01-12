package com.dashboard.service;

import com.dashboard.config.Config;
import com.dashboard.model.User;
import com.dashboard.tool.Kurl;
import com.dashboard.tool.Usefull;
import com.mashape.unirest.http.HttpResponse;
import com.mashape.unirest.http.JsonNode;
import com.mashape.unirest.http.Unirest;
import com.mashape.unirest.http.exceptions.UnirestException;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import java.util.Optional;

@Service
public class AuthenticationService {

    @Autowired
    private UserService userService;

    @Autowired
    private Config config;

    public boolean register(String email, String password) {
        try {
            Unirest u = Kurl.getUnirest();

            HttpResponse<JsonNode> response = u.post(config.get("app_url") + "register")
                    .header("accept", "application/json")
                    .field("email", email)
                    .field("password", password)
                    .asJson();
            if (response.getStatus() == 200)
                return true;
            else
                return false;
        }
        catch (UnirestException e) {
            return false;
        }
    }

    public String login(String email, String password) {
        try {
            Unirest u = Kurl.getUnirest();

            HttpResponse<JsonNode> response = u.post(config.get("app_url") + "login")
                    .header("accept", "application/json")
                    .field("email", email)
                    .field("password", password)
                    .asJson();
            if (response.getStatus() == 200)
                return response.getBody().getObject().get("token").toString();
            else
                return null;
        }
        catch (UnirestException e) {
            return null;
        }
    }

    public String oauth(String email) {
        Optional<User> user;
        String password = Usefull.createRandomString(8);
        String token;

        if (register(email, password) == true)
            return login(email, password);
        else if ((user = userService.getUserByEmail(email)).isPresent()) {
            token = user.get().createToken();
            userService.saveUser(user.get());
            return token;
        }
        else
            return null;
    }
}
