#include "BossRoar.h"
#include "Character/Boss/Boss.h"

void BossRoar::EnterState() {
	CCLOG("Hello From Roar State");
	Animate* animateResult;
	if (boss->getCurrentDirection() == 1) {
		animateResult = boss->roar_E;
	}
	if (boss->getCurrentDirection() == 2) {
		animateResult = boss->roar_NEE;
	}
	if (boss->getCurrentDirection() == 3) {
		animateResult = boss->roar_NE;
	}
	if (boss->getCurrentDirection() == 4) {
		animateResult = boss->roar_NNE;
	}
	if (boss->getCurrentDirection() == 5) {
		animateResult = boss->roar_N;
	}
	if (boss->getCurrentDirection() == 6) {
		animateResult = boss->roar_NNW;
	}
	if (boss->getCurrentDirection() == 7) {
		animateResult = boss->roar_NW;
	}
	if (boss->getCurrentDirection() == 8) {
		animateResult = boss->roar_NWW;
	}
	if (boss->getCurrentDirection() == 9) {
		animateResult = boss->roar_W;
	}
	if (boss->getCurrentDirection() == 10) {
		animateResult = boss->roar_SWW;
	}
	if (boss->getCurrentDirection() == 11) {
		animateResult = boss->roar_SW;
	}
	if (boss->getCurrentDirection() == 12) {
		animateResult = boss->roar_SSW;
	}
	if (boss->getCurrentDirection() == 13) {
		animateResult = boss->roar_S;
	}
	if (boss->getCurrentDirection() == 14) {
		animateResult = boss->roar_SSE;
	}
	if (boss->getCurrentDirection() == 15) {
		animateResult = boss->roar_SE;
	}
	if (boss->getCurrentDirection() == 16) {
		animateResult = boss->roar_SEE;
	}
	lastDir = boss->getCurrentDirection();

	boss->getCurrentSprite()->runAction(cocos2d::Sequence::create(
		animateResult,
		cocos2d::CallFunc::create([this]() {
			if (boss->getPhysicsBody()->getVelocity().x != 0 || boss->getPhysicsBody()->getVelocity().y != 0)boss->SwitchState(boss->runState);
			if (boss->getPhysicsBody()->getVelocity().x == 0 && boss->getPhysicsBody()->getVelocity().y == 0)boss->SwitchState(boss->idleState);
			}),
		nullptr
	));
}

void BossRoar::ExitState() {
	if (boss->getCurrentSprite()->getNumberOfRunningActions() > 0)boss->getCurrentSprite()->stopAllActions();
}

void BossRoar::UpdateState() {

}

