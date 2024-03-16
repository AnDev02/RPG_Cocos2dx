#include "BossDead.h"
#include "Character/Boss/Boss.h"

void BossDead::EnterState() {
	CCLOG("Hello From Dead State");
	if (boss->getCurrentDirection() == 1) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_E));
	}
	if (boss->getCurrentDirection() == 2) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_NEE));
	}
	if (boss->getCurrentDirection() == 3) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_NE));
	}
	if (boss->getCurrentDirection() == 4) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_NNE));
	}
	if (boss->getCurrentDirection() == 5) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_N));
	}
	if (boss->getCurrentDirection() == 6) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_NNW));
	}
	if (boss->getCurrentDirection() == 7) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_NW));
	}
	if (boss->getCurrentDirection() == 8) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_NWW));
	}
	if (boss->getCurrentDirection() == 9) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_W));
	}
	if (boss->getCurrentDirection() == 10) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_SWW));
	}
	if (boss->getCurrentDirection() == 11) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_SW));
	}
	if (boss->getCurrentDirection() == 12) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_SSW));
	}
	if (boss->getCurrentDirection() == 13) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_S));
	}
	if (boss->getCurrentDirection() == 14) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_SSE));
	}
	if (boss->getCurrentDirection() == 15) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_SE));
	}
	if (boss->getCurrentDirection() == 16) {
		boss->getCurrentSprite()->runAction(RepeatForever::create(boss->death_SEE));
	}
	lastDir = boss->getCurrentDirection();
}

void BossDead::ExitState() {

}

void BossDead::UpdateState() {

}

