#include "BossAngry.h"
#include "Enemies/Boss/Boss.h"

void BossAngry::EnterState() {
	//CCLOG("Hello From Angry State");
	Animate* animateResult;
	if (boss->getCurrentDirection() == 1) {
		animateResult = boss->angry_E;
	}
	if (boss->getCurrentDirection() == 2) {
		animateResult = boss->angry_NE;
	}
	if (boss->getCurrentDirection() == 3) {
		animateResult = boss->angry_N;
	}
	if (boss->getCurrentDirection() == 4) {
		animateResult = boss->angry_NW;
	}
	if (boss->getCurrentDirection() == 5) {
		animateResult = boss->angry_W;
	}
	if (boss->getCurrentDirection() == 6) {
		animateResult = boss->angry_SW;
	}
	if (boss->getCurrentDirection() == 7) {
		animateResult = boss->angry_S;
	}
	if (boss->getCurrentDirection() == 8) {
		animateResult = boss->angry_SE;
	}
	lastDir = boss->getCurrentDirection();

	boss->getCurrentSprite()->runAction(cocos2d::Sequence::create(
		animateResult,
		cocos2d::CallFunc::create([this]() {
			if (boss->getPhysicsBody()->getVelocity().x == 0 && boss->getPhysicsBody()->getVelocity().y == 0)boss->SwitchState(boss->idleState);
			}),
		nullptr
	));
}

void BossAngry::ExitState() {
	if (boss->getCurrentSprite()->getNumberOfRunningActions() > 0)boss->getCurrentSprite()->stopAllActions();
}

void BossAngry::UpdateState() {

}

