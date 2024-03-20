#ifndef __PLAYER_CHARACTER_FACTORY_H__
#define __PLAYER_CHARACTER_FACTORY_H__

#include "cocos2d.h"

#include "./PlayerCharacter.h"
#include "./Knight/Knight.h"
#include "./Warrior/Warrior.h"
#include "./Fighter/Fighter.h"

USING_NS_CC;

class PlayerCharacterFactory
{
public:
    static PlayerCharacter* createPlayerCharacter(std::string playerType);
};

#endif 
