#ifndef __ENEMIES_IDLE_H__
#define __ENEMIES_IDLE_H__

#include "cocos2d.h"
#include "EnemiesStateBase.h"
USING_NS_CC;

class EnemiesIdle : public EnemiesStateBase
{
public:
    EnemiesIdle(Enemy* crt) : EnemiesStateBase(crt) {}
    virtual void EnterState() override;
    virtual void UpdateState() override;
    virtual void ExitState() override;

private:
    int lastDir;
};

#endif 