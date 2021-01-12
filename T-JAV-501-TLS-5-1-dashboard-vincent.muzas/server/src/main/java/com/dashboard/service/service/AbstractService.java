package com.dashboard.service.service;

import com.dashboard.config.Config;
import com.dashboard.model.Service;
import com.dashboard.model.User;
import lombok.Data;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.Optional;

@Data
public abstract class AbstractService {

    protected Service service = null;
    protected User user = null;

    protected AbstractService(Optional<Service> service, Optional<User> user)
    {
        if (service.isPresent())
            this.service = service.get();
        if (user.isPresent())
            this.user = user.get();
    }
}