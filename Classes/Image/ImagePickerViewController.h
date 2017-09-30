//
//  ImagePickerViewController.h
//  cocos2d-x-sdk-integration-mobile
//
//  Created by Aillieo on 2017/9/30.
//

#import <UIKit/UIKit.h>


@interface ImagePickerViewController: UIViewController<UINavigationControllerDelegate, UIImagePickerControllerDelegate>
{
    NSString *filePath;
}

-(void)selectFromPhoto;

-(void)takeWithCamera;

@end
