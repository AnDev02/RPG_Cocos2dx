#include "PlayerCharacterDead.h"
#include "PlayerCharacters/PlayerCharacter.h"

void PlayerCharacterDead::EnterState() {
	CCLOG("Hello From Dead State");

}

void PlayerCharacterDead::ExitState() {
	if (playerCharacter->getNumberOfRunningActions() > 0)playerCharacter->getCurrentSprite()->stopAllActions();
}

void PlayerCharacterDead::UpdateState() {


}

