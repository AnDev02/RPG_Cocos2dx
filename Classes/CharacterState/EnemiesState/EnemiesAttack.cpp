#include "EnemiesAttack.h"
#include "Character/Enemy/Enemies.h"

void EnemiesAttack::EnterState() {
	CCLOG("Hello From Attack State");
	if (enemies->getCurrentDirection() == 1) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_E));
	}
	if (enemies->getCurrentDirection() == 2) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_NEE));
	}
	if (enemies->getCurrentDirection() == 3) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_NE));
	}
	if (enemies->getCurrentDirection() == 4) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_NNE));
	}
	if (enemies->getCurrentDirection() == 5) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_N));
	}
	if (enemies->getCurrentDirection() == 6) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_NNW));
	}
	if (enemies->getCurrentDirection() == 7) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_NW));
	}
	if (enemies->getCurrentDirection() == 8) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_NWW));
	}
	if (enemies->getCurrentDirection() == 9) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_W));
	}
	if (enemies->getCurrentDirection() == 10) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_SWW));
	}
	if (enemies->getCurrentDirection() == 11) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_SW));
	}
	if (enemies->getCurrentDirection() == 12) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_SSW));
	}
	if (enemies->getCurrentDirection() == 13) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_S));
	}
	if (enemies->getCurrentDirection() == 14) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_SSE));
	}
	if (enemies->getCurrentDirection() == 15) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_SE));
	}
	if (enemies->getCurrentDirection() == 16) {
		enemies->getCurrentSprite()->runAction((enemies->defaultAttack_SEE));
	}
}

void EnemiesAttack::ExitState() {

}

void EnemiesAttack::UpdateState() {

}

