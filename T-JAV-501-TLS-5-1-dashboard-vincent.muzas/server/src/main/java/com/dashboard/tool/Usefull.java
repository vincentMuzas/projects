package com.dashboard.tool;

import java.util.Random;

public class Usefull {

    static public String ucfirst(String str)
    {
        return str.substring(0, 1).toUpperCase() + str.substring(1);
    }

    static public String createRandomString(Integer size)
    {
        String str = new String();
        Random r = new Random();

        for (Integer n = 0; n < size; n += 1)
            str += r.nextInt(9);
        return str;
    }
}
