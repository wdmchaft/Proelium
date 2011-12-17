//
//  AppDelegate.h
//  Proelium
//
//  Created by Cameron Deans on 17/12/2011.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "PolycodeView.h"
#include "ProeliumApp.h"

@interface AppDelegate : NSObject <NSApplicationDelegate> 
{
    PolycodeView *mainView;
    ProeliumApp *app;
    NSTimer *timer;
}

@property (assign) IBOutlet NSWindow *window;
@property (assign) IBOutlet PolycodeView *mainView;

@end
