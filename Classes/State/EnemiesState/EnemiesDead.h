#ifndef __ENEMIES_DEAD_H__
#define __ENEMIES_DEAD_H__

#include "cocos2d.h"
#include "EnemiesStateBase.h"
USING_NS_CC;

class EnemiesDead : public EnemiesStateBase
{
public:
    EnemiesDead(Enemy* crt) : EnemiesStateBase(crt) {}
    virtual void EnterState() override;
    virtual void UpdateState() override;
    virtual void ExitState() override;

private:
    int lastDir;
};

#endif 
