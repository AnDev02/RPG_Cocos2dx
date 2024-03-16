#include "PlayerCharacterDead.h"
#include "Character/PlayerCharacter/PlayerCharacter.h"

void PlayerCharacterDead::EnterState() {
	CCLOG("Hello From Dead State");

}

void PlayerCharacterDead::ExitState() {
	if (playerCharacter->getNumberOfRunningActions() > 0)playerCharacter->getCurrentSprite()->stopAllActions();
}

void PlayerCharacterDead::UpdateState() {


}

