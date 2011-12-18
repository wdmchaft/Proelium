//
//  Mob.cpp
//  Proelium
//
//  Created by Cameron Deans on 16/12/2011.
//  Copyright (c) 2011 Cameron Deans. All rights reserved.
//

#include "Mob.h"

Mob::Mob()
{
    int size = 1;
    model = new ScenePrimitive(ScenePrimitive::TYPE_BOX, size, size, size);
    
    currentHealth = 30;
    maxHealth = 100; 
    name = "Mob";
}
Mob::~Mob()
{
    //Alert of death?
    //Drop loot?
}