//
//  SceneGetImage.cpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/20.
//
//

#include "SceneGetImage.hpp"

USING_NS_CC;

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
    
    
    auto labelItem = MenuItemLabel::create(Label::createWithTTF("CLICK ME", "fonts/arial.ttf", 24),
                                           CC_CALLBACK_1(SceneGetImage::menuCallback, this));
    
    
    auto menu = Menu::create(labelItem, NULL);
    menu->setPosition(origin + visibleSize/2);
    this->addChild(menu, 1);
    
    return true;
}


void SceneGetImage::menuCallback(Ref* pSender)
{
    
}
