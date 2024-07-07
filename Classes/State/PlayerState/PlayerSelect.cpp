#include "PlayerSelect.h"
#include "Player/Player.h"

void PlayerSelect::EnterState() {
	Animate* animateResult;
	if (player->getCurrentDirection() == 1) {
		animateResult = ((player->specialSelect_E));
	}
	if (player->getCurrentDirection() == 2) {
		animateResult = ((player->specialSelect_NE));
	}

	if (player->getCurrentDirection() == 3) {
		animateResult = ((player->specialSelect_N));
	}

	if (player->getCurrentDirection() == 4) {
		animateResult = ((player->specialSelect_NW));
	}

	if (player->getCurrentDirection() == 5) {
		animateResult = ((player->specialSelect_W));
	}

	if (player->getCurrentDirection() == 6) {
		animateResult = ((player->specialSelect_SW));
	}

	if (player->getCurrentDirection() == 7) {
		animateResult = ((player->specialSelect_S));
	}

	if (player->getCurrentDirection() == 8) {
		animateResult = ((player->specialSelect_SE));
	}

	lastDir = player->getCurrentDirection();

	player->getCurrentSprite()->runAction(Sequence::create(animateResult, 
		 cocos2d::CallFunc::create([this]() {

			if (player->isMoving()) {
				player->SwitchState(player->walkState);
			}
			if (!player->isMoving()) {
				player->SwitchState(player->idleState);
			}

			}), nullptr));

}

void PlayerSelect::ExitState() {
	if (player->getNumberOfRunningActions() > 0)player->getCurrentSprite()->stopAllActions();
}

void PlayerSelect::UpdateState() {
	//if (player->isMoving()) {
	//	player->SwitchState(player->walkState);
	//}
	//if (!player->isMoving()) {
	//	player->SwitchState(player->idleState);
	//}
}

