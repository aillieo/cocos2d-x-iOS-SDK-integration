//
//  SceneGetText.hpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/11.
//
//

#ifndef SceneGetText_hpp
#define SceneGetText_hpp


#include "cocos2d.h"
#include "SceneBase.h"

class SceneGetText : public SceneBase
{
public:
    static SceneBase* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCallback(cocos2d::Ref* pSender);
    
private:
    
    // implement the "static create()" method manually
    CREATE_FUNC(SceneGetText);
    
    
    void getText();
    
};


#endif /* SceneGetText_hpp */
