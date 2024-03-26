#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "cocos2d.h"
#include "BaseCharacter/BaseCharacter.h"
#include "State/PlayerCharacterState/PlayerCharacterStateBase.h"
#include "State/PlayerCharacterState/PlayerCharacterAttack.h"
#include "State/PlayerCharacterState/PlayerCharacterDead.h"
#include "State/PlayerCharacterState/PlayerCharacterIdle.h"
#include "State/PlayerCharacterState/PlayerCharacterWalk.h"
#include "State/PlayerCharacterState/PlayerCharacterSelect.h"
#include "UserInterface/InGame/Joystick.h"
#include "Skills/SkillBase.h"
#include "Skills/SkillFactory.h"

USING_NS_CC;

class PlayerCharacter : public BaseCharacter
{
public:
    Vec2 movementDirection;
    Joystick* _joystick;
    PlayerCharacterStateBase* currentState;
    PlayerCharacterStateBase* attackState;
    PlayerCharacterStateBase* walkState;
    PlayerCharacterStateBase* idleState;
    PlayerCharacterStateBase* deadState;
    PlayerCharacterStateBase* selectState;

    //Arm Attack
    Animate* armAttack_E; //1
    Animate* armAttack_NEE; //2
    Animate* armAttack_NE; //3
    Animate* armAttack_NNE; //4
    Animate* armAttack_N; //5
    Animate* armAttack_NNW; //6
    Animate* armAttack_NW; //7
    Animate* armAttack_NWW; //8
    Animate* armAttack_W; //9
    Animate* armAttack_SWW; //10
    Animate* armAttack_SW; //11
    Animate* armAttack_SSW; //12
    Animate* armAttack_S; //13
    Animate* armAttack_SSE; //14
    Animate* armAttack_SE; //15
    Animate* armAttack_SEE; //16

    //Arm Walk
    Animate* armWalk_E; //1
    Animate* armWalk_NEE; //2
    Animate* armWalk_NE; //3
    Animate* armWalk_NNE; //4
    Animate* armWalk_N; //5
    Animate* armWalk_NNW; //6
    Animate* armWalk_NW; //7
    Animate* armWalk_NWW; //8
    Animate* armWalk_W; //9
    Animate* armWalk_SWW; //10
    Animate* armWalk_SW; //11
    Animate* armWalk_SSW; //12
    Animate* armWalk_S; //13
    Animate* armWalk_SSE; //14
    Animate* armWalk_SE; //15
    Animate* armWalk_SEE; //16

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

    //Special Select
    Animate* specialSelect_E; //1
    Animate* specialSelect_NEE; //2
    Animate* specialSelect_NE; //3
    Animate* specialSelect_NNE; //4
    Animate* specialSelect_N; //5
    Animate* specialSelect_NNW; //6
    Animate* specialSelect_NW; //7
    Animate* specialSelect_NWW; //8
    Animate* specialSelect_W; //9
    Animate* specialSelect_SWW; //10
    Animate* specialSelect_SW; //11
    Animate* specialSelect_SSW; //12
    Animate* specialSelect_S; //13
    Animate* specialSelect_SSE; //14
    Animate* specialSelect_SE; //15
    Animate* specialSelect_SEE; //16

    //Armed Idle
    Animate* armIdle_E; //1
    Animate* armIdle_NEE; //2
    Animate* armIdle_NE; //3
    Animate* armIdle_NNE; //4
    Animate* armIdle_N; //5
    Animate* armIdle_NNW; //6
    Animate* armIdle_NW; //7
    Animate* armIdle_NWW; //8
    Animate* armIdle_W; //9
    Animate* armIdle_SWW; //10
    Animate* armIdle_SW; //11
    Animate* armIdle_SSW; //12
    Animate* armIdle_S; //13
    Animate* armIdle_SSE; //14
    Animate* armIdle_SE; //15
    Animate* armIdle_SEE; //16

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

    void Initalize(PlayerCharacterStateBase* startingState) {
        currentState = startingState;
        currentState->EnterState();
    }

    void SwitchState(PlayerCharacterStateBase* newState) {
        /*if (currentState == newState) {
            CCLOG("Not change to new State!");
            return;
        }*/
        currentState->ExitState();
        currentState = newState;
        currentState->EnterState();
    }

    Vec2 mouseClickPos;

    float calculateAngle(const Vec2& vectorA, const Vec2& vectorB);

    void handleMove(float deltaTime);

    void onMouseDown(Event* event);

    void update(float dt);

    void addSkill(std::string skillName) {
        auto skill = SkillFactory::createSkill(skillName);
        skill->retain();
        skills.push_back(skill);
        this->addChild(skill);
    }

    void increaseSkillPoint(int pnt) {
        this->skillPoint += pnt;
    };
    void decreaseSkillPoint(int pnt) {
        this->skillPoint -= pnt;
    };
    int getSkillPoint() const { return skillPoint; };

    CREATE_FUNC(PlayerCharacter);

protected:
    std::vector<SkillBase*> skills;
    int skillPoint = 100;
};

#endif // 
