#include "BossAttack.h"
#include "Boss/Boss.h"

const int ATTACK1 = 1;
const int ATTACK2 = 2;
const int ATTACK3 = 3;
void BossAttack::EnterState() {
	CCLOG("Hello From Attack State");
    Animate* animateResult;
    if (boss->getCurrentDirection() == 1) {
        if(boss->currentCombo == ATTACK1)animateResult = boss->attack1_E;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_E;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_E;
    }
    if (boss->getCurrentDirection() == 2) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_NEE;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_NEE;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_NEE;
    }
    if (boss->getCurrentDirection() == 3) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_NE;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_NE;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_NE;
    }
    if (boss->getCurrentDirection() == 4) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_NNE;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_NNE;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_NNE;
    }
    if (boss->getCurrentDirection() == 5) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_N;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_N;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_N;
    }
    if (boss->getCurrentDirection() == 6) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_NNW;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_NNW;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_NNW;
    }
    if (boss->getCurrentDirection() == 7) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_NW;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_NW;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_NW;
    }
    if (boss->getCurrentDirection() == 8) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_NWW;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_NWW;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_NWW;
    }
    if (boss->getCurrentDirection() == 9) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_W;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_W;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_W;
    }
    if (boss->getCurrentDirection() == 10) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_SWW;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_SWW;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_SWW;
    }
    if (boss->getCurrentDirection() == 11) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_SW;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_SW;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_SW;
    }
    if (boss->getCurrentDirection() == 12) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_SSW;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_SSW;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_SSW;
    }
    if (boss->getCurrentDirection() == 13) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_S;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_S;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_S;
    }
    if (boss->getCurrentDirection() == 14) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_SSE;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_SSE;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_SSE;
    }
    if (boss->getCurrentDirection() == 15) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_SE;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_SE;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_SE;
    }
    if (boss->getCurrentDirection() == 16) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_SEE;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_SEE;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_SEE;
    }
    lastDir = boss->getCurrentDirection();
    boss->getCurrentSprite()->runAction(cocos2d::Sequence::create(
        animateResult,
        cocos2d::CallFunc::create([this]() {
            // Khi animation kết thúc, chuyển trạng thái về trạng thái trước đó
            boss->currentCombo++;
            if (boss->currentCombo == 4) {
                boss->currentCombo = 1;
            }
            //Running
            if (boss->getPhysicsBody()->getVelocity().y != 0 || boss->getPhysicsBody()->getVelocity().x != 0) {
                boss->currentCombo = 1;
                boss->SwitchState(boss->runState);
            }
            //Idle
            if (boss->getPhysicsBody()->getVelocity().y == 0 && boss->getPhysicsBody()->getVelocity().x == 0) {
                if (boss->isTargetInAttackRange)boss->SwitchState(boss->attackState);
                else {
                    boss->currentCombo = 1;
                    boss->SwitchState(boss->idleState);
                }
            }
            }),
        nullptr
    ));
}

void BossAttack::ExitState() {

}

void BossAttack::UpdateState() {
    CCLOG("Updating for Boss");
    
}

