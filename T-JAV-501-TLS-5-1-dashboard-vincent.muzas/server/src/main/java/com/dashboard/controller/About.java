package com.dashboard.controller;

import com.dashboard.service.service.GoogleService;
import com.dashboard.service.service.TwitterService;
import com.dashboard.service.service.YammerService;
import com.dashboard.service.service.RapidApiService;
import org.json.JSONArray;
import org.json.JSONObject;
import org.springframework.context.annotation.Description;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

import java.lang.reflect.Method;
import java.lang.reflect.Parameter;
import java.net.InetAddress;
import java.net.UnknownHostException;
import java.util.ArrayList;

@RestController
public class About {

    private ArrayList<Class> servicesList = new ArrayList<Class>() {
        {
            add(RapidApiService.class);
            add(YammerService.class);
            add(TwitterService.class);
            add(GoogleService.class);
        }
    };

    @GetMapping(path = "/about.json", produces = "application/json")
    public ResponseEntity<String> about() throws UnknownHostException {
        JSONObject json = new JSONObject();
        JSONObject server = new JSONObject();
        JSONArray services = new JSONArray();

        json.put("client", new JSONObject().put("host", InetAddress.getLocalHost().getHostAddress()));
        for (Class s : servicesList)
            services.put(inspectService(s));
        server.put("current_time", System.currentTimeMillis());
        server.put("services", services);
        json.put("server", server);
        return new ResponseEntity<String>(json.toString(), HttpStatus.OK);
    }

    private JSONObject inspectService(Class _class)
    {
        JSONObject service = new JSONObject();
        JSONArray widgets = new JSONArray();
        Method[] methods = _class.getDeclaredMethods();

        service.put("name", _class.getSimpleName().replace("Service", ""));
        for (Method method : methods)
            widgets.put( inspectWidget(method) );
        service.put("widgets", widgets);
        return service;
    }

    private JSONObject inspectWidget(Method method)
    {
        JSONObject widget = new JSONObject();
        JSONArray params = new JSONArray();

        widget.put("name", method.getName());
        widget.put("description", method.getAnnotation(Description.class).value());
        for (Parameter parameter: method.getParameters()) {
            params.put(
                    new JSONObject()
                            .put("name", parameter.getName())
                            .put("type", parameter.getType().getSimpleName())
            );
        }
        widget.put("params", params);
        return widget;
    }
}