#ifndef __PLAYER_CHARACTER_DEAD_H__
#define __PLAYER_CHARACTER_DEAD_H__

#include "cocos2d.h"
#include "PlayerCharacterStateBase.h"
USING_NS_CC;

class PlayerCharacterDead : public PlayerCharacterStateBase
{
public:
    PlayerCharacterDead(PlayerCharacter* crt) : PlayerCharacterStateBase(crt) {}
    virtual void EnterState() override;
    virtual void UpdateState() override;
    virtual void ExitState() override;

private:
    int lastDir;
};

#endif 
