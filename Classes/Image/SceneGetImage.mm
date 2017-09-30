//
//  SceneGetImage.mm
//  cocos2d-x-sdk-integration
//
//  Created by Aillieo on 2017/9/20.
//
//

#include "SceneGetImage.hpp"
#import "AppController.h"
#import "ImagePickerViewController.h"
#import "RootViewController.h"


void SceneGetImage::selectFromPhotos()
{
    ImagePickerViewController * imagePickerViewController = [[ImagePickerViewController alloc]initWithNibName:nil bundle:nil];
    
    RootViewController *rvc = [AppController getRootViewController];
    [rvc.view addSubview:imagePickerViewController.view];
    [imagePickerViewController selectFromPhoto];
}


void SceneGetImage::takeWithCamera()
{
    ImagePickerViewController * imagePickerViewController = [[ImagePickerViewController alloc]initWithNibName:nil bundle:nil];
    
    RootViewController *rvc = [AppController getRootViewController];
    [rvc.view addSubview:imagePickerViewController.view];
    [imagePickerViewController takeWithCamera];
}
