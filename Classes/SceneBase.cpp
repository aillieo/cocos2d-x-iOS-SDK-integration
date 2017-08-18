#include "SceneBase.h"

USING_NS_CC;

Scene* SceneBase::createScene()
{
    return SceneBase::create();
}

// on "init" you need to initialize your instance
bool SceneBase::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    m_title = Label::createWithTTF("SceneBase", "fonts/arial.ttf", 24);
    
    m_title->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height - m_title->getContentSize().height);
    this->addChild(m_title, 1);


    return true;
}


void SceneBase::setTitle(const std::string& title)
{
    m_title->setString(title.c_str());
}
