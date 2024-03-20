#include "PlayerCharacterIdle.h"
#include "PlayerCharacters/PlayerCharacter.h"

void PlayerCharacterIdle::EnterState() {
	CCLOG("Hello From Idle State");
	if (playerCharacter->getCurrentDirection() == 1) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_E));
	}
	if (playerCharacter->getCurrentDirection() == 2) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_NEE));
	}
	if (playerCharacter->getCurrentDirection() == 3) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_NE));
	}
	if (playerCharacter->getCurrentDirection() == 4) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_NNE));
	}
	if (playerCharacter->getCurrentDirection() == 5) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_N));
	}
	if (playerCharacter->getCurrentDirection() == 6) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_NNW));
	}
	if (playerCharacter->getCurrentDirection() == 7) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_NW));
	}
	if (playerCharacter->getCurrentDirection() == 8) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_NWW));
	}
	if (playerCharacter->getCurrentDirection() == 9) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_W));
	}
	if (playerCharacter->getCurrentDirection() == 10) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_SWW));
	}
	if (playerCharacter->getCurrentDirection() == 11) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_SW));
	}
	if (playerCharacter->getCurrentDirection() == 12) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_SSW));
	}
	if (playerCharacter->getCurrentDirection() == 13) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_S));	
	}
	if (playerCharacter->getCurrentDirection() == 14) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_SSE));
	}
	if (playerCharacter->getCurrentDirection() == 15) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_SE));
	}
	if (playerCharacter->getCurrentDirection() == 16) {
		playerCharacter->getCurrentSprite()->runAction((playerCharacter->armIdle_SEE));
	}
	lastDir = playerCharacter->getCurrentDirection();
}

void PlayerCharacterIdle::ExitState() {
	if (playerCharacter->getNumberOfRunningActions() > 0)playerCharacter->getCurrentSprite()->stopAllActions();
}

void PlayerCharacterIdle::UpdateState() {
	if (lastDir != playerCharacter->getCurrentDirection()) {
		playerCharacter->SwitchState(playerCharacter->idleState);
	}
	if (playerCharacter->getPhysicsBody()->getVelocity().x != 0 || playerCharacter->getPhysicsBody()->getVelocity().y != 0) {
		playerCharacter->SwitchState(playerCharacter->walkState);
	}
}

