#include "BossGetHit.h"
#include "Character/Boss/Boss.h"

void BossGetHit::EnterState() {
	CCLOG("Hello From GetHit State");
	if (boss->getCurrentDirection() == 1) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_E));
	}
	if (boss->getCurrentDirection() == 2) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_NEE));
	}
	if (boss->getCurrentDirection() == 3) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_NE));
	}
	if (boss->getCurrentDirection() == 4) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_NNE));
	}
	if (boss->getCurrentDirection() == 5) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_N));
	}
	if (boss->getCurrentDirection() == 6) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_NNW));
	}
	if (boss->getCurrentDirection() == 7) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_NW));
	}
	if (boss->getCurrentDirection() == 8) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_NWW));
	}
	if (boss->getCurrentDirection() == 9) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_W));
	}
	if (boss->getCurrentDirection() == 10) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_SWW));
	}
	if (boss->getCurrentDirection() == 11) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_SW));
	}
	if (boss->getCurrentDirection() == 12) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_SSW));
	}
	if (boss->getCurrentDirection() == 13) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_S));
	}
	if (boss->getCurrentDirection() == 14) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_SSE));
	}
	if (boss->getCurrentDirection() == 15) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_SE));
	}
	if (boss->getCurrentDirection() == 16) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->getHit_SEE));
	}
	lastDir = boss->getCurrentDirection();
}

void BossGetHit::ExitState() {

}

void BossGetHit::UpdateState() {

}

