#ifndef __ENEMIES_STATE_BASE_H__
#define __ENEMIES_STATE_BASE_H__

#include "cocos2d.h"
//class StateManager;
class Enemies;
USING_NS_CC;

class EnemiesStateBase
{
public:
    EnemiesStateBase(Enemies* crt) : enemies(crt) {}

    virtual void EnterState() = 0;
    virtual void UpdateState() = 0;
    virtual void ExitState() = 0;

protected:
    Enemies* enemies;
};

#endif // __STATE_BASE_H__

