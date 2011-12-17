//
//  AppDelegate.m
//  Proelium
//
//  Created by Cameron Deans on 17/12/2011.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import "AppDelegate.h"

@implementation AppDelegate

@synthesize window = _window;
@synthesize mainView;

- (void)dealloc
{
    [super dealloc];
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    app = new ProeliumApp(mainView);
    timer = [NSTimer timerWithTimeInterval:(1.0f/60.0f) 
                                    target:self 
                                  selector:@selector(animationTimer:) 
                                  userInfo:nil 
                                   repeats:YES];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSDefaultRunLoopMode];
    [[NSRunLoop currentRunLoop] addTimer:timer forMode:NSEventTrackingRunLoopMode];
}

- (BOOL)applicationShouldTerminateAfterLastWindowClosed:(NSApplication *)sender
{
    return YES;
}

-(void)animationTimer:(NSTimer *)timer
{
    if(!app->Update()) {
        [[NSApplication sharedApplication] stop:self];
    }
}

@end
