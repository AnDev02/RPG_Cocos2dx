#include "PlayerCharacterFactory.h"

PlayerCharacter* PlayerCharacterFactory::createPlayerCharacter(std::string playerType) {
	PlayerCharacter* result = nullptr;

	if (playerType == "Knight") {
		result = Knight::create();
	}
	else if (playerType == "Fighter") {
		result = Fighter::create();
	}
	if (playerType == "Warrior") {
		result = Warrior::create();
	}

	return result;
}