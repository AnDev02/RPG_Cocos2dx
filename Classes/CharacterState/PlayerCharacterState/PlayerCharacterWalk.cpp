#include "PlayerCharacterWalk.h"
#include "Character/PlayerCharacter/PlayerCharacter.h"

void PlayerCharacterWalk::EnterState() {
	CCLOG("Hello From Walk State");
	if (playerCharacter->getCurrentDirection() == 1) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_E));
	}
	if (playerCharacter->getCurrentDirection() == 2) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_NEE));
	}
	if (playerCharacter->getCurrentDirection() == 3) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_NE));
	}
	if (playerCharacter->getCurrentDirection() == 4) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_NNE));
	}
	if (playerCharacter->getCurrentDirection() == 5) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_N));
	}
	if (playerCharacter->getCurrentDirection() == 6) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_NNW));
	}
	if (playerCharacter->getCurrentDirection() == 7) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_NW));
	}
	if (playerCharacter->getCurrentDirection() == 8) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_NWW));
	}
	if (playerCharacter->getCurrentDirection() == 9) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_W));
	}
	if (playerCharacter->getCurrentDirection() == 10) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_SWW));
	}
	if (playerCharacter->getCurrentDirection() == 11) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_SW));
	}
	if (playerCharacter->getCurrentDirection() == 12) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_SSW));
	}
	if (playerCharacter->getCurrentDirection() == 13) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_S));
	}
	if (playerCharacter->getCurrentDirection() == 14) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_SSE));
	}
	if (playerCharacter->getCurrentDirection() == 15) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_SE));
	}
	if (playerCharacter->getCurrentDirection() == 16) {
		playerCharacter->getCurrentSprite()->runAction(RepeatForever::create(playerCharacter->armWalk_SEE));
	}
	lastDir = playerCharacter->getCurrentDirection();

}

void PlayerCharacterWalk::ExitState() {
	if (playerCharacter->getCurrentSprite()->getNumberOfRunningActions() > 0)playerCharacter->getCurrentSprite()->stopAllActions();
}

void PlayerCharacterWalk::UpdateState() {
	if (lastDir != playerCharacter->getCurrentDirection()) {
		playerCharacter->SwitchState(playerCharacter->walkState);
	}
	if (playerCharacter->getPhysicsBody()->getVelocity().x == 0 && playerCharacter->getPhysicsBody()->getVelocity().y == 0) {
		playerCharacter->SwitchState(playerCharacter->idleState);
	}

}

