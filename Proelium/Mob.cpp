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
    
    //Not used currently
    currentHealth = 30;
    maxHealth = 100; 
    name = "Mob";
}

Mob::~Mob()
{
    //Alert of death?
    //Drop loot?
}

ScenePrimitive* Mob::ShootProjectile(Direction::Enum dir)
{
    Projectile* tempProjectile = new Projectile(dir); 
    tempProjectile->model->setPosition(this->model->getPosition());
    activeProjectiles.push_back(tempProjectile);
    return tempProjectile->model;
}
void Mob::Update(Number elapsed, Scene *scene)
{
    //Is there any 'live' projectiles?
    if(!activeProjectiles.empty())
    {
        for(int i=0; i < activeProjectiles.size();i++)
        {
            
            //Take off the time since the last frame
            activeProjectiles[i]->lifetimeRemaining = activeProjectiles[i]->lifetimeRemaining - elapsed;
            
            if (activeProjectiles[i]->lifetimeRemaining <= 0) {
                //Delete the bullet
                vector<Projectile*>::iterator iter = activeProjectiles.begin() + i;
                scene->removeEntity(activeProjectiles[i]->model);
                
                delete activeProjectiles[i];
                activeProjectiles[i] = NULL;
                activeProjectiles.erase(iter);
                return;
            }
            
            
            if (activeProjectiles[i]->direction == Direction::Left) {
                activeProjectiles[i]->model->setPositionZ(activeProjectiles[i]->model->getPosition().z + (activeProjectiles[i]->movmentRate * elapsed));    
            }
            else if (activeProjectiles[i]->direction == Direction::Right) {
                activeProjectiles[i]->model->setPositionZ(activeProjectiles[i]->model->getPosition().z - (activeProjectiles[i]->movmentRate * elapsed));
            }
            else if (activeProjectiles[i]->direction == Direction::Up) {
                activeProjectiles[i]->model->setPositionX(activeProjectiles[i]->model->getPosition().x - (activeProjectiles[i]->movmentRate * elapsed));
            }
            else if (activeProjectiles[i]->direction == Direction::Down) {
                activeProjectiles[i]->model->setPositionX(activeProjectiles[i]->model->getPosition().x + (activeProjectiles[i]->movmentRate * elapsed));
            }
            else
            {
                //We dont have a direction? WTF!
            }
            
        }
    }
}