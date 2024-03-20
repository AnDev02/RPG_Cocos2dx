#include "BossIdle.h"
#include "Boss/Boss.h"

void BossIdle::EnterState() {
	CCLOG("Hello From Idle State");
	if (boss->getCurrentDirection() == 1) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_E));
	}
	if (boss->getCurrentDirection() == 2) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_NEE));
	}
	if (boss->getCurrentDirection() == 3) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_NE));
	}
	if (boss->getCurrentDirection() == 4) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_NNE));
	}
	if (boss->getCurrentDirection() == 5) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_N));
	}
	if (boss->getCurrentDirection() == 6) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_NNW));
	}
	if (boss->getCurrentDirection() == 7) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_NW));
	}
	if (boss->getCurrentDirection() == 8) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_NWW));
	}
	if (boss->getCurrentDirection() == 9) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_W));
	}
	if (boss->getCurrentDirection() == 10) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_SWW));
	}
	if (boss->getCurrentDirection() == 11) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_SW));
	}
	if (boss->getCurrentDirection() == 12) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_SSW));
	}
	if (boss->getCurrentDirection() == 13) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_S));
	}
	if (boss->getCurrentDirection() == 14) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_SSE));
	}
	if (boss->getCurrentDirection() == 15) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_SE));
	}
	if (boss->getCurrentDirection() == 16) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->idle_SEE));
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
		boss->SwitchState(boss->runState);
	}
	if (boss->isTargetInAttackRange) {
		boss->SwitchState(boss->attackState);
	}
}

