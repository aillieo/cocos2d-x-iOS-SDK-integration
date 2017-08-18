//
//  ScenePrompt.hpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/8/18.
//
//

#ifndef ScenePrompt_hpp
#define ScenePrompt_hpp

#include "cocos2d.h"
#include "SceneBase.h"

class ScenePrompt : public SceneBase
{
public:
    static SceneBase* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCallback(cocos2d::Ref* pSender);
    
private:
    
    // implement the "static create()" method manually
    CREATE_FUNC(ScenePrompt);


    void showPrompt();
    
};

#endif /* ScenePrompt_hpp */
