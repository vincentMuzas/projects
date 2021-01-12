package com.dashboard.tool;

import com.mashape.unirest.http.HttpResponse;
import com.mashape.unirest.http.Unirest;
import org.apache.http.NameValuePair;
import org.apache.http.client.utils.URLEncodedUtils;
import org.apache.http.conn.ssl.SSLConnectionSocketFactory;
import org.apache.http.conn.ssl.TrustSelfSignedStrategy;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.ssl.SSLContexts;

import javax.net.ssl.SSLContext;
import java.net.URI;
import java.net.URISyntaxException;
import java.nio.charset.Charset;
import java.security.KeyManagementException;
import java.security.KeyStoreException;
import java.security.NoSuchAlgorithmException;
import java.util.ArrayList;

public class Kurl {

    static public String format(HttpResponse<String> response)
    {
        String resp = response.getBody();

        resp = resp.replace("test(", "");
        resp = resp.substring(0, resp.length() - 1);
        return resp;
    }

    static public Unirest getUnirest() {
        try {
            Unirest u = new Unirest();

            SSLContext sslcontext = SSLContexts.custom()
                    .loadTrustMaterial(null, new TrustSelfSignedStrategy())
                    .build();
            SSLConnectionSocketFactory sslsf = new SSLConnectionSocketFactory(sslcontext, SSLConnectionSocketFactory.ALLOW_ALL_HOSTNAME_VERIFIER);
            CloseableHttpClient httpclient = HttpClients.custom()
                    .setSSLSocketFactory(sslsf)
                    .build();
            u.setHttpClient(httpclient);
            return u;
        }
        catch (KeyStoreException |NoSuchAlgorithmException | KeyManagementException e) {
            return null;
        }
    }

    static public ArrayList<String> parseUrl(String url) throws URISyntaxException {
        ArrayList<String> params = new ArrayList<>();

        for (NameValuePair param : URLEncodedUtils.parse(new URI(url), Charset.forName("UTF-8")))
            params.add(param.getValue());
        return params;
    }
}
