#include "BossFactory.h"

Boss* BossFactory::createBoss(std::string bossType) {
	Boss* result = nullptr;

	if (bossType == "HellBeast") {
		result = HellBeast::create();
	}
	
	return result;
}