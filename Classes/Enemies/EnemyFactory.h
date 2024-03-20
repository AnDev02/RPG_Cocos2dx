#ifndef __ENEMY_FACTORY_H__
#define __ENEMY_FACTORY_H__

#include "cocos2d.h"

#include "Enemy.h"
#include "./Skeleton/Skeleton.h"
#include "./Slime/Slime.h"
#include "./ShadowLord/ShadowLord.h"

USING_NS_CC;

class EnemyFactory
{
public:
    static Enemy* createEnemy(std::string enemyType);
};

#endif 
