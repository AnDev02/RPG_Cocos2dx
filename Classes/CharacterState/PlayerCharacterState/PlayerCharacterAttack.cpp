#include "PlayerCharacterAttack.h"
#include "Character/PlayerCharacter/PlayerCharacter.h"

void PlayerCharacterAttack::EnterState() {
    CCLOG("Hello From Attack State");
    Animate* animateResult;
    if (playerCharacter->getCurrentDirection() == 1) {
        animateResult = playerCharacter->armAttack_E;
    }
    if (playerCharacter->getCurrentDirection() == 2) {
        animateResult = playerCharacter->armAttack_NEE;
    }
    if (playerCharacter->getCurrentDirection() == 3) {
        animateResult = playerCharacter->armAttack_NE;
    }
    if (playerCharacter->getCurrentDirection() == 4) {
        animateResult = playerCharacter->armAttack_NNE;
    }
    if (playerCharacter->getCurrentDirection() == 5) {
        animateResult = playerCharacter->armAttack_N;
    }
    if (playerCharacter->getCurrentDirection() == 6) {
        animateResult = playerCharacter->armAttack_NNW;
    }
    if (playerCharacter->getCurrentDirection() == 7) {
        animateResult = playerCharacter->armAttack_NW;
    }
    if (playerCharacter->getCurrentDirection() == 8) {
        animateResult = playerCharacter->armAttack_NWW;
    }
    if (playerCharacter->getCurrentDirection() == 9) {
        animateResult = playerCharacter->armAttack_W;
    }
        if (playerCharacter->getCurrentDirection() == 10) {
            animateResult = playerCharacter->armAttack_SWW;
        }
        if (playerCharacter->getCurrentDirection() == 11) {
            animateResult = playerCharacter->armAttack_SW;
        }
        if (playerCharacter->getCurrentDirection() == 12) {
            animateResult = playerCharacter->armAttack_SSW;
        }
        if (playerCharacter->getCurrentDirection() == 13) {
            animateResult = playerCharacter->armAttack_S;
        }
        if (playerCharacter->getCurrentDirection() == 14) {
            animateResult = playerCharacter->armAttack_SSE;
        }
        if (playerCharacter->getCurrentDirection() == 15) {
            animateResult = playerCharacter->armAttack_SE;
        }
        if (playerCharacter->getCurrentDirection() == 16) {
            animateResult = playerCharacter->armAttack_SEE;
        }
        lastDir = playerCharacter->getCurrentDirection();
        playerCharacter->getCurrentSprite()->runAction(cocos2d::Sequence::create(
            animateResult,
            cocos2d::CallFunc::create([this]() {
                // Khi animation kết thúc, chuyển trạng thái về trạng thái trước đó
                //Running
                if (playerCharacter->getPhysicsBody()->getVelocity().y != 0 || playerCharacter->getPhysicsBody()->getVelocity().x != 0)playerCharacter->SwitchState(playerCharacter->walkState);
                //Idle
                if (playerCharacter->getPhysicsBody()->getVelocity().y == 0 && playerCharacter->getPhysicsBody()->getVelocity().x == 0)playerCharacter->SwitchState(playerCharacter->idleState);
                }),
            nullptr
        ));

}

void PlayerCharacterAttack::ExitState() {
	
}

void PlayerCharacterAttack::UpdateState() {


}

