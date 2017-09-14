//
//  SceneGetText.cpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/11.
//
//

#include "SceneGetText.hpp"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#include "platform/android/jni/JniHelper.h"
#define CLASS_NAME "com/aillieo/cocos2d_x_sdk_integration/SceneGetText"
#endif

USING_NS_CC;
using namespace cocos2d::ui;

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
    
    
    
    m_label = Label::createWithTTF("", "fonts/arial.ttf", 24);
    m_label->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.width*3/4);
    this->addChild(m_label);
    
    
    
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
    
    
    
    
    
    auto labelItem = MenuItemLabel::create(Label::createWithTTF("CLICK ME", "fonts/arial.ttf", 24),
                                           CC_CALLBACK_1(SceneGetText::menuCallback, this));
    
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(labelItem, NULL);
    menu->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.width/4);
    this->addChild(menu, 1);
    
    
    return true;
}


void SceneGetText::menuCallback(Ref* pSender)
{
    
    std::string text = getText(m_str);
    m_label->setString(text);
    
}


void SceneGetText::editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox)
{
    log("%s",__func__);
}

void SceneGetText::editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox)
{
    log("%s",__func__);
}

void SceneGetText::editBoxTextChanged(cocos2d::ui::EditBox* editBox, const std::string &text)
{
    log("%s",__func__);
    m_str = editBox->getText();
}

void SceneGetText::editBoxReturn(cocos2d::ui::EditBox *editBox)
{
    log("%s",__func__);
}



#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
std::string SceneGetText::getText(std::string str)
{
    JniMethodInfo t;
    cocos2d::log("will try call method");
    if(JniHelper::getStaticMethodInfo(t, CLASS_NAME, "getText", "(Ljava/lang/String;)Ljava/lang/String;"))
    {
        cocos2d::log("has this static method");
        
        jstring inStr = t.env->NewStringUTF(str.c_str());
        jstring outStr = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID, inStr);
        t.env->DeleteLocalRef(inStr);
        const char* c_str= t.env->GetStringUTFChars(outStr, NULL);
        std::string ret(c_str);
        t.env->ReleaseStringUTFChars(outStr, c_str);
        
        return ret;
    }
}
#endif
