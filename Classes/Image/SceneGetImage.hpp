//
//  SceneGetImage.hpp
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/20.
//
//

#ifndef SceneGetImage_hpp
#define SceneGetImage_hpp

#include "cocos2d.h"
#include "SceneBase.h"

class SceneGetImage : public SceneBase
{
public:
    static SceneBase* createScene();
    
    virtual bool init();
    
    void menuCallbackPhoto(cocos2d::Ref* pSender);
    
    void menuCallbackCamera(cocos2d::Ref* pSender);
    
private:
    
    CREATE_FUNC(SceneGetImage);
    
    void selectFromPhotos();
    void takeWithCamera();
    
    void onImagePickEnd(cocos2d::EventCustom* event);
    
    Node* m_imageRoot;
};

#endif /* SceneGetImage_hpp */
