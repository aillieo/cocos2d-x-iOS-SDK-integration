/****************************************************************************
Copyright (c) 2015-2017 Chukong Technologies Inc.
 
http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
package org.cocos2dx.cpp;

import org.cocos2dx.lib.Cocos2dxActivity;

import android.app.AlertDialog;
import android.os.Bundle;
import android.os.Handler;
import android.os.Message;

import com.aillieo.cocos2d_x_sdk_integration.SceneAlert;


public class AppActivity extends Cocos2dxActivity {

    public static final int SHOW_ALERT = 0x0001;
    public static final int SEND_TEXT = 0x0002;
    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        SceneAlert.setHandler(m_Handler);
    }

    private Handler m_Handler = new Handler()
    {
        public void handleMessage(Message msg) {

        switch (msg.what)
        {
            case SHOW_ALERT: {
                AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(AppActivity.this);
                AlertDialog alertDialog = alertDialogBuilder.create();
                alertDialog.setMessage("message");
                alertDialog.show();
            }
                break;

            case SEND_TEXT: {
                AlertDialog.Builder alertDialogBuilder = new AlertDialog.Builder(AppActivity.this);
                AlertDialog alertDialog = alertDialogBuilder.create();
                if (msg.obj != null)
                    alertDialog.setMessage((String) msg.obj);
                alertDialog.show();
            }
                break;

        }
    }
    };
}
