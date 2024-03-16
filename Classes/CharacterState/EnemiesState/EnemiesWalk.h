#ifndef __ENEMIES_WALK_H__
#define __ENEMIES_WALK_H__

#include "cocos2d.h"
#include "EnemiesStateBase.h"
USING_NS_CC;

class EnemiesWalk : public EnemiesStateBase
{
public:
    EnemiesWalk(Enemies* crt) : EnemiesStateBase(crt) {}
    virtual void EnterState() override;
    virtual void UpdateState() override;
    virtual void ExitState() override;

private:
    int lastDir;
};

#endif 
