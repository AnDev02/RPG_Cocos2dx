#ifndef __ENEMIES_FACTORY_H__
#define __ENEMIES_FACTORY_H__

#include "cocos2d.h"

#include "Enemies.h"
#include "Skeleton.h"
#include "Slime.h"
#include "ShadowLord.h"

USING_NS_CC;

class EnemiesFactory
{
public:
    static Enemies* createEnemies(std::string enemiesType);
};

#endif 
