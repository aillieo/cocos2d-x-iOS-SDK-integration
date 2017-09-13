package com.aillieo.cocos2d_x_sdk_integration;

/**
 * Created by aillieo on 2017/9/11.
 */

import org.cocos2dx.cpp.AppActivity;
import android.os.Handler;
import android.os.Message;

public class SceneSendText {

    static private Handler m_handler;

    public static void setHandler(Handler handler)
    {
        m_handler = handler;
    };


    public static void sendText(final String text) {

        System.out.println(text);

        Message msg = new Message();
        msg.what=AppActivity.SEND_TEXT;
        msg.obj = text;
        m_handler.sendMessage(msg);
    }

}
