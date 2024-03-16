#include "EnemiesIdle.h"
#include "Character/Enemy/Enemies.h"

void EnemiesIdle::EnterState() {
	CCLOG("Hello From Idle State");
	if (enemies->getCurrentDirection() == 1) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_E));
	}
	if (enemies->getCurrentDirection() == 2) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_NEE));
	}
	if (enemies->getCurrentDirection() == 3) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_NE));
	}
	if (enemies->getCurrentDirection() == 4) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_NNE));
	}
	if (enemies->getCurrentDirection() == 5) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_N));
	}
	if (enemies->getCurrentDirection() == 6) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_NNW));
	}
	if (enemies->getCurrentDirection() == 7) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_NW));
	}
	if (enemies->getCurrentDirection() == 8) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_NWW));
	}
	if (enemies->getCurrentDirection() == 9) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_W));
	}
	if (enemies->getCurrentDirection() == 10) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_SWW));
	}
	if (enemies->getCurrentDirection() == 11) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_SW));
	}
	if (enemies->getCurrentDirection() == 12) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_SSW));
	}
	if (enemies->getCurrentDirection() == 13) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_S));
	}
	if (enemies->getCurrentDirection() == 14) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_SSE));
	}
	if (enemies->getCurrentDirection() == 15) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_SE));
	}
	if (enemies->getCurrentDirection() == 16) {
		enemies->getCurrentSprite()->runAction((enemies->defaultIdle_SEE));
	}
	lastDir = enemies->getCurrentDirection();
}

void EnemiesIdle::ExitState() {
	if (enemies->getCurrentSprite()->getNumberOfRunningActions() > 0)enemies->getCurrentSprite()->stopAllActions();
}

void EnemiesIdle::UpdateState() {
	if (lastDir != enemies->getCurrentDirection()) {
		enemies->SwitchState(enemies->idleState);
	}
	if (enemies->getPhysicsBody()->getVelocity().x != 0 || enemies->getPhysicsBody()->getVelocity().y != 0) {
		enemies->SwitchState(enemies->walkState);
	}
}

