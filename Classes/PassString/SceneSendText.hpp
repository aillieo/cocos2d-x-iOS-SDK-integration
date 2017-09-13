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
#include "cocos-ext.h"

class SceneSendText : public SceneBase, public cocos2d::ui::EditBoxDelegate
{
public:
    static SceneBase* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCallback(cocos2d::Ref* pSender);
    
private:
    
    // implement the "static create()" method manually
    CREATE_FUNC(SceneSendText);

    
    // EditBoxDelegate
    void editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox);
    void editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox);
    void editBoxTextChanged(cocos2d::ui::EditBox* editBox,const std::string &text);
    void editBoxReturn(cocos2d::ui::EditBox *editBox);

    // EditBox
    cocos2d::ui::EditBox* m_editBox;
    std::string m_str;
    
    
    void sendText(std::string str);
    
};

#endif /* SceneSendText_hpp */
