#include "NormalMonsterIdle.h"
#include "Enemies/NormalMonster/NormalMonster.h"

void NormalMonsterIdle::EnterState() {
	//CCLOG("Hello From Idle State");
		if (normalMonster->getCurrentDirection() == 1) {
			normalMonster->getCurrentSprite()->runAction((normalMonster->defaultIdle_E));
		}

		if (normalMonster->getCurrentDirection() == 2) {
			normalMonster->getCurrentSprite()->runAction((normalMonster->defaultIdle_NE));
		}

		if (normalMonster->getCurrentDirection() == 3) {
			normalMonster->getCurrentSprite()->runAction((normalMonster->defaultIdle_N));
		}

		if (normalMonster->getCurrentDirection() == 4) {
			normalMonster->getCurrentSprite()->runAction((normalMonster->defaultIdle_NW));
		}

		if (normalMonster->getCurrentDirection() == 5) {
			normalMonster->getCurrentSprite()->runAction((normalMonster->defaultIdle_W));
		}

		if (normalMonster->getCurrentDirection() == 6) {
			normalMonster->getCurrentSprite()->runAction((normalMonster->defaultIdle_SW));
		}

		if (normalMonster->getCurrentDirection() == 7) {
			normalMonster->getCurrentSprite()->runAction((normalMonster->defaultIdle_S));
		}

		if (normalMonster->getCurrentDirection() == 8) {
			normalMonster->getCurrentSprite()->runAction((normalMonster->defaultIdle_SE));
		}

		lastDir = normalMonster->getCurrentDirection();
}

void NormalMonsterIdle::ExitState() {
		if (normalMonster->getCurrentSprite()->getNumberOfRunningActions() > 0)normalMonster->getCurrentSprite()->stopAllActions();
}

void NormalMonsterIdle::UpdateState() {
		if (lastDir != normalMonster->getCurrentDirection()) {
			if (normalMonster->isTargetInAttackRange && normalMonster->attackState)normalMonster->SwitchState(normalMonster->attackState);
			normalMonster->SwitchState(normalMonster->idleState);
		}
		if (normalMonster->getPhysicsBody()->getVelocity().x != 0 || normalMonster->getPhysicsBody()->getVelocity().y != 0) {
			normalMonster->SwitchState(normalMonster->walkState);
		}
		//if (normalMonster->getCurrentHP() <= 0) {
		//	normalMonster->die();
		//}
}

