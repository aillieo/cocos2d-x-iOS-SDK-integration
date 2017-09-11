#pragma once

#include "cocos2d.h"

class SceneBase : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    void setTitle(const std::string& title);
    
private:
    
    void backToSceneIndex(cocos2d::Ref* pSender);
    
    CREATE_FUNC(SceneBase);
    
    cocos2d::Label* m_title;
    
};
