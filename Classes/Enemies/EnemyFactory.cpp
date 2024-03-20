#include "EnemyFactory.h"

Enemy* EnemyFactory::createEnemy(std::string enemyType) {
	Enemy* result = nullptr;

	if (enemyType == "Skeleton") {
		result = Skeleton::create();
	}
	else if (enemyType == "Slime") {
		result = Slime::create();
	}
	if (enemyType == "ShadowLord") {
		result = ShadowLord::create();
	}

	return result;
}