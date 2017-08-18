#ifndef __SCENEINDEX_H__
#define __SCENEINDEX_H__

#include "cocos2d.h"

class SceneIndex : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCallback(cocos2d::Ref* pSender);

private:

    // implement the "static create()" method manually
    CREATE_FUNC(SceneIndex);
    
};

#endif // __SCENEINDEX_H__
