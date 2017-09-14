//
//  SceneManager.cpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/11.
//
//

#include "SceneManager.hpp"
#include "SceneAlert.hpp"
#include "SceneSendText.hpp"
#include "SceneGetText.hpp"

SceneManager* SceneManager::instance = nullptr;
SceneManager* SceneManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new SceneManager();
        instance->reset();
    }
    return instance;
}

void SceneManager::DestroyInstance()
{
    
    if(!instance)
    {
        return;
    }
    else
    {
        instance->reset();
        delete instance;
        instance = nullptr;
    }
    
}

void SceneManager::reset()
{

}

SceneBase* SceneManager::createSceneById(int id)
{
    SceneBase* scene = nullptr;
    switch (id) {
        case 1:
            scene = SceneAlert::createScene();
            break;
        case 2:
            scene = SceneSendText::createScene();
            break;
        case 3:
            scene = SceneGetText::createScene();
            break;
        default:
            break;
    }
    
    if(scene != nullptr)
    {
        scene->setTitle(getSceneNameById(id));
    }
    
    return scene;
}


std::string SceneManager::getSceneNameById(int id)
{
    
    std::string name = "";
    switch (id) {
        case 1:
            name = "SceneAlert";
            break;
        case 2:
            name = "SceneSendText";
            break;
        case 3:
            name = "SceneGetText";
            break;
        default:
            break;
    }
    
    return name;
}

int SceneManager::getMaxSceneId()
{
    return 3;
}
