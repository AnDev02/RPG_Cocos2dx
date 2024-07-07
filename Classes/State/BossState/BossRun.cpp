#include "BossRun.h"
#include "Enemies/Boss/Boss.h"

void BossRun::EnterState() {
	//CCLOG("Hello From Run State");
	if (boss->getCurrentDirection() == 1) {
		boss->getCurrentSprite()->runAction((boss->run_E));
	}

	if (boss->getCurrentDirection() == 2) {
		boss->getCurrentSprite()->runAction((boss->run_NE));
	}

	if (boss->getCurrentDirection() == 3) {
		boss->getCurrentSprite()->runAction((boss->run_N));
	}

	if (boss->getCurrentDirection() == 4) {
		boss->getCurrentSprite()->runAction((boss->run_NW));
	}

	if (boss->getCurrentDirection() == 5) {
		boss->getCurrentSprite()->runAction((boss->run_W));
	}

	if (boss->getCurrentDirection() == 6) {
		boss->getCurrentSprite()->runAction((boss->run_SW));
	}

	if (boss->getCurrentDirection() == 7) {
		boss->getCurrentSprite()->runAction((boss->run_S));
	}

	if (boss->getCurrentDirection() == 8) {
		boss->getCurrentSprite()->runAction((boss->run_SE));
	}

	lastDir = boss->getCurrentDirection();
}

void BossRun::ExitState() {
	if (boss->getCurrentSprite()->getNumberOfRunningActions() > 0)boss->getCurrentSprite()->stopAllActions();
}

void BossRun::UpdateState() {
	if (boss->getCurrentSprite()->getNumberOfRunningActions() == 0) {
		boss->SwitchState(boss->runState);
	}
	if (boss->getPhysicsBody()->getVelocity().x == 0 && boss->getPhysicsBody()->getVelocity().y == 0) {
		if (boss->isTargetInAttackRange) {
			boss->SwitchState(boss->attackState);
		}
		else boss->SwitchState(boss->idleState);
	}

}

