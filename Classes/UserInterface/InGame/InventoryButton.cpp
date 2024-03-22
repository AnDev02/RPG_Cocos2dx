#include "InventoryButton.h"
#include "../../Inventory/Inventory.h"

InventoryButton* InventoryButton::create(Inventory* inventory) {
    auto node = new InventoryButton();
    if (node && node->init(inventory)) {
        node->autorelease();
        return node;
    }
    CC_SAFE_DELETE(node);
    return nullptr;
}

bool InventoryButton::init(Inventory* inventory) {
    if (!Node::init()) {
        return false;
    }

    inven = inventory;
    btnSprite = Sprite::create("res/inventory-icon.png");
    btnSprite->setPosition(this->getPosition());
    btnSprite->setScale(3);
    this->addChild(btnSprite);

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true); // ??m b?o r?ng s? ki?n ch?m ch? ???c x? lý b?i sprite này
    touchListener->onTouchBegan = CC_CALLBACK_2(InventoryButton::onTouchBegan, this); // G?n hàm x? lý onTouchBegan
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, btnSprite);


    return true;
}

bool InventoryButton::onTouchBegan(Touch* touch, Event* event) {
    if (btnSprite->getBoundingBox().containsPoint(this->convertToNodeSpace(touch->getLocation()))) {
        if(inven->isShow()) 
            inven->hideInventory();
        else
            inven->showInventory();
        return true;
    }
    return false;
}
