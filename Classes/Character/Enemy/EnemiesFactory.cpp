#include "EnemiesFactory.h"


Enemies* EnemiesFactory::createEnemies(std::string enemiesType) {
	Enemies* result = nullptr;

	if (enemiesType == "Skeleton") {
		result = Skeleton::create();
	}
	else if (enemiesType == "Slime") {
		result = Slime::create();
	}
	if (enemiesType == "ShadowLord") {
		result = ShadowLord::create();
	}

	return result;
}