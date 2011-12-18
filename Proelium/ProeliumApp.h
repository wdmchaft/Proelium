//
//  ProeliumApp.h
//  Proelium
//
//  Created by Cameron Deans on 16/12/2011.
//  Copyright (c) 2011 Cameron Deans. All rights reserved.
//


#include "PolycodeView.h"
#include "Polycode.h"
#include "Player.h"
#include "Enemy.h"
//For convertIntToString
#include <sstream>

using namespace Polycode;

class ProeliumApp : public EventHandler {
public:
    ProeliumApp(PolycodeView *view);
    ~ProeliumApp();
    
    void handleEvent(Event *e);
    
    bool Update();
    
    Screen *screen;
    Scene *scene;
    Player *player;
private:
    Core *core;
};