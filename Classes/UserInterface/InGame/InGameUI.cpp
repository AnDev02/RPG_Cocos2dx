#include "InGameUI.h"
#include "PlayerCharacters/PlayerCharacter.h"
#include "Enemies/Enemy.h"
#include "Enemies/EnemyFactory.h"
#include "UserInterface/InGame/Joystick.h"
#include "Boss/BossFactory.h"
#include "UserInterface/InGame/Minimap.h"
#include "Inventory/Inventory.h"
#include "UserInterface/InGame/HealthBar.h"
#include "UserInterface/InGame/Joystick.h"
#include "MapDecoration/MapDecoration.h"
#include "UserInterface/InGame/TalentCarousel.h"
#include "UserInterface/InGame/TalentButton.h"
#include "UserInterface/InGame/InventoryButton.h"

InGameUI* InGameUI::create(PlayerCharacter* player) {
    auto node = new InGameUI();
    if (node && node->init(player)) {
        node->_player = player;
        node->autorelease();
        return node;
    }
    CC_SAFE_DELETE(node);
    return nullptr;
}

bool InGameUI::init(PlayerCharacter* player) {
    if (!Layer::init()) {
        return false;
    }
    auto visibleSize = Director::getInstance()->getVisibleSize();

    auto inventory = Inventory::createInventory(player);
    inventory->setPosition(Vec2(0, 0));
    this->addChild(inventory, 20);


    auto healthBar = HealthBar::create("res/health-bar-border.png", "res/health-bar-inside.png", 10000, 5000);
    healthBar->setPosition(Vec2(0, -visibleSize.height / 2 + visibleSize.height / 4 + healthBar->getHeight() / 2.2));
    healthBar->decreaseHealth(7000);
    healthBar->decreaseMana(2500);
    healthBar->setScale(0.25 * Director::getInstance()->getContentScaleFactor());
    this->addChild(healthBar, 5);

    auto inventoryButton = InventoryButton::create(inventory);
    inventoryButton->setPosition(Vec2(-visibleSize.width / 4 + 40, visibleSize.height / 5));
    inventoryButton->setScale(0.1);
    this->addChild(inventoryButton, 6);

    _joystick = Joystick::create();
    _joystick->setPosition(Vec2(-visibleSize.width / 4 + _joystick->getSize().width, -visibleSize.height / 2 + visibleSize.height / 4 + healthBar->getHeight() * 1.5));
    _joystick->setScale(0.8 * Director::getInstance()->getContentScaleFactor());
    this->addChild(_joystick);


    
    TalentCarousel* talentCarousel = TalentCarousel::create(player);
    talentCarousel->setPosition(Vec2());
    this->addChild(talentCarousel, 6);

    TalentButton* talentButton = TalentButton::create(talentCarousel);
    talentButton->setPosition(-visibleSize.width / 4 + 65, visibleSize.height / 5);
    talentButton->setScale(0.1);
    this->addChild(talentButton, 5);

    this->scheduleUpdate();
    return true;
}

void InGameUI::update(float dt) {
    if (_joystick) {
        _player->movementDirection = _joystick->getDirection();
        if (_joystick->getIsPress()) {
            _player->handleMove(dt);

        }
        else {
            _player->getPhysicsBody()->setVelocity(Vec2::ZERO);
        }
    }
    _player->currentState->UpdateState();
}