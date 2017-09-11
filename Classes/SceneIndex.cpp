#include "SceneIndex.h"
#include "SceneManager.hpp"

USING_NS_CC;

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

    
    auto manager = SceneManager::getInstance();
    
    auto menu = Menu::create();
    int maxSceneId = manager->getMaxSceneId();
    for(int i = 1 ; i <= maxSceneId; i++)
    {
        auto labelItem = MenuItemLabel::create(
                                               Label::createWithTTF(manager->getSceneNameById(i), "fonts/arial.ttf", 20),
                                               CC_CALLBACK_1(SceneIndex::menuCallback, this));
        
        labelItem->setTag(i);
        
        menu->addChild(labelItem);
    }
    
    menu->setPosition(origin + visibleSize/2);
    menu->alignItemsVertically();
    this->addChild(menu, 1);


    return true;
}


void SceneIndex::menuCallback(Ref* pSender)
{
    Node* node = dynamic_cast<Node*>(pSender);
    int id = node->getTag();
    
    CCLOG("scene id = %d",id);
    
    auto scene = SceneManager::getInstance()->createSceneById(id);
    if(scene != nullptr)
    {
        Director::getInstance()->replaceScene(scene);
    }
}
