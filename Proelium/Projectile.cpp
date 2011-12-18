//
//  Projectile.cpp
//  Proelium
//
//  Created by Cameron Deans on 16/12/2011.
//  Copyright (c) 2011 Cameron Deans. All rights reserved.
//



#import "Projectile.h"

Projectile::Projectile(Direction::Enum direction)
{
    movmentRate = 2.0f;
    
    Number size = 0.2f;
    model = new ScenePrimitive(ScenePrimitive::TYPE_BOX, size, size, size);
    this->direction = direction;
    
    //In micro seconds?
    //Arbitraty value for testing atm.
    lifetimeRemaining = 250;
}



