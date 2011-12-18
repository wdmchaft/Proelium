//
//  Projectile.h
//  Proelium
//
//  Created by Cameron Deans on 16/12/2011.
//  Copyright (c) 2011 Cameron Deans. All rights reserved.
//

#ifndef Proelium_Projectile_h
#define Proelium_Projectile_h

#include <iostream>
#include "Polycode.h"

namespace Direction
{
    enum Enum
    {
        Left,
        Right,
        Up,
        Down
    };
}

class Projectile {
    
    
public:
    Projectile(Direction::Enum direction);
    Polycode::ScenePrimitive* model;
    Direction::Enum direction;
    
    float movmentRate;
    int lifetimeRemaining;
    
};



#endif
