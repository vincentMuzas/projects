package com.dashboard.controller;

import com.dashboard.config.Config;
import com.dashboard.model.Service;
import com.dashboard.service.UserService;
import com.dashboard.service.service.TwitterService;
import com.mashape.unirest.http.exceptions.UnirestException;
import org.springframework.beans.factory.ObjectProvider;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.Optional;

@RestController
public class TestController {

    @Autowired
    private UserService userService;

    @Autowired
    private TwitterService twitterService;

    @Autowired
    private Config config;

    @GetMapping("/test")
    public void test() throws UnirestException {
//        Service s = new Service();
//        s.setToken("3014032251-9tHEckQZV3XKbdeILJgyBNui8joLC3IlObRqAqO");
//        s.setRefreshToken("lxieEDfjvjfCEz1VU7bfZWX7D9shc0RPopf6OVMJFZWyc");
//        twitterService.setService(s);
//        System.out.println( twitterService.changeLanguage("fr") );
    }
}
