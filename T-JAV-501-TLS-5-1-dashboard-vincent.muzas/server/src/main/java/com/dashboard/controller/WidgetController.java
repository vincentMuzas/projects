package com.dashboard.controller;

import com.dashboard.config.Config;
import com.dashboard.model.User;
import com.dashboard.model.Widget;
import com.dashboard.service.ServiceService;
import com.dashboard.service.UserService;
import com.dashboard.service.WidgetService;
import org.json.JSONArray;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import java.lang.reflect.Constructor;
import java.lang.reflect.Method;
import java.util.ArrayList;
import java.util.Optional;

import static com.dashboard.tool.Usefull.ucfirst;

@RestController
public class WidgetController {

    @Autowired
    UserService userService;

    @Autowired
    ServiceService serviceService;

    @Autowired
    WidgetService widgetService;

    @GetMapping(path = "/widgetList", produces = "application/json")
    public ResponseEntity<String> getWidgetList(@RequestParam String token) {
        Optional<User> user;
        JSONArray resp = new JSONArray();

        if (userService.isLogged(token) == false)
            return new ResponseEntity<String>("{}", HttpStatus.FORBIDDEN);
        user = userService.getUserByToken(token);
        for (Widget widget : widgetService.getWidgetsByUserId(user.get().getId())) {
            resp.put(new JSONObject()
                .put("id", widget.getId())
                .put("service_name", widget.getServiceName())
                .put("widget_name", widget.getName())
                .put("params", new JSONArray(widget.getParams()))
                .put("created_at", widget.getCreatedAt().getTime())
            );
        }
        return new ResponseEntity<String>(resp.toString(), HttpStatus.OK);
    }

    @PostMapping(path = "/widget", produces = "application/json")
    public ResponseEntity<String> postWidget(@RequestParam String token, @RequestParam String serviceName,
                                            @RequestParam String widgetName, @RequestParam JSONArray params) {
        Widget widget = new Widget();
        Optional<User> user = userService.getUserByToken(token);
        JSONObject resp;

        if (userService.isLogged(token) == false)
            return new ResponseEntity<String>("{}", HttpStatus.FORBIDDEN);
        widget.setName(widgetName);
        widget.setServiceName(serviceName);
        widget.setParams(params.toString());
        widget.setUserId(user.get().getId());
        if ((resp = executeWidgetService(widget, user)) != null) {
            widgetService.saveWidget(widget);
            return new ResponseEntity<String>(resp.toString(), HttpStatus.OK);
        }
        return new ResponseEntity<String>("{}", HttpStatus.NOT_FOUND);
    }

    @PutMapping(path = "/widget", produces = "application/json")
    public ResponseEntity<String> postWidget(@RequestParam String token, @RequestParam Long widgetId,
                                             @RequestParam JSONArray params) {
        Optional<Widget> widget = widgetService.getWidget(widgetId);
        Optional<User> user = userService.getUserByToken(token);
        JSONObject resp;

        if (userService.isLogged(token) == false)
            return new ResponseEntity<String>("{}", HttpStatus.FORBIDDEN);
        if (widget.isPresent() && user.isPresent() && user.get().getId() == widget.get().getUserId()) {
            widget.get().setParams(params.toString());
            if ((resp = executeWidgetService(widget.get(), user)) != null) {
                widgetService.saveWidget(widget.get());
                return new ResponseEntity<String>(resp.toString(), HttpStatus.OK);
            }
        }
        return new ResponseEntity<String>("{}", HttpStatus.NOT_FOUND);
    }

    @DeleteMapping(path = "/widget", produces = "application/json")
    public ResponseEntity<String> deleteWidget(@RequestParam String token, @RequestParam Long widgetId) {
        Optional<Widget> widget = widgetService.getWidget(widgetId);
        Optional<User> user = user = userService.getUserByToken(token);

        if (userService.isLogged(token) == false)
            return new ResponseEntity<String>("{}", HttpStatus.FORBIDDEN);
        if (widget.isPresent() && user.isPresent() && user.get().getId() == widget.get().getUserId()) {
            widgetService.deleteWidget(widgetId);
            return new ResponseEntity<String>("{}", HttpStatus.OK);
        }
        return new ResponseEntity<String>("{}", HttpStatus.NOT_FOUND);
    }

    @GetMapping(path = "/widget", produces = "application/json")
    public ResponseEntity<String> getWidget(@RequestParam String token, @RequestParam Long widgetId) {
        Optional<Widget> widget = widgetService.getWidget(widgetId);
        Optional<User> user = userService.getUserByToken(token);
        JSONObject resp;

        if (userService.isLogged(token) == false)
            return new ResponseEntity<String>("{}", HttpStatus.FORBIDDEN);
        if (widget.isPresent() && user.isPresent() && user.get().getId() == widget.get().getUserId()) {
            if ((resp = executeWidgetService(widget.get(), user)) != null)
                return new ResponseEntity<String>(resp.toString(), HttpStatus.OK);
        }
        return new ResponseEntity<String>("{}", HttpStatus.NOT_FOUND);
    }

    private JSONObject executeWidgetService(Widget widget, Optional<User> user) {
        try {
            ArrayList<Object> ctor_params = new ArrayList<>() {
                {
                    add(serviceService.getServiceByNameAndUserId(widget.getServiceName(), user.get().getId()));
                    add(user);
                }
            };
            JSONArray params = new JSONArray(widget.getParams());
            Class<?> _class = Class.forName("com.dashboard.service.service." + ucfirst(widget.getServiceName()) + "Service");
            Constructor<?> ctor = _class.getConstructor(createArgumentTypes(ctor_params.toArray()));
            Object inst = ctor.newInstance(ctor_params.toArray());
            Method method = inst.getClass().getMethod(widget.getName(), createArgumentTypes(params.toList().toArray()));
            return (JSONObject) method.invoke(inst, params.toList().toArray());
        }
        catch (Exception e) {
//            e.printStackTrace();
            return null;
        }
    }

    private Class<?>[] createArgumentTypes(Object[] arguments) {
        Class[] types = new Class[arguments.length];

        for (int i = 0; i < arguments.length; i++) {
//            System.out.println( arguments[i] + " -----> [" + arguments[i].getClass() + "]" );
            types[i] = arguments[i].getClass();
        }
        return types;
    }
}
