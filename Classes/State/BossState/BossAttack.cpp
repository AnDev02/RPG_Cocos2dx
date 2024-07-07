#include "BossAttack.h"
#include "Enemies/Boss/Boss.h"

const int ATTACK1 = 1;
const int ATTACK2 = 2;
const int ATTACK3 = 3;
void BossAttack::EnterState() {
	//CCLOG("Hello From Attack State");
    Animate* animateResult;
    if(boss->getPositionX() < boss->target->getPositionX())
    animateResult = boss->attack1_E;
    if (boss->getPositionX() >= boss->target->getPositionX())
        animateResult = boss->attack1_W;
    if (boss->getCurrentDirection() == 1) {
        if(boss->currentCombo == ATTACK1)animateResult = boss->attack1_E;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_E;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_E;
    }
    if (boss->getCurrentDirection() == 2) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_NE;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_NE;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_NE;
    }

    if (boss->getCurrentDirection() == 3) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_N;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_N;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_N;
    }

    if (boss->getCurrentDirection() == 4) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_NW;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_NW;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_NW;
    }

    if (boss->getCurrentDirection() == 5) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_W;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_W;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_W;
    }

    if (boss->getCurrentDirection() == 6) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_SW;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_SW;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_SW;
    }

    if (boss->getCurrentDirection() == 7) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_S;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_S;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_S;
    }

    if (boss->getCurrentDirection() == 8) {
        if (boss->currentCombo == ATTACK1)animateResult = boss->attack1_SE;
        if (boss->currentCombo == ATTACK2)animateResult = boss->attack2_SE;
        if (boss->currentCombo == ATTACK3)animateResult = boss->attack3_SE;
    }

    lastDir = boss->getCurrentDirection();
    boss->getCurrentSprite()->runAction(cocos2d::Sequence::create(
        cocos2d::CallFunc::create([this]() {
            float amountDamage = boss->getDamage() + 100.0f * (boss->currentCombo - 1);
            if(boss->getPosition().distance(boss->target->getPosition()) <= 50)
            boss->getCurrentTarget()->takeDamage(amountDamage);
            }),
        animateResult,
        cocos2d::CallFunc::create([this]() {
            
            // Khi animation kt thc, chuyn trng thi v trng thi trc 
            boss->currentCombo++;
            auto bossName = boss->getName();
           // CCLOG("BOSS NAME: %s", bossName);
            if (bossName == "Okyanus" || bossName == "HellBeast") {
                if (boss->currentCombo == 4) {
                    boss->currentCombo = 1;
                }
            }
            else if (bossName == "Paradiso") {
                if (boss->currentCombo == 3) {
                    boss->currentCombo = 1;
                }
            }
            //Running
            if (boss->getPhysicsBody()->getVelocity().y != 0 || boss->getPhysicsBody()->getVelocity().x != 0) {
                boss->currentCombo = 1;
                boss->SwitchState(boss->walkState);
            }
            //Idle
            if (boss->getPhysicsBody()->getVelocity().y == 0 && boss->getPhysicsBody()->getVelocity().x == 0) {
                if (boss->isTargetInAttackRange) { 
                    boss->SwitchState(boss->attackState); 
                }
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
   // CCLOG("Updating for Boss");
    
}

