package com.dashboard.service.service;

import com.dashboard.model.Service;
import com.dashboard.model.User;

import java.util.Optional;

@org.springframework.stereotype.Service
public class GoogleService extends AbstractService {

    public GoogleService(Optional<Service> service, Optional<User> user) {
        super(service, user);
    }
}