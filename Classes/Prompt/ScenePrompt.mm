//
//  ScenePrompt.mm
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/8/18.
//
//

#include "ScenePrompt.hpp"
#import "AppController.h"

void ScenePrompt::showPrompt()
{
    NSLog(@"showPrompt OC");
    
    UIAlertController*alert = [UIAlertController
                               alertControllerWithTitle: @"Title"
                               message: @"Content"
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
