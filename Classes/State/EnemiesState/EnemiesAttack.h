#ifndef __ENEMIES_ATTACK_H__
#define __ENEMIES_ATTACK_H__

#include "cocos2d.h"
#include "EnemiesStateBase.h"
USING_NS_CC;

class EnemiesAttack : public EnemiesStateBase
{
public:
    EnemiesAttack(Enemy* crt) : EnemiesStateBase(crt) {}
    virtual void EnterState() override;
    virtual void UpdateState() override;
    virtual void ExitState() override;

private:
    int lastDir;
};

#endif 
