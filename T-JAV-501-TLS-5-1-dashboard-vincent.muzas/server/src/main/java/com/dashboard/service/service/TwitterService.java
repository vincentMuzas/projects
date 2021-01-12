package com.dashboard.service.service;

import com.dashboard.config.Config;
import com.dashboard.model.Service;
import com.dashboard.model.User;
import com.dashboard.tool.OauthHeaderGenerator;
import org.json.JSONObject;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.context.annotation.Description;
import org.springframework.http.HttpEntity;
import org.springframework.http.HttpHeaders;
import org.springframework.http.HttpMethod;
import org.springframework.http.ResponseEntity;
import org.springframework.web.client.RestTemplate;

import java.net.URISyntaxException;
import java.util.HashMap;
import java.util.Map;
import java.util.Optional;

@org.springframework.stereotype.Service
public class TwitterService extends AbstractService {

    final String client_id = "Rni8w9FmFESDEOMJJnlAockXD";
    final String client_secret = "msaFMXfdxRdcYIunqAgHK7AZ5CAYOQpqvbA65xnmqyloyZn8bb";

    public TwitterService(Optional<Service> service, Optional<User> user) {
        super(service, user);
    }

    @Description("Get account infos.")
    public JSONObject getAccountInfos() throws URISyntaxException {
        Map<String, String> requestParams = new HashMap<String, String>() {
            {
                put("include_email", "true");
            }
        };

        OauthHeaderGenerator generator = new OauthHeaderGenerator(client_id,
                client_secret, service.getToken(), service.getRefreshToken());
        RestTemplate rt = new RestTemplate();
        String header = generator.generate("GET", "https://api.twitter.com/1.1/account/verify_credentials.json",
                requestParams);
        HttpHeaders headers = new HttpHeaders();

        headers.add("Authorization", header);
        HttpEntity<String> httpEntity = new HttpEntity<String>("body", headers);
        ResponseEntity<String> resp = rt.exchange("https://api.twitter.com/1.1/account/verify_credentials.json?include_email=true",
                HttpMethod.GET, httpEntity, String.class);
        return new JSONObject(resp.getBody());
    }

    @Description("Update language settings. | 'lang' must be specified by the appropriate two letter ISO 639-1")
    public JSONObject updateLanguage(String lang)
    {
        Map<String, String> requestParams = new HashMap<String, String>() {
            {
                put("lang", lang);
            }
        };
        OauthHeaderGenerator generator = new OauthHeaderGenerator(client_id,
                client_secret, service.getToken(), service.getRefreshToken());
        RestTemplate rt = new RestTemplate();
        String header = generator.generate("POST", "https://api.twitter.com/1.1/account/settings.json",
                requestParams);
        HttpHeaders headers = new HttpHeaders();

        headers.add("Authorization", header);
        HttpEntity<String> httpEntity = new HttpEntity<String>("body", headers);
        ResponseEntity<String> resp = rt.exchange("https://api.twitter.com/1.1/account/settings.json?lang=" + lang,
                HttpMethod.POST, httpEntity, String.class);
        return new JSONObject(resp.getBody());
    }
}
