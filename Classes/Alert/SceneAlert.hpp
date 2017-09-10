//
//  SceneAlert.hpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/8/18.
//
//

#ifndef SceneAlert_hpp
#define SceneAlert_hpp

#include "cocos2d.h"
#include "SceneBase.h"

class SceneAlert : public SceneBase
{
public:
    static SceneBase* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCallback(cocos2d::Ref* pSender);
    
private:
    
    // implement the "static create()" method manually
    CREATE_FUNC(SceneAlert);


    void showAlert();
    
};

#endif /* SceneAlert_hpp */
