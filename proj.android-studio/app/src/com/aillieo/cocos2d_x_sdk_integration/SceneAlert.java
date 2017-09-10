package com.aillieo.cocos2d_x_sdk_integration;

import org.cocos2dx.cpp.AppActivity;
import android.os.Handler;
import android.os.Message;


public class SceneAlert {

    static private Handler m_handler;

    public static void setHandler(Handler handler)
    {
        m_handler = handler;
    };


    public static void showAlert() {

        Message msg = new Message();
        msg.what=AppActivity.SHOW_ALERT;
        m_handler.sendMessage(msg);
    }

}