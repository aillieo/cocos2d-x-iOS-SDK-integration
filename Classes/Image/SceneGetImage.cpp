//
//  SceneGetImage.cpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/20.
//
//

#include "SceneGetImage.hpp"

USING_NS_CC;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#define CLASS_NAME "com/aillieo/cocos2d_x_sdk_integration/SceneGetImage"
#endif

SceneBase* SceneGetImage::createScene()
{
    return SceneGetImage::create();
}

bool SceneGetImage::init()
{
    if ( !SceneBase::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto labelItemPhoto = MenuItemLabel::create(Label::createWithTTF("SELECT FROM PHOTOS", "fonts/arial.ttf", 14),
                                           CC_CALLBACK_1(SceneGetImage::menuCallbackPhoto, this));
    
    auto labelItemCamera = MenuItemLabel::create(Label::createWithTTF("TAKE WITH CAMERA", "fonts/arial.ttf", 14),
                                           CC_CALLBACK_1(SceneGetImage::menuCallbackCamera, this));
    
    
    auto menu = Menu::create(labelItemPhoto, labelItemCamera, NULL);
    menu->setPosition(origin + visibleSize/2);
    menu->alignItemsVertically();
    this->addChild(menu, 1);
    
    
    EventListenerCustom* elc = EventListenerCustom::create("ImagePickEnd", CC_CALLBACK_1(SceneGetImage::onImagePickEnd,this));
    _eventDispatcher->addEventListenerWithSceneGraphPriority(elc, this);
    

    m_imageRoot = Node::create();
    addChild(m_imageRoot);
    m_imageRoot->setPosition(origin + visibleSize/2);
    
    return true;
}

void SceneGetImage::menuCallbackPhoto(cocos2d::Ref* pSender)
{
    selectFromPhotos();
}

void SceneGetImage::menuCallbackCamera(cocos2d::Ref* pSender)
{
    takeWithCamera();
}

void SceneGetImage::onImagePickEnd(EventCustom* event)
{
    m_imageRoot->removeAllChildren();
    std::string* s =  static_cast<std::string*>(event->getUserData());
    log("%s",(*s).c_str());
    
    Sprite* sp = Sprite::create(*s);
    m_imageRoot->addChild(sp);
    sp->runAction(RepeatForever::create(RotateBy::create(1.0, 90.0)));
    
}


