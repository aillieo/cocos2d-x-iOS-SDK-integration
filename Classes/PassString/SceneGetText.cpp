//
//  SceneGetText.cpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/11.
//
//

#include "SceneGetText.hpp"


USING_NS_CC;

SceneBase* SceneGetText::createScene()
{
    return SceneGetText::create();
}

// on "init" you need to initialize your instance
bool SceneGetText::init()
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
                                           CC_CALLBACK_1(SceneGetText::menuCallback, this));
    
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(labelItem, NULL);
    menu->setPosition(origin + visibleSize/2);
    this->addChild(menu, 1);
    
    
    return true;
}


void SceneGetText::menuCallback(Ref* pSender)
{
    
    getText();
    
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
void SceneGetText::getText()
{
    
}
#endif
