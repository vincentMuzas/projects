package com.dashboard.controller.OAuth;

import com.dashboard.model.Service;
import com.dashboard.service.service.TwitterService;
import com.dashboard.tool.Kurl;
import com.dashboard.tool.OauthHeaderGenerator;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.*;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

import javax.servlet.ServletException;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.net.URISyntaxException;
import java.util.*;

@RestController
public class TwitterController extends AbstractController {

    @Autowired
    TwitterService twitterService;

    @GetMapping(path = "${oauth.twitter.callback_1}")
    public void callback(HttpServletResponse response, HttpServletRequest request,
                         @RequestParam(defaultValue = "", required = false) String userToken) throws IOException, ServletException, URISyntaxException {
        OauthHeaderGenerator generator = new OauthHeaderGenerator(config.get("oauth.twitter.client_id"),
                config.get("oauth.twitter.client_secret"), "", "");
        Map<String, String> headerParams = new HashMap<>();
        RestTemplate rt = new RestTemplate();
        String header = generator.generate("GET", "https://api.twitter.com/oauth/request_token", headerParams);
        HttpHeaders headers = new HttpHeaders();
        ArrayList<String> respParams;

        headers.add("Authorization", header);
        HttpEntity<String> httpEntity = new HttpEntity<String>("body", headers);
        ResponseEntity<String> resp = rt.exchange("https://api.twitter.com/oauth/request_token",
                HttpMethod.GET, httpEntity, String.class);
        respParams = Kurl.parseUrl("?" + resp.getBody());
        request.getSession().setAttribute("oauth_token_secret", respParams.get(1));
        if (userToken.isEmpty() == false)
            request.getSession().setAttribute("userToken", userToken);
        else
            request.getSession().setAttribute("userToken", "");
        response.sendRedirect("https://api.twitter.com/oauth/authenticate?oauth_token=" + respParams.get(0));
    }

    @GetMapping(path = "${oauth.twitter.callback}", produces = "application/json")
    public ResponseEntity<String> callback(HttpServletRequest request,
                                           @RequestParam String oauth_token, @RequestParam String oauth_verifier) throws URISyntaxException {
        OauthHeaderGenerator generator = new OauthHeaderGenerator(config.get("oauth.twitter.client_id"),
                config.get("oauth.twitter.client_secret"), oauth_token, request.getSession().getAttribute("oauth_token_secret").toString());
        Map<String, String> params = new HashMap<>();
        RestTemplate rt = new RestTemplate();
        String header = generator.generate("GET", "https://api.twitter.com/oauth/access_token", params);
        HttpHeaders headers = new HttpHeaders();
        ArrayList<String> respParams;

        headers.add("Authorization", header);
        HttpEntity<String> httpEntity = new HttpEntity<String>("body", headers);
        ResponseEntity<String> resp = rt.exchange("https://api.twitter.com/oauth/access_token?oauth_verifier=" + oauth_verifier,
                HttpMethod.GET, httpEntity, String.class);
        respParams = Kurl.parseUrl("?" + resp.getBody());
        Service s = new Service();
        s.setToken(respParams.get(0));
        s.setRefreshToken(respParams.get(1));
        twitterService.setService(s);
        String email = twitterService.getAccountInfos().get("email").toString();
        String userToken = request.getSession().getAttribute("userToken").toString();
        userToken = setServiceAndUser("twitter", email, userToken, respParams.get(0), respParams.get(1));
        return new ResponseEntity<String>(new JSONObject().put("token", userToken).toString(), HttpStatus.OK);
    }
}
