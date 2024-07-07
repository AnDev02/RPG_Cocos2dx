#include "BossIdle.h"
#include "Enemies/Boss/Boss.h"

void BossIdle::EnterState() {
	//CCLOG("Hello From Idle State");
	if (boss->getCurrentDirection() == 1) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_E));
	}
	if (boss->getCurrentDirection() == 2) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_NE));
	}

	if (boss->getCurrentDirection() == 3) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_N));
	}

	if (boss->getCurrentDirection() == 4) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_NW));
	}

	if (boss->getCurrentDirection() == 5) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_W));
	}

	if (boss->getCurrentDirection() == 6) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_SW));
	}

	if (boss->getCurrentDirection() == 7) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_S));
	}

	if (boss->getCurrentDirection() == 8) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_SE));
	}

	lastDir = boss->getCurrentDirection();
}

void BossIdle::ExitState() {
	if (boss->getCurrentSprite()->getNumberOfRunningActions() > 0)boss->getCurrentSprite()->stopAllActions();
}


void BossIdle::UpdateState() {
	if (lastDir != boss->getCurrentDirection()) {
		boss->SwitchState(boss->idleState);
	}
	if (boss->getPhysicsBody()->getVelocity().x != 0 || boss->getPhysicsBody()->getVelocity().y != 0) {
		boss->SwitchState(boss->walkState);
	}
	if (boss->isTargetInAttackRange) {
		boss->SwitchState(boss->attackState);
	}
}

