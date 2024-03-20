#include "BossWalk.h"
#include "Boss/Boss.h"

void BossWalk::EnterState() {
	CCLOG("Hello From Walk State");
	if (boss->getCurrentDirection() == 1) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_E));
	}
	if (boss->getCurrentDirection() == 2) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_NEE));
	}
	if (boss->getCurrentDirection() == 3) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_NE));
	}
	if (boss->getCurrentDirection() == 4) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_NNE));
	}
	if (boss->getCurrentDirection() == 5) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_N));
	}
	if (boss->getCurrentDirection() == 6) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_NNW));
	}
	if (boss->getCurrentDirection() == 7) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_NW));
	}
	if (boss->getCurrentDirection() == 8) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_NWW));
	}
	if (boss->getCurrentDirection() == 9) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_W));
	}
	if (boss->getCurrentDirection() == 10) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_SWW));
	}
	if (boss->getCurrentDirection() == 11) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_SW));
	}
	if (boss->getCurrentDirection() == 12) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_SSW));
	}
	if (boss->getCurrentDirection() == 13) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_S));
	}
	if (boss->getCurrentDirection() == 14) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_SSE));
	}
	if (boss->getCurrentDirection() == 15) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_SE));
	}
	if (boss->getCurrentDirection() == 16) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->walk_SEE));
	}
	lastDir = boss->getCurrentDirection();
}

void BossWalk::ExitState() {

}

void BossWalk::UpdateState() {

}

