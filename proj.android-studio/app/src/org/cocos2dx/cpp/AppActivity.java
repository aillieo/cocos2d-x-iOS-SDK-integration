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

///
import java.io.File;
import java.io.FileNotFoundException;
import android.app.Activity;
import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.net.Uri;
import android.os.Environment;
import android.os.Handler;
import android.provider.MediaStore;
import android.util.Log;
///


import com.aillieo.cocos2d_x_sdk_integration.SceneAlert;
import com.aillieo.cocos2d_x_sdk_integration.SceneGetImage;
import com.aillieo.cocos2d_x_sdk_integration.SceneSendText;


public class AppActivity extends Cocos2dxActivity {



    public static final int SHOW_ALERT = 0x0001;
    public static final int SEND_TEXT = 0x0002;
    public static final int SELECT_FROM_PHOTOS = 0x0003;
    public static final int TAKE_WITH_CAMERA = 0x0004;



    public static final int NONE = 0;
    public static final int PHOTOGRAPH = 1;
    public static final int PHOTO_ZOOM = 2;
    public static final int PHOTO_RESULT = 3;
    public static final String IMAGE_UNSPECIFIED = "image/*";



    private static String TAG = "ImagePicker";

    public static native void onImageSaved(String path);

    //拍摄照片保存路径
    private static String savePath = Environment.getExternalStorageDirectory() +"/ImagePicker";
    private static String photoName = "";
    private static Uri imgUri = null;



    protected void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        SceneAlert.setHandler(m_Handler);
        SceneSendText.setHandler(m_Handler);
        SceneGetImage.setHandler(m_Handler);
    }

    private Handler m_Handler = new Handler()
    {
        public void handleMessage(Message msg) {

            System.out.println("handleMessage()");

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

            case SELECT_FROM_PHOTOS:
            {
                Intent intent = new Intent(Intent.ACTION_PICK, null);
                intent.setDataAndType(MediaStore.Images.Media.EXTERNAL_CONTENT_URI, IMAGE_UNSPECIFIED);
                startActivityForResult(intent, PHOTO_ZOOM);
            }

            break;

            case TAKE_WITH_CAMERA:
            {

                File destDir = new File(savePath);
                if (!destDir.exists())
                {
                    destDir.mkdirs();
                }
                photoName = "temp.jpg";
                File file = new File(savePath + "/" + photoName);
                imgUri = Uri.fromFile(file);
                Intent intent = new Intent(MediaStore.ACTION_IMAGE_CAPTURE);
                intent.putExtra(MediaStore.EXTRA_OUTPUT, imgUri);
                startActivityForResult(intent, PHOTOGRAPH);

            }
                break;

        }
    }
    };



    public void onActivityResult(int requestCode,int resultCode,Intent data)
    {
        System.out.println("onActivityResult() : " + String.valueOf(requestCode) + " : " + String.valueOf(resultCode));

        if (requestCode == NONE)
            return;

        // 拍照 不能使用data，因为没有返回是空的
        if (requestCode == PHOTOGRAPH)
        {
            if (imgUri == null)
            {
                Log.e(TAG, "PHOTOGRAPH imgUri is null");
                return;
            }
            startPhotoZoom(imgUri);
        }

        if (requestCode == PHOTO_ZOOM)
        {
            // 读取相册缩放图片
            if (data==null )
            {
                Log.e(TAG, "data is null");
                return;
            }
            if (data.getData()==null)
            {
                Log.e(TAG, "data.getData() is null");
                return;
            }
            startPhotoZoom(data.getData());
        }

        // 处理结果
        if (requestCode == PHOTO_RESULT)
        {
            Log.d(TAG, "requestCode == PHOTO_RESULT : " + imgUri.getPath());
            Bitmap bitmap = decodeUriAsBitmap(imgUri);
            if (bitmap == null)
            {
                Log.e(TAG, "bitmap is null");
            }
            Log.d(TAG, "图片已经保存，通知c++层");
            System.out.println("图片已经保存，通知c++层");
            onImageSaved(savePath + "/" + photoName);
        }
    }

    public void startPhotoZoom(Uri uri)
    {
        Log.d(TAG, "startPhotoZoom : " + uri.getPath());
        photoName = System.currentTimeMillis() + ".jpg";
        File file = new File(savePath,photoName);
        imgUri = Uri.fromFile(file);
        Log.d(TAG, "startPhotoZoom : " + imgUri.getPath());
        Intent intent = new Intent("com.android.camera.action.CROP");
        intent.setDataAndType(uri, IMAGE_UNSPECIFIED);
        intent.putExtra("crop", "true");
        intent.putExtra("aspectX", 1);
        intent.putExtra("aspectY", 1);
        intent.putExtra("outputX", 600);
        intent.putExtra("outputY", 600);
        intent.putExtra("return-data", false);
        intent.putExtra(MediaStore.EXTRA_OUTPUT, imgUri);
        startActivityForResult(intent, PHOTO_RESULT);
    }

    private Bitmap decodeUriAsBitmap(Uri uri)
    {
        Log.d(TAG, "decodeUriAsBitmap");
        System.out.println("decodeUriAsBitmap");
        Bitmap bitmap = null;
        try {
            System.out.println("decodeUriAsBitmap in try 1");
            bitmap = BitmapFactory.decodeStream(this.getContentResolver().openInputStream(uri));
            System.out.println("decodeUriAsBitmap in try 2");
        } catch (FileNotFoundException e) {
            // TODO: handle exception
            System.out.println("decodeUriAsBitmap in catch");
            e.printStackTrace();
            return null;
        }

        return bitmap;
    }

}
