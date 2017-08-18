#pragma once

#include "cocos2d.h"

class SceneBase : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

protected:
    
    void setTitle(const std::string& title);
    
private:
    
    CREATE_FUNC(SceneBase);
    
    cocos2d::Label* m_title;
    
};
