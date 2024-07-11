#include "BossDead.h"
#include "Enemies/Boss/Boss.h"

void BossDead::EnterState() {
		boss->getPhysicsBody()->setVelocity(Vec2(0, 0));
	Animate* animateResult;
	if (boss->getCurrentDirection() == 1) {
		animateResult = ((boss->death_E));
	}

	if (boss->getCurrentDirection() == 2) {
		animateResult = ((boss->death_NE));
	}

	if (boss->getCurrentDirection() == 3) {
		animateResult = ((boss->death_N));
	}

	if (boss->getCurrentDirection() == 4) {
		animateResult = ((boss->death_NW));
	}

	if (boss->getCurrentDirection() == 5) {
		animateResult = ((boss->death_W));
	}

	if (boss->getCurrentDirection() == 6) {
		animateResult = ((boss->death_SW));
	}

	if (boss->getCurrentDirection() == 7) {
		animateResult = ((boss->death_S));
	}

	if (boss->getCurrentDirection() == 8) {
		animateResult = ((boss->death_SE));
	}

	boss->getCurrentSprite()->runAction(Sequence::create(animateResult, FadeOut::create(1.0), nullptr));
}

void BossDead::ExitState() {

}

void BossDead::UpdateState() {

}

