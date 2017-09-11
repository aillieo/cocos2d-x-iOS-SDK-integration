//
//  SceneManager.hpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/11.
//
//

#ifndef SceneManager_hpp
#define SceneManager_hpp

#include "SceneBase.h"

class SceneManager
{
public:

    static SceneManager* getInstance();
    static void DestroyInstance();

    SceneBase* createSceneById(int id);
    std::string getSceneNameById(int id);

    int getMaxSceneId();
    
private:
    
    static SceneManager* instance;
    
    void reset();
};

#endif /* SceneManager_hpp */
