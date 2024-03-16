#include "BossRun.h"
#include "Character/Boss/Boss.h"

void BossRun::EnterState() {
	CCLOG("Hello From Run State");
	if (boss->getCurrentDirection() == 1) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_E));
	}
	if (boss->getCurrentDirection() == 2) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_NEE));
	}
	if (boss->getCurrentDirection() == 3) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_NE));
	}
	if (boss->getCurrentDirection() == 4) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_NNE));
	}
	if (boss->getCurrentDirection() == 5) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_N));
	}
	if (boss->getCurrentDirection() == 6) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_NNW));
	}
	if (boss->getCurrentDirection() == 7) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_NW));
	}
	if (boss->getCurrentDirection() == 8) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_NWW));
	}
	if (boss->getCurrentDirection() == 9) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_W));
	}
	if (boss->getCurrentDirection() == 10) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_SWW));
	}
	if (boss->getCurrentDirection() == 11) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_SW));
	}
	if (boss->getCurrentDirection() == 12) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_SSW));
	}
	if (boss->getCurrentDirection() == 13) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_S));
	}
	if (boss->getCurrentDirection() == 14) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_SSE));
	}
	if (boss->getCurrentDirection() == 15) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_SE));
	}
	if (boss->getCurrentDirection() == 16) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->run_SEE));
	}
	lastDir = boss->getCurrentDirection();
}

void BossRun::ExitState() {
	if (boss->getCurrentSprite()->getNumberOfRunningActions() > 0)boss->getCurrentSprite()->stopAllActions();
}

void BossRun::UpdateState() {
	if (lastDir != boss->getCurrentDirection()) {
		boss->SwitchState(boss->runState);
	}
	if (boss->getPhysicsBody()->getVelocity().x == 0 && boss->getPhysicsBody()->getVelocity().y == 0) {
		if (boss->isTargetInAttackRange) {
			boss->SwitchState(boss->attackState);
		}
		else boss->SwitchState(boss->idleState);
	}

}

