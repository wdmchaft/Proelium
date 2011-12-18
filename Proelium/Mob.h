//
//  Mob.h
//  Proelium
//
//  Created by Cameron Deans on 16/12/2011.
//  Copyright (c) 2011 Cameron Deans. All rights reserved.
//


#ifndef PolycodeTemplate_Mob_h
#define PolycodeTemplate_Mob_h

#include <iostream>
#include "Polycode.h"
#include "Projectile.h"
#include <vector>

class Mob {
    
public:
    Mob();
    ~Mob();
    ScenePrimitive* model;
    int currentHealth;
    int maxHealth;
    Polycode::String name;
    std::vector<Projectile*> activeProjectiles;
    
    ScenePrimitive* ShootProjectile(Direction::Enum dir);
    void Update(Number elapsed, Scene *scene);
    void DeleteProjectile(int i, vector<Projectile*>vector);
};


#endif
