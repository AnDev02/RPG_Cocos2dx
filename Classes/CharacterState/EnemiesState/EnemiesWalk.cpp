#include "EnemiesWalk.h"
#include "Character/Enemy/Enemies.h"

void EnemiesWalk::EnterState() {
	CCLOG("Hello From Walk State");
	if (enemies->getCurrentDirection() == 1) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_E));
	}
	if (enemies->getCurrentDirection() == 2) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_NEE));
	}
	if (enemies->getCurrentDirection() == 3) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_NE));
	}
	if (enemies->getCurrentDirection() == 4) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_NNE));
	}
	if (enemies->getCurrentDirection() == 5) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_N));
	}
	if (enemies->getCurrentDirection() == 6) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_NNW));
	}
	if (enemies->getCurrentDirection() == 7) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_NW));
	}
	if (enemies->getCurrentDirection() == 8) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_NWW));
	}
	if (enemies->getCurrentDirection() == 9) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_W));
	}
	if (enemies->getCurrentDirection() == 10) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_SWW));
	}
	if (enemies->getCurrentDirection() == 11) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_SW));
	}
	if (enemies->getCurrentDirection() == 12) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_SSW));
	}
	if (enemies->getCurrentDirection() == 13) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_S));
	}
	if (enemies->getCurrentDirection() == 14) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_SSE));
	}
	if (enemies->getCurrentDirection() == 15) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_SE));
	}
	if (enemies->getCurrentDirection() == 16) {
		enemies->getCurrentSprite()->runAction(RepeatForever::create(enemies->defaultWalk_SEE));
	}
	lastDir = enemies->getCurrentDirection();
}

void EnemiesWalk::ExitState() {
	if (enemies->getCurrentSprite()->getNumberOfRunningActions() > 0)enemies->getCurrentSprite()->stopAllActions();
}

void EnemiesWalk::UpdateState() {
	if (lastDir != enemies->getCurrentDirection()) {
		enemies->SwitchState(enemies->walkState);
	}
	if (enemies->getPhysicsBody()->getVelocity().x == 0 && enemies->getPhysicsBody()->getVelocity().y == 0) {
		enemies->SwitchState(enemies->idleState);
	}
}

