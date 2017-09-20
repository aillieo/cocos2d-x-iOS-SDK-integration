//
//  SceneLocalNotification.hpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/20.
//
//

#ifndef SceneLocalNotification_hpp
#define SceneLocalNotification_hpp

#include "cocos2d.h"
#include "SceneBase.h"

class SceneLocalNotification : public SceneBase
{
public:
    static SceneBase* createScene();
    
    virtual bool init();
    
    void menuCallback(cocos2d::Ref* pSender);
    
private:
    
    CREATE_FUNC(SceneLocalNotification);
    
};

#endif /* SceneLocalNotification_hpp */
