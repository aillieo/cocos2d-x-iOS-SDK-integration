package com.aillieo.cocos2d_x_sdk_integration;

/**
 * Created by aillieo on 2017/9/30.
 */


import org.cocos2dx.cpp.AppActivity;
import android.os.Handler;
import android.os.Message;

public class SceneGetImage {

    static private Handler m_handler;

    public static void setHandler(Handler handler)
    {
        m_handler = handler;
    };

    //打开相册
    static public void selectFromPhotos()
    {
        Message msg = new Message();
        msg.what=AppActivity.SELECT_FROM_PHOTOS;
        m_handler.sendMessage(msg);
    }

    //打开相机
    static public void takeWithCamera()
    {
        Message msg = new Message();
        msg.what=AppActivity.TAKE_WITH_CAMERA;
        m_handler.sendMessage(msg);
    }





}
