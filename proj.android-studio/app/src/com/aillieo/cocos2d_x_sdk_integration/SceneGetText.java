package com.aillieo.cocos2d_x_sdk_integration;

/**
 * Created by aillieo on 2017/9/11.
 */

import org.cocos2dx.cpp.AppActivity;

public class SceneGetText {

    public static String getText(String str) {

        StringBuilder sb = new StringBuilder(str);
        sb.append(" from Android");
        return sb.toString();
    }

}