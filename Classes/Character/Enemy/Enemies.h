#ifndef __ENEMIES_H__
#define __ENEMIES_H__

#include "cocos2d.h"
#include "Character/Character.h"
#include "CharacterState/EnemiesState/EnemiesStateBase.h"
#include "CharacterState/EnemiesState/EnemiesAttack.h"
#include "CharacterState/EnemiesState/EnemiesDead.h"
#include "CharacterState/EnemiesState/EnemiesIdle.h"
#include "CharacterState/EnemiesState/EnemiesWalk.h"
USING_NS_CC;

class Enemies : public Character
{
public:
    EnemiesStateBase* currentState;
    EnemiesStateBase* attackState;
    EnemiesStateBase* walkState;
    EnemiesStateBase* idleState;
    EnemiesStateBase* deadState;

    //default Attack
    Animate* defaultAttack_E; //1
    Animate* defaultAttack_NEE; //2
    Animate* defaultAttack_NE; //3
    Animate* defaultAttack_NNE; //4
    Animate* defaultAttack_N; //5
    Animate* defaultAttack_NNW; //6
    Animate* defaultAttack_NW; //7
    Animate* defaultAttack_NWW; //8
    Animate* defaultAttack_W; //9
    Animate* defaultAttack_SWW; //10
    Animate* defaultAttack_SW; //11
    Animate* defaultAttack_SSW; //12
    Animate* defaultAttack_S; //13
    Animate* defaultAttack_SSE; //14
    Animate* defaultAttack_SE; //15
    Animate* defaultAttack_SEE; //16

    //Default Walk
    Animate* defaultWalk_E; //1
    Animate* defaultWalk_NEE; //2
    Animate* defaultWalk_NE; //3
    Animate* defaultWalk_NNE; //4
    Animate* defaultWalk_N; //5
    Animate* defaultWalk_NNW; //6
    Animate* defaultWalk_NW; //7
    Animate* defaultWalk_NWW; //8
    Animate* defaultWalk_W; //9
    Animate* defaultWalk_SWW; //10
    Animate* defaultWalk_SW; //11
    Animate* defaultWalk_SSW; //12
    Animate* defaultWalk_S; //13
    Animate* defaultWalk_SSE; //14
    Animate* defaultWalk_SE; //15
    Animate* defaultWalk_SEE; //16

    //Special Dead
    Animate* specialDeath_E; //1
    Animate* specialDeath_NEE; //2
    Animate* specialDeath_NE; //3
    Animate* specialDeath_NNE; //4
    Animate* specialDeath_N; //5
    Animate* specialDeath_NNW; //6
    Animate* specialDeath_NW; //7
    Animate* specialDeath_NWW; //8
    Animate* specialDeath_W; //9
    Animate* specialDeath_SWW; //10
    Animate* specialDeath_SW; //11
    Animate* specialDeath_SSW; //12
    Animate* specialDeath_S; //13
    Animate* specialDeath_SSE; //14
    Animate* specialDeath_SE; //15
    Animate* specialDeath_SEE; //16

    //Default Idle
    Animate* defaultIdle_E; //1
    Animate* defaultIdle_NEE; //2
    Animate* defaultIdle_NE; //3
    Animate* defaultIdle_NNE; //4
    Animate* defaultIdle_N; //5
    Animate* defaultIdle_NNW; //6
    Animate* defaultIdle_NW; //7
    Animate* defaultIdle_NWW; //8
    Animate* defaultIdle_W; //9
    Animate* defaultIdle_SWW; //10
    Animate* defaultIdle_SW; //11
    Animate* defaultIdle_SSW; //12
    Animate* defaultIdle_S; //13
    Animate* defaultIdle_SSE; //14
    Animate* defaultIdle_SE; //15
    Animate* defaultIdle_SEE; //16

    virtual bool init();

    void Initalize(EnemiesStateBase* startingState) {
        currentState = startingState;
        currentState->EnterState();
    }

    void SwitchState(EnemiesStateBase* newState) {
        /*if (currentState == newState) {
            CCLOG("Not change to new State!");
            return;
        }*/
        currentState->ExitState();
        currentState = newState;
        currentState->EnterState();
    }

    CREATE_FUNC(Enemies);

private:

};

#endif 
