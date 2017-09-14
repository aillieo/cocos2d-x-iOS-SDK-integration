//
//  SceneGetText.mm
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/11.
//
//

#include "SceneGetText.hpp"
#import "AppController.h"

std::string SceneGetText::getText(std::string str)
{
    NSString * inStr = [NSString stringWithUTF8String:str.c_str()];
    NSString * outStr = [inStr stringByAppendingString: @" from iOS"];
    
    return [outStr UTF8String];
}
