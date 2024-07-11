#include "Dropdown.h"
#include "UserInterface/InGame/InGameUI.h"
#include "Scenes/SelectMapLayer.h"
#include "Game/Game.h"

Dropdown* Dropdown::create() {
    auto node = new Dropdown();
    if (node && node->init()) {
        node->autorelease();
        return node;
    }
    CC_SAFE_DELETE(node);
    return nullptr;
}

bool Dropdown::init() {
    if (!Node::init()) {
        return false;
    }
    bg = Sprite::create("res/dropdown_btn.png");
    bg->setScale(2.8, 1.8);
    iconSprite = Sprite::create("res/left-arr-ui2.png");
    iconSprite->setScale(1.2);
    this->addChild(bg);
    this->addChild(iconSprite);
    isOpen = false;
    isScaling = false;  // Khởi tạo biến cờ
    bg->setAnchorPoint(Vec2(1.0, 0));
    updateIconSpritePosition();

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(Dropdown::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

bool Dropdown::onTouchBegan(Touch* touch, Event* event) {
    if (isVisible()) {
        auto startPoint = this->convertToNodeSpace(touch->getLocation());
        if (iconSprite->getBoundingBox().containsPoint(startPoint)) {
            iconSprite->setVisible(false);
            iconSprite->setRotation(isOpen ? 180 : 0);
            if (isScaling) {
                return false; 
            }
            ScaleTo* scaleAction;
            if (isOpen)
                scaleAction = ScaleTo::create(0.5, bg->getScaleX() / 3, bg->getScaleY());
            else
                scaleAction = ScaleTo::create(0.5, bg->getScaleX() * 3, bg->getScaleY());

            auto sequence = Sequence::create(
                scaleAction,
                CallFunc::create([this]() {
                    updateIconSpritePosition();
                    isScaling = false;  
                    iconSprite->setVisible(true);
                    }),
                nullptr
            );

            isScaling = true;  
            bg->runAction(sequence);

            isOpen = !isOpen;
        }
    }
    return false;
}

void Dropdown::updateIconSpritePosition() {
    float bgWidth = bg->getContentSize().width * bg->getScaleX();
    iconSprite->setPosition(Vec2(bg->getPositionX() - bgWidth + (iconSprite->getContentSize().width * iconSprite->getScale() * 0.75), bg->getPositionY() + bg->getContentSize().height * bg->getScaleY() / 2));
}