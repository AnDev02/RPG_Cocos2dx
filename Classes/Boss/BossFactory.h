#ifndef __BOSS_FACTORY_H__
#define __BOSS_FACTORY_H__

#include "cocos2d.h"

#include "Boss.h"
#include "HellBeast.h"

USING_NS_CC;

class BossFactory
{
public:
    static Boss* createBoss(std::string bossType);
};

#endif 
