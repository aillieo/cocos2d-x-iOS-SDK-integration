//
//  SceneAlert.cpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/8/18.
//
//

#include "SceneAlert.hpp"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#define CLASS_NAME "com/aillieo/cocos2d_x_sdk_integration/SceneAlert"
#endif

USING_NS_CC;

SceneBase* SceneAlert::createScene()
{
    return SceneAlert::create();
}

// on "init" you need to initialize your instance
bool SceneAlert::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !SceneBase::init() )
    {
        return false;
    }
    
    setTitle("SceneAlert");
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto labelItem = MenuItemLabel::create(
                                           Label::createWithTTF("CLICK ME", "fonts/arial.ttf", 24),
                                           CC_CALLBACK_1(SceneAlert::menuCallback, this));
    
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(labelItem, NULL);
    menu->setPosition(origin + visibleSize/2);
    this->addChild(menu, 1);
    
    
    return true;
}


void SceneAlert::menuCallback(Ref* pSender)
{
    
    showAlert();
    
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
void SceneAlert::showAlert()
{
    JniMethodInfo t;
    cocos2d::log("will try call method");
    if(JniHelper::getStaticMethodInfo(t, CLASS_NAME, "showAlert", "()V"))
    {
        cocos2d::log("has this static method");
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
    }
}
#endif
