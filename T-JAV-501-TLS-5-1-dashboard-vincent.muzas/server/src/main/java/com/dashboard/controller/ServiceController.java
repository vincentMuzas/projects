package com.dashboard.controller;

import com.dashboard.model.Service;
import com.dashboard.model.User;
import com.dashboard.model.Widget;
import com.dashboard.service.ServiceService;
import com.dashboard.service.UserService;
import org.json.JSONArray;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import java.util.Optional;

@RestController
public class ServiceController {

    @Autowired
    UserService userService;

    @Autowired
    ServiceService service;

    @GetMapping(path = "/services", produces = "application/json")
    public ResponseEntity<String> getServices(@RequestParam String token) {
        Optional<User> user = userService.getUserByToken(token);
        JSONArray resp = new JSONArray();

        if (userService.isLogged(token) == false)
            return new ResponseEntity<String>("Forbidden", HttpStatus.FORBIDDEN);
        for (Service s : service.getServicesByUserId(user.get().getId())) {
            resp.put(new JSONObject()
                .put("id", s.getId())
                .put("service_name", s.getName())
                .put("token", s.getToken())
                .put("refresh_token", s.getRefreshToken())
                .put("created_at", s.getCreatedAt().getTime())
            );
        }
        return new ResponseEntity<String>(resp.toString(), HttpStatus.OK);
    }
}