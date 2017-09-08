package com.aillieo.cocos2d_x_sdk_integration;

import org.cocos2dx.cpp.AppActivity;
import android.os.Handler;
import android.os.Message;


public class ScenePrompt {

    static private Handler m_handler;

    public static void setHandler(Handler handler)
    {
        m_handler = handler;
    };


    public static void showPrompt() {

        Message msg = new Message();
        msg.what=AppActivity.SHOW_DIALOG;
        m_handler.sendMessage(msg);
    }

}