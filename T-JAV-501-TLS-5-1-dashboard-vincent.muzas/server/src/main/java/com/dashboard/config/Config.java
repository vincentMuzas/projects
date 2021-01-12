package com.dashboard.config;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.context.annotation.Configuration;
import org.springframework.core.env.Environment;
import org.springframework.stereotype.Service;

@Configuration
@Service
public class Config {

    @Autowired
    private Environment env;

    public String get(String propertyName) {
        return env.getProperty(propertyName);
    }
}
