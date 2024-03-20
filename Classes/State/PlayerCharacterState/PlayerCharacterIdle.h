#ifndef __PLAYER_CHARACTER_IDLE_H__
#define __PLAYER_CHARACTER_IDLE_H__

#include "cocos2d.h"
#include "PlayerCharacterStateBase.h"
USING_NS_CC;

class PlayerCharacterIdle : public PlayerCharacterStateBase
{
public:
    PlayerCharacterIdle(PlayerCharacter* crt) : PlayerCharacterStateBase(crt) {}
    virtual void EnterState() override;
    virtual void UpdateState() override;
    virtual void ExitState() override;

private:
    int lastDir;
};

#endif 
