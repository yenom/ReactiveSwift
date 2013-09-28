//
//  RACPassthroughSubscriber.h
//  ReactiveCocoa
//
//  Created by Justin Spahr-Summers on 2013-06-13.
//  Copyright (c) 2013 GitHub, Inc. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "RACSubscriber.h"

@class RACSignal;

/// Passes through all events to another subscriber while not disposed.
@interface RACPassthroughSubscriber : NSObject <RACSubscriber>

/// Initializes the receiver to pass through events until disposed.
///
/// subscriber - The subscriber to forward events to. This must not be nil.
/// signal     - The signal that will be sending events to the receiver.
/// disposable - When this disposable is disposed, no more events will be
///              forwarded. This must not be nil.
///
/// Returns an initialized passthrough subscriber.
- (instancetype)initWithSubscriber:(id<RACSubscriber>)subscriber signal:(RACSignal *)signal disposable:(RACDisposable *)disposable;

- (void)didSubscribeWithDisposable:(RACDisposable *)disposable __attribute__((unavailable("Pass a disposable to -initWithSubscriber:signal:disposable: instead")));

@end
