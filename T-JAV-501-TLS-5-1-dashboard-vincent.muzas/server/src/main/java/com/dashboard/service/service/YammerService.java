package com.dashboard.service.service;

import com.dashboard.model.Service;
import com.dashboard.model.User;

import java.util.Optional;

@org.springframework.stereotype.Service
public class YammerService extends AbstractService {

    public YammerService(Optional<Service> service, Optional<User> user) {
        super(service, user);
    }
}
