//
//  SGFFObjectQueue.h
//  SGPlayer
//
//  Created by Single on 2018/1/22.
//  Copyright © 2018年 single. All rights reserved.
//

#import <Foundation/Foundation.h>


@protocol SGFFObjectQueueItem <NSObject>

- (long long)position;
- (long long)duration;
- (long long)size;

- (void)lock;
- (void)unlock;

@end


@interface SGFFObjectQueue : NSObject

- (instancetype)init;
- (instancetype)initWithMaxCount:(NSInteger)maxCount;

@property (nonatomic, assign) BOOL shouldSortObjects;

- (NSInteger)count;
- (long long)duration;
- (long long)size;

- (void)putObjectSync:(__kindof id <SGFFObjectQueueItem>)object;
- (void)putObjectAsync:(__kindof id <SGFFObjectQueueItem>)object;

- (__kindof id <SGFFObjectQueueItem>)getObjectSync;
- (__kindof id <SGFFObjectQueueItem>)getObjectAsync;

- (__kindof id <SGFFObjectQueueItem>)getObjectSyncWithPositionHandler:(BOOL(^)(long long * current, long long * expect))positionHandler;
- (__kindof id <SGFFObjectQueueItem>)getObjectAsyncWithPositionHandler:(BOOL(^)(long long * current, long long * expect))positionHandler;

- (void)flush;
- (void)destroy;

@end
