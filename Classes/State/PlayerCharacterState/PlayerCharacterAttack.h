#ifndef __PLAYER_CHARACTER_ATTACK_H__
#define __PLAYER_CHARACTER_ATTACK_H__

#include "cocos2d.h"
#include "PlayerCharacterStateBase.h"
USING_NS_CC;

class PlayerCharacterAttack : public PlayerCharacterStateBase
{
public:
    PlayerCharacterAttack(PlayerCharacter* crt) : PlayerCharacterStateBase(crt) {}
    virtual void EnterState() override;
    virtual void UpdateState() override;
    virtual void ExitState() override;

private:
    int lastDir;
};

#endif 
