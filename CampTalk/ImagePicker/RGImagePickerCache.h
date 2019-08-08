//
//  RGImagePickerCache.h
//  CampTalk
//
//  Created by renge on 2019/8/1.
//  Copyright © 2019 yuru. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RGImagePickerConst.h"
#import "RGImageAlbumListViewController.h"

NS_ASSUME_NONNULL_BEGIN

extern NSNotificationName RGPHAssetLoadStatusHasChanged;
extern NSNotificationName RGImagePickerCachePickPhotosHasChanged;

@class RGImageAlbumListViewController;

@interface PHAsset (RGLoaded)

@property (nonatomic, assign) CGFloat rgLoadLargeImageProgress;

//@property (nonatomic, assign) BOOL rgIsLoaded;

@property (nonatomic, assign) PHImageRequestID rgRequestId;

@end

@interface RGImagePickerCache : NSObject

@property (nonatomic, strong) NSMutableArray <PHAsset *> *pickPhotos;

@property (nonatomic, assign) NSUInteger maxCount;

@property (nonatomic, strong) NSMutableArray <NSDictionary <NSString *, UIImage *> *> *cachePhotos;

@property (nonatomic, copy) RGImagePickResult pickResult;

// thumbnail
- (void)addThumbCachePhoto:(UIImage *)photo forAsset:(PHAsset *)asset;
- (void)removeThumbCachePhotoForAsset:(NSArray <PHAsset *> *)assets;

// large image
- (UIImage *_Nullable)imageForAsset:(PHAsset *)asset
                          onlyCache:(BOOL)onlyCache
                           syncLoad:(BOOL)syncLoad
                           allowNet:(BOOL)allowNet
                         targetSize:(CGSize)targetSize
                         completion:(void(^_Nullable)(UIImage *image))completion;

// load status
- (void)setLoadStatusCache:(BOOL)loaded forAsset:(PHAsset *)asset;
- (BOOL)loadStatusCacheForAsset:(PHAsset *)asset;
- (void)requestLoadStatusWithAsset:(PHAsset *)asset result:(void(^)(BOOL needLoad))result;

// pick photo
- (void)setPhotos:(NSArray <PHAsset *> *)phassets;
- (void)addPhotos:(NSArray <PHAsset *> *)phassets;
- (void)removePhotos:(NSArray <PHAsset *> *)phassets;
- (BOOL)contain:(PHAsset *)phassets;

- (BOOL)isFull;

- (void)callBack:(UIViewController *)viewController;

- (void)showPickerPhotosWithParentViewController:(UIViewController *)viewController;

@end

@interface RGImagePickerViewController ()

@property (nonatomic, strong) PHAssetCollection *collection;

@property (nonatomic, strong) RGImagePickerCache *cache;

@end

NS_ASSUME_NONNULL_END
