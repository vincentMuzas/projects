package com.dashboard.controller.OAuth;

import com.dashboard.config.Config;
import com.dashboard.model.Service;
import com.dashboard.model.User;
import com.dashboard.service.AuthenticationService;
import com.dashboard.service.ServiceService;
import com.dashboard.service.UserService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RestController;

import java.util.Optional;

@RestController
public abstract class AbstractController {

    @Autowired
    protected AuthenticationService authService;

    @Autowired
    protected Config config;

    @Autowired
    protected UserService userService;

    @Autowired
    protected ServiceService serviceService;

    protected String setServiceAndUser(String serviceName, String email, String userToken, String access_token,
                                  String refresh_token)
    {
        Optional<Service> s;
        Service service;
        String token = null;
        User user;

        if (userToken == null || userToken.isEmpty())
            token = authService.oauth(email);
        else
            token = userToken;
        user = userService.getUserByToken(token).get();
        s = serviceService.getServiceByNameAndUserId(serviceName, user.getId());
        if (s == null || s.isPresent() == false)
            service = new Service();
        else
            service = s.get();
        service.setName(serviceName);
        service.setUserId(user.getId());
        service.setToken(access_token);
        service.setRefreshToken(refresh_token);
        serviceService.saveService(service);
        return token;
    }
}