//
//  ImagePickerViewController.m
//  cocos2d-x-sdk-integration-mobile
//
//  Created by Aillieo on 2017/9/30.
//

#import "ImagePickerViewController.h"

#import <Foundation/Foundation.h>
#import "ImagePickerViewController.h"

@interface ImagePickerViewController ()

@end

@implementation ImagePickerViewController

-(void)viewDidLoad
{
    [super viewDidLoad];
}

-(void)viewDidUnload
{
    [super viewDidUnload];
}

-(void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
}

-(void)selectFromPhoto
{
    NSLog(@"-(void)localPhoto");
    UIImagePickerController *picker = [[UIImagePickerController alloc]init];
    picker.delegate = self;
    picker.sourceType = UIImagePickerControllerSourceTypePhotoLibrary;
    picker.allowsEditing = YES;
    [self presentViewController:picker animated:YES completion:^(void)
     {
         NSLog(@"ImageViewController is presented");
     }];
    [picker release];
}

-(void)takeWithCamera
{
    UIImagePickerControllerSourceType sourceType = UIImagePickerControllerSourceTypeCamera;
    if ([UIImagePickerController isSourceTypeAvailable:sourceType])
    {
        UIImagePickerController *picker = [[UIImagePickerController alloc]init];
        picker.delegate = self;
        picker.allowsEditing = YES;
        picker.sourceType = sourceType;
        [self presentViewController:picker animated:YES completion:^(void)
         {
             NSLog(@"ImageViewController is presented");
         }];
    }
    else
    {
        NSLog(@"模拟器无法使用相机，请在真机中调试");
    }
    NSLog(@"-(void)takePhoto");
}

-(void)imagePickerController:(UIImagePickerController *)picker didFinishPickingMediaWithInfo:(NSDictionary<NSString *,id> *)info
{
    NSString *type = [info objectForKey:@"UIImagePickerControllerMediaType"];
    if ([type isEqualToString:@"public.image"])
    {

        //UIImage *image = [info objectForKey:@"UIImagePickerControllerOriginalImage"];
        UIImage *image = [info objectForKey:@"UIImagePickerControllerEditedImage"];
        NSData *data;
        if (UIImagePNGRepresentation(image) == nil)
        {
            data = UIImageJPEGRepresentation(image, 1.0);
        }
        else
        {
            data = UIImagePNGRepresentation(image);
        }
        
        //图片保存路径
        //这里将图片放在沙盒的documents/image文件夹中
        NSString *documentsPath = [NSHomeDirectory() stringByAppendingPathComponent:@"Documents"];
        NSString *imgPath = [documentsPath stringByAppendingPathComponent:@"image"];
        

        NSFileManager *fileManager = [NSFileManager defaultManager];

        NSString *uuid = [[NSUUID UUID]UUIDString];

        NSString *fileName = [NSString stringWithFormat:@"%@.png",uuid];
        
        [fileManager removeItemAtPath:imgPath error:nil];

        [fileManager createDirectoryAtPath:imgPath withIntermediateDirectories:YES attributes:nil error:nil];
        [fileManager createFileAtPath:[imgPath stringByAppendingPathComponent:fileName] contents:data attributes:nil];
        
        filePath = [[NSString alloc]initWithFormat:@"%@",[imgPath stringByAppendingPathComponent:fileName]];
        
        [picker dismissViewControllerAnimated:YES completion:^(void){}];
        
        // 向原scene发送事件 带上文件路径
        std::string strFilePath = [filePath UTF8String];
        cocos2d::Director::getInstance()->getEventDispatcher()->dispatchCustomEvent("ImagePickEnd",&strFilePath);
        
    }
}

-(void)imagePickerControllerDidCancel:(UIImagePickerController *)picker
{
    NSLog(@"您取消了照片选择");
    [picker dismissViewControllerAnimated:YES completion:^(void){}];
}

@end
