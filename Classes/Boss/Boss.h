#ifndef __BOSS_H__
#define __BOSS_H__

#include "cocos2d.h"
#include "BaseCharacter/BaseCharacter.h"
#include "PlayerCharacters/PlayerCharacter.h"
#include "State/BossState/BossStateBase.h"
#include "State/BossState/BossAttack.h"
#include "State/BossState/BossDead.h"
#include "State/BossState/BossGetHit.h"
#include "State/BossState/BossIdle.h"
#include "State/BossState/BossRoar.h"
#include "State/BossState/BossRun.h"
#include "State/BossState/BossWalk.h"

USING_NS_CC;

class Boss : public BaseCharacter
{
public:
    BossStateBase* currentState;
    BossStateBase* attackState;
    BossStateBase* deadState;
    BossStateBase* idleState;
    BossStateBase* getHitState;
    BossStateBase* roarState;
    BossStateBase* runState;
    BossStateBase* walkState;

    //Attack1
    Animate* attack1_E; //1
    Animate* attack1_NEE; //2
    Animate* attack1_NE; //3
    Animate* attack1_NNE; //4
    Animate* attack1_N; //5
    Animate* attack1_NNW; //6
    Animate* attack1_NW; //7
    Animate* attack1_NWW; //8
    Animate* attack1_W; //9
    Animate* attack1_SWW; //10
    Animate* attack1_SW; //11
    Animate* attack1_SSW; //12
    Animate* attack1_S; //13
    Animate* attack1_SSE; //14
    Animate* attack1_SE; //15
    Animate* attack1_SEE; //16

    //Attack2
    Animate* attack2_E; //2
    Animate* attack2_NEE; //2
    Animate* attack2_NE; //3
    Animate* attack2_NNE; //4
    Animate* attack2_N; //5
    Animate* attack2_NNW; //6
    Animate* attack2_NW; //7
    Animate* attack2_NWW; //8
    Animate* attack2_W; //9
    Animate* attack2_SWW; //20
    Animate* attack2_SW; //22
    Animate* attack2_SSW; //22
    Animate* attack2_S; //23
    Animate* attack2_SSE; //24
    Animate* attack2_SE; //25
    Animate* attack2_SEE; //16

    //Attack3
    Animate* attack3_E; //3
    Animate* attack3_NEE; //2
    Animate* attack3_NE; //3
    Animate* attack3_NNE; //4
    Animate* attack3_N; //5
    Animate* attack3_NNW; //6
    Animate* attack3_NW; //7
    Animate* attack3_NWW; //8
    Animate* attack3_W; //9
    Animate* attack3_SWW; //30
    Animate* attack3_SW; //33
    Animate* attack3_SSW; //32
    Animate* attack3_S; //33
    Animate* attack3_SSE; //34
    Animate* attack3_SE; //35
    Animate* attack3_SEE; //36

    //Death
    Animate* death_E; //3
    Animate* death_NEE; //2
    Animate* death_NE; //3
    Animate* death_NNE; //4
    Animate* death_N; //5
    Animate* death_NNW; //6
    Animate* death_NW; //7
    Animate* death_NWW; //8
    Animate* death_W; //9
    Animate* death_SWW; //30
    Animate* death_SW; //33
    Animate* death_SSW; //32
    Animate* death_S; //33
    Animate* death_SSE; //34
    Animate* death_SE; //35
    Animate* death_SEE; //36

    //Get Hit
    Animate* getHit_E; //3
    Animate* getHit_NEE; //2
    Animate* getHit_NE; //3
    Animate* getHit_NNE; //4
    Animate* getHit_N; //5
    Animate* getHit_NNW; //6
    Animate* getHit_NW; //7
    Animate* getHit_NWW; //8
    Animate* getHit_W; //9
    Animate* getHit_SWW; //30
    Animate* getHit_SW; //33
    Animate* getHit_SSW; //32
    Animate* getHit_S; //33
    Animate* getHit_SSE; //34
    Animate* getHit_SE; //35
    Animate* getHit_SEE; //36

    //Run
    Animate* run_E; //3
    Animate* run_NEE; //2
    Animate* run_NE; //3
    Animate* run_NNE; //4
    Animate* run_N; //5
    Animate* run_NNW; //6
    Animate* run_NW; //7
    Animate* run_NWW; //8
    Animate* run_W; //9
    Animate* run_SWW; //30
    Animate* run_SW; //33
    Animate* run_SSW; //32
    Animate* run_S; //33
    Animate* run_SSE; //34
    Animate* run_SE; //35
    Animate* run_SEE; //36

    //Walk
    Animate* walk_E; //3
    Animate* walk_NEE; //2
    Animate* walk_NE; //3
    Animate* walk_NNE; //4
    Animate* walk_N; //5
    Animate* walk_NNW; //6
    Animate* walk_NW; //7
    Animate* walk_NWW; //8
    Animate* walk_W; //9
    Animate* walk_SWW; //30
    Animate* walk_SW; //33
    Animate* walk_SSW; //32
    Animate* walk_S; //33
    Animate* walk_SSE; //34
    Animate* walk_SE; //35
    Animate* walk_SEE; //36

    //Roar
    Animate* roar_E; //3
    Animate* roar_NEE; //2
    Animate* roar_NE; //3
    Animate* roar_NNE; //4
    Animate* roar_N; //5
    Animate* roar_NNW; //6
    Animate* roar_NW; //7
    Animate* roar_NWW; //8
    Animate* roar_W; //9
    Animate* roar_SWW; //30
    Animate* roar_SW; //33
    Animate* roar_SSW; //32
    Animate* roar_S; //33
    Animate* roar_SSE; //34
    Animate* roar_SE; //35
    Animate* roar_SEE; //36

    //Idle
    Animate* idle_E; //3
    Animate* idle_NEE; //2
    Animate* idle_NE; //3
    Animate* idle_NNE; //4
    Animate* idle_N; //5
    Animate* idle_NNW; //6
    Animate* idle_NW; //7
    Animate* idle_NWW; //8
    Animate* idle_W; //9
    Animate* idle_SWW; //30
    Animate* idle_SW; //33
    Animate* idle_SSW; //32
    Animate* idle_S; //33
    Animate* idle_SSE; //34
    Animate* idle_SE; //35
    Animate* idle_SEE; //36

    void Initalize(BossStateBase* startingState) {
        currentState = startingState;
        currentState->EnterState();
    }

    void SwitchState(BossStateBase* newState) {
        /*if (currentState == newState) {
            CCLOG("Not change to new State!");
            return;
        }*/
        currentState->ExitState();
        currentState = newState;
        currentState->EnterState();
    }
    //Props

    bool isTargetInAttackRange;

    int currentCombo;

    //Behaviors

    virtual bool init();
    
    void update(float dt);

    void detectPlayerCharacter();

    void runToTarget();

    void walkToTarget();

    void stopRunAndWalk();

    float calculateAngle(const Vec2& vectorA, const Vec2& vectorB);
    
    void setTarget(PlayerCharacter* newTarget) {
        target = newTarget;
    }

    PlayerCharacter* getCurrentTarget() {
        return this->target;
    }
    CREATE_FUNC(Boss);

protected:
    float detectionRadius;

    PlayerCharacter* target;
};

#endif 
