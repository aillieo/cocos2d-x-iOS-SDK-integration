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
using namespace cocos2d::ui;

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
    menu->setPosition(origin + Point(visibleSize.width/2, visibleSize.height/3));
    this->addChild(menu, 1);
    
    
    
    
    m_str = "";
    m_editBox = cocos2d::ui::EditBox::create(Size(100,18), Scale9Sprite::create("edit_box.png"));
    m_editBox->setPosition(origin + Point(visibleSize.width/2, visibleSize.height*2/3));
    m_editBox->setFontColor(Color3B(0,0,0));
    m_editBox->setPlaceHolder("input here");
    m_editBox->setMaxLength(100);
    m_editBox->setInputMode(cocos2d::ui::EditBox::InputMode::SINGLE_LINE);
    //m_editBox->setInputFlag(cocos2d::ui::EditBox::InputFlag::INITIAL_CAPS_WORD);
    m_editBox->setReturnType(cocos2d::ui::EditBox::KeyboardReturnType::DONE);
    m_editBox->setDelegate(this);
    addChild(m_editBox);
    
    
    
    
    return true;
}


void SceneSendText::menuCallback(Ref* pSender)
{
    
    sendText(m_str);
    
}


void SceneSendText::editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox)
{
    log("%s",__func__);
}

void SceneSendText::editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox)
{
    log("%s",__func__);
}

void SceneSendText::editBoxTextChanged(cocos2d::ui::EditBox* editBox,const std::string &text)
{
    log("%s",__func__);
    
    m_str = editBox->getText();
}

void SceneSendText::editBoxReturn(cocos2d::ui::EditBox *editBox)
{
    log("%s",__func__);
}


#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
void SceneSendText::sendText(std::string str)
{
    JniMethodInfo t;
    cocos2d::log("will try call method");
    if(JniHelper::getStaticMethodInfo(t, CLASS_NAME, "sendText", "(Ljava/lang/String;)V"))
    {
        cocos2d::log("has this static method");

        jstring jText = t.env->NewStringUTF(str.c_str());
        t.env->CallStaticVoidMethod(t.classID, t.methodID, jText);
        t.env->DeleteLocalRef(jText);

    }
    
}
#endif
