#include "SceneIndex.h"

USING_NS_CC;
#include "ScenePrompt.hpp"

Scene* SceneIndex::createScene()
{
    return SceneIndex::create();
}

// on "init" you need to initialize your instance
bool SceneIndex::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }
    
    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    
    
    auto labelItem = MenuItemLabel::create(
         Label::createWithTTF("Hello World", "fonts/arial.ttf", 24),
         CC_CALLBACK_1(SceneIndex::menuCallback, this));
    
    labelItem->setTag(1);

    // create menu, it's an autorelease object
    auto menu = Menu::create(labelItem, NULL);
    menu->setPosition(origin + visibleSize/2);
    this->addChild(menu, 1);


    return true;
}


void SceneIndex::menuCallback(Ref* pSender)
{
    
    Node* node = dynamic_cast<Node*>(pSender);
    int tag = node->getTag();
    
    CCLOG("tag = %d",tag);
    
    switch (tag) {
        case 1:
        {
            auto scene = ScenePrompt::createScene();
            Director::getInstance()->replaceScene(scene);
            break;
        }
        default:
            break;
    }
    
}
