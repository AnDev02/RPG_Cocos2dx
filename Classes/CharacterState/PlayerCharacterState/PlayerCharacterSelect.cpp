﻿#include "PlayerCharacterSelect.h"
#include "Character/PlayerCharacter/PlayerCharacter.h"

void PlayerCharacterSelect::EnterState() {
	CCLOG("Hello From Select State");

}

void PlayerCharacterSelect::ExitState() {
	if (playerCharacter->getNumberOfRunningActions() > 0)playerCharacter->stopAllActions();
}

void PlayerCharacterSelect::UpdateState() {


}

