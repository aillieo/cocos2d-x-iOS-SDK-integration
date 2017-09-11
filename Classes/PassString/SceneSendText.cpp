//
//  SceneSendText.cpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/11.
//
//

#include "SceneSendText.hpp"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#define CLASS_NAME "com/aillieo/cocos2d_x_sdk_integration/SceneSendText"
#endif

USING_NS_CC;

SceneBase* SceneSendText::createScene()
{
    return SceneSendText::create();
}

// on "init" you need to initialize your instance
bool SceneSendText::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !SceneBase::init() )
    {
        return false;
    }
    
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    
    auto labelItem = MenuItemLabel::create(
                                           Label::createWithTTF("CLICK ME", "fonts/arial.ttf", 24),
                                           CC_CALLBACK_1(SceneSendText::menuCallback, this));
    
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(labelItem, NULL);
    menu->setPosition(origin + visibleSize/2);
    this->addChild(menu, 1);
    
    
    return true;
}


void SceneSendText::menuCallback(Ref* pSender)
{
    
    sendText();
    
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
void SceneSendText::sendText()
{

}
#endif
