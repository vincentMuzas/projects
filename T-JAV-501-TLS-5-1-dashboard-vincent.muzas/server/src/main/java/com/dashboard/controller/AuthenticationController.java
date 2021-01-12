package com.dashboard.controller;

import com.dashboard.model.User;
import com.dashboard.service.UserService;
import org.json.JSONArray;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.security.crypto.bcrypt.BCryptPasswordEncoder;
import org.springframework.validation.Errors;
import org.springframework.validation.FieldError;
import org.springframework.web.bind.annotation.*;

import javax.validation.Valid;
import java.sql.SQLIntegrityConstraintViolationException;
import java.util.Optional;

@RestController
public class AuthenticationController {

    @Autowired
    private UserService userService;

    @PostMapping(path = "/register", produces = "application/json")
    public ResponseEntity<String> register(@ModelAttribute String email, @ModelAttribute String password,
                                           @Valid User user, Errors errors) {
        if (errors.hasErrors()) {
            JSONArray errs = new JSONArray();
            for (FieldError e : errors.getFieldErrors())
                errs.put(new JSONObject().put(e.getField(), e.getDefaultMessage()));
            return new ResponseEntity<String>(errs.toString(), HttpStatus.UNPROCESSABLE_ENTITY);
        } else {
            user.setHashedPassword(user.getPassword());
            user.createToken(); // Useless but required, because token can't be null when creating an user
            userService.saveUser(user);
            return new ResponseEntity<String>("{}", HttpStatus.OK);
        }
    }

    @PostMapping(path = "/login", produces = "application/json")
    public ResponseEntity<String> login(@RequestParam String email, @RequestParam String password) {
        Optional<User> oUser = userService.getUserByEmail(email);
        User user;

        if (oUser.isPresent()) {
            user = oUser.get();
            if (new BCryptPasswordEncoder().matches(password, user.getPassword())) {
                JSONObject JsonResponse = new JSONObject().put("token", user.createToken());
                userService.saveUser(user);
                return new ResponseEntity<String>(JsonResponse.toString(), HttpStatus.OK);
            }
        }
        return new ResponseEntity<String>("{}", HttpStatus.UNAUTHORIZED);
    }
}
