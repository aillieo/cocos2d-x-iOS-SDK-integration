//
//  SceneSendText.hpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/11.
//
//

#ifndef SceneSendText_hpp
#define SceneSendText_hpp

#include "cocos2d.h"
#include "SceneBase.h"

class SceneSendText : public SceneBase
{
public:
    static SceneBase* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCallback(cocos2d::Ref* pSender);
    
private:
    
    // implement the "static create()" method manually
    CREATE_FUNC(SceneSendText);


    void sendText();
    
};

#endif /* SceneSendText_hpp */
