//
//  SceneSendText.mm
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/11.
//
//

#include "SceneSendText.hpp"
#import "AppController.h"

void SceneSendText::sendText(std::string str)
{

    NSString * nsstr = [NSString stringWithUTF8String:str.c_str()];
    NSLog(@"showAlert OC");
    
    UIAlertController*alert = [UIAlertController
                               alertControllerWithTitle: @"Title"
                               message: nsstr
                               preferredStyle:UIAlertControllerStyleAlert];
    
    [alert addAction:[UIAlertAction
                      actionWithTitle:@"OK"
                      style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action)
                      {
                      }]];
    
    // get rootViewController
    RootViewController *rvc = [AppController getRootViewController];
    [rvc presentViewController:alert
                      animated:YES completion:nil];
    
}
