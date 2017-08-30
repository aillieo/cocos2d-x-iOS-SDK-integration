//
//  ScenePrompt.cpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/8/18.
//
//

#include "ScenePrompt.hpp"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#define CLASS_NAME "com/aillieo/cocos2d_x_sdk_integration/ScenePrompt"
#endif

USING_NS_CC;

SceneBase* ScenePrompt::createScene()
{
    return ScenePrompt::create();
}

// on "init" you need to initialize your instance
bool ScenePrompt::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !SceneBase::init() )
    {
        return false;
    }
    
    setTitle("ScenePrompt");
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto labelItem = MenuItemLabel::create(
                                           Label::createWithTTF("CLICK ME", "fonts/arial.ttf", 24),
                                           CC_CALLBACK_1(ScenePrompt::menuCallback, this));
    
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(labelItem, NULL);
    menu->setPosition(origin + visibleSize/2);
    this->addChild(menu, 1);
    
    
    return true;
}


void ScenePrompt::menuCallback(Ref* pSender)
{
    
    showPrompt();
    
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
void ScenePrompt::showPrompt()
{
    JniMethodInfo t;
    cocos2d::log("will try call method");
    if(JniHelper::getStaticMethodInfo(t, CLASS_NAME, "showPrompt", "()V"))
    {
        cocos2d::log("has this static method");
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
    }
}
#endif
