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
#include "cocos-ext.h"

class SceneGetText : public SceneBase, public cocos2d::ui::EditBoxDelegate
{
public:
    static SceneBase* createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCallback(cocos2d::Ref* pSender);
    
private:
    
    // implement the "static create()" method manually
    CREATE_FUNC(SceneGetText);
    
    cocos2d::ui::EditBox* m_editBox;
    
    cocos2d::Label* m_label;
    
    std::string getText(std::string str);
    std::string m_str;
    
    // EditBoxDelegate
    void editBoxEditingDidBegin(cocos2d::ui::EditBox* editBox);
    void editBoxEditingDidEnd(cocos2d::ui::EditBox* editBox);
    void editBoxTextChanged(cocos2d::ui::EditBox* editBox,const std::string &text);
    void editBoxReturn(cocos2d::ui::EditBox *editBox);

};


#endif /* SceneGetText_hpp */
