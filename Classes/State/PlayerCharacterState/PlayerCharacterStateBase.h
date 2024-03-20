#ifndef __PLAYER_CHARACTER_STATE_BASE_H__
#define __PLAYER_CHARACTER_STATE_BASE_H__

#include "cocos2d.h"
//class StateManager;
class PlayerCharacter;
USING_NS_CC;

class PlayerCharacterStateBase
{
public:
    PlayerCharacterStateBase(PlayerCharacter* crt) : playerCharacter(crt) {}

    virtual void EnterState() = 0;
    virtual void UpdateState() = 0;
    virtual void ExitState() = 0;

protected:
    PlayerCharacter* playerCharacter;
};

#endif // __STATE_BASE_H__

