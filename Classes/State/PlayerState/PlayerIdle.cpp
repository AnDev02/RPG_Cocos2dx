#include "PlayerIdle.h"
#include "Player/Player.h"

void PlayerIdle::EnterState() {
	//CCLOG("Hello From Idle State");
	if (player->getCurrentDirection() == 1) {
		player->getCurrentSprite()->runAction((player->armIdle_E));
	}
	if (player->getCurrentDirection() == 2) {
		player->getCurrentSprite()->runAction((player->armIdle_NE));
	}

	if (player->getCurrentDirection() == 3) {
		player->getCurrentSprite()->runAction((player->armIdle_N));
	}

	if (player->getCurrentDirection() == 4) {
		player->getCurrentSprite()->runAction((player->armIdle_NW));
	}

	if (player->getCurrentDirection() == 5) {
		player->getCurrentSprite()->runAction((player->armIdle_W));
	}

	if (player->getCurrentDirection() == 6) {
		player->getCurrentSprite()->runAction((player->armIdle_SW));
	}

	if (player->getCurrentDirection() == 7) {
		player->getCurrentSprite()->runAction((player->armIdle_S));	
	}

	if (player->getCurrentDirection() == 8) {
		player->getCurrentSprite()->runAction((player->armIdle_SE));
	}

	lastDir = player->getCurrentDirection();
}

void PlayerIdle::ExitState() {
	if (player->getNumberOfRunningActions() > 0)player->getCurrentSprite()->stopAllActions();
}

void PlayerIdle::UpdateState() {
	if (lastDir != player->getCurrentDirection()) {
		player->SwitchState(player->idleState);
	}
	if (player->isMoving()) {
		player->SwitchState(player->walkState);
	}
}

