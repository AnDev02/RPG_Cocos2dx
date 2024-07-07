#include "PlayerAttack.h"
#include "Player/Player.h"
#include "Enemies/Enemy.h"
#include "HelloWorldScene.h"
#include "Map/Map.h"
#include "AudioEngine.h"
#include "Audio/AudioEngine.h"
#include "SettingsManager/SettingsData.h"
void PlayerAttack::EnterState() {
    // CCLOG("Hello From Attack State");
    Animate* animateResult;
    UserDefault::getInstance()->setIntegerForKey("slash_sound", Audio::getInstance()->play2d("sound/sounds effect/slash_sound.mp3", false, SettingsData::getInstance()->getSoundSlider() / 100.0f));

    if (player->getCurrentDirection() == 1) {
        animateResult = player->armAttack_E;
    }
    if (player->getCurrentDirection() == 2) {
        animateResult = player->armAttack_NE;
    }
    if (player->getCurrentDirection() == 3) {
        animateResult = player->armAttack_N;
    }
    if (player->getCurrentDirection() == 4) {
        animateResult = player->armAttack_NW;
    }
    if (player->getCurrentDirection() == 5) {
        animateResult = player->armAttack_W;
    }
    if (player->getCurrentDirection() == 6) {
        animateResult = player->armAttack_SW;
    }
    if (player->getCurrentDirection() == 7) {
        animateResult = player->armAttack_S;
    }

    if (player->getCurrentDirection() == 8) {
        animateResult = player->armAttack_SE;
    }
    lastDir = player->getCurrentDirection();
    player->getCurrentSprite()->runAction(cocos2d::Sequence::create(
        cocos2d::CallFunc::create([this]() {
            // Ly scene chnh t Director
            Scene* currentScene = Director::getInstance()->getRunningScene();
            if (currentScene) {
                Game* game = dynamic_cast<Game*>(currentScene->getChildByName("GameInstance"));
                if (game) {
                    auto children = game->gameMap->getTiledMap()->getChildren();
                    for (const auto& child : children) {
                        // Kim tra xem i tng con c phi l Player khng
                        auto enemy = dynamic_cast<Enemy*>(child);
                        if (enemy) {

                            int dirResult = 0;
                            Vec2 direction = enemy->getPosition() - player->getPosition();
                            direction.normalize();

                            float angleResult = calculateAngle(direction, Vec2(1, 0));

                            if (angleResult >= -45 && angleResult < 0) { dirResult = 1; } //E
                            if (angleResult >= -90 && angleResult < -45) { dirResult = 2; } //NE
                            if (angleResult >= -135 && angleResult < -90) { dirResult = 3; } //N
                            if (angleResult >= -180 && angleResult < -135) { dirResult = 4; } //NW
                            if (angleResult >= 135 && angleResult < 180) { dirResult = 5; } //W
                            if (angleResult >= 90 && angleResult < 135) { dirResult = 6; } //SW
                            if (angleResult >= 45 && angleResult < 90) { dirResult = 7; } //S
                            if (angleResult >= 0 && angleResult < 45) { dirResult = 8; } //SE

                            if (player->getPosition().distance(enemy->getPosition()) <= player->getAttackRange()) {
                                auto boss = dynamic_cast<Boss*>(enemy);
                                if (boss && boss->currentState != boss->deadState) {
                                    boss->takeDamage(player->getDamage() + player->getEquipmentSkillDamage());
                                    if (boss->getCurrentHP() == 0)player->gainExp(boss->getExpGain());
                                }

                                auto monster = dynamic_cast<NormalMonster*>(enemy);
                                if (monster && monster->currentState != monster->deadState) {
                                    monster->takeDamage(player->getDamage() + player->getEquipmentSkillDamage());
                                    if (monster->getCurrentHP() == 0)player->gainExp(monster->getExpGain());
                                }
                            }

                        }
                    }
                }
            }}),
        animateResult,
        cocos2d::CallFunc::create([this]() {
            //Running
            if (player->getPhysicsBody()->getVelocity().y != 0 || player->getPhysicsBody()->getVelocity().x != 0)player->SwitchState(player->walkState);
            //Idle
            if (player->getPhysicsBody()->getVelocity().y == 0 && player->getPhysicsBody()->getVelocity().x == 0)player->SwitchState(player->idleState);
            }),
        nullptr
    ));

}

void PlayerAttack::ExitState() {

}

void PlayerAttack::UpdateState() {


}

