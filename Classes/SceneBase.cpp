#include "SceneBase.h"
#include "SceneIndex.h"

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
    
    m_title = Label::createWithTTF("SceneBase", "fonts/arial.ttf", 20);
    
    m_title->setPosition(origin.x + visibleSize.width/2, origin.y + visibleSize.height - m_title->getContentSize().height);
    this->addChild(m_title, 1);

    
    
    
    auto labelItem = MenuItemLabel::create(Label::createWithTTF("BACK", "fonts/arial.ttf", 18),
                                           CC_CALLBACK_1(SceneBase::backToSceneIndex, this));
    auto menu = Menu::create(labelItem, NULL);
    menu->setPosition(origin.x + labelItem->getContentSize().width /2,
                      origin.y + visibleSize.height - labelItem->getContentSize().height /2);
    this->addChild(menu, 1);
    
    

    return true;
}


void SceneBase::setTitle(const std::string& title)
{
    m_title->setString(title.c_str());
}

void SceneBase::backToSceneIndex(cocos2d::Ref* pSender)
{
    Director::getInstance()->replaceScene(SceneIndex::createScene());
}
