#include "Inventory.h"
#include "../PlayerCharacters/PlayerCharacter.h"
Inventory *Inventory::createInventory(PlayerCharacter* _player)
{
    auto inventory = new (std::nothrow) Inventory();
    if (inventory && inventory->init(_player))
    {
        inventory->autorelease();
        return inventory;
    }
    else
    {
        delete inventory;
        return nullptr;
    }
}

bool Inventory::init(PlayerCharacter* _player)
{
    if (!Node::init())
    {
        return false;
    }

    Size visibleSize = Director::getInstance()->getVisibleSize();
    inventoryBorder = Node::create();
    this->addChild(inventoryBorder);
    auto layer = LayerColor::create(Color4B(0, 0, 0, 255));
    layer->setContentSize(Director::getInstance()->getVisibleSize());
    layer->setPosition(Vec2(-Director::getInstance()->getVisibleSize().width / 2, -Director::getInstance()->getVisibleSize().height / 2));

    inventoryBorder->addChild(layer, 1);

    auto touchListener2 = EventListenerTouchOneByOne::create();
    touchListener2->onTouchBegan = [&](Touch* touch, Event* event) {
        auto startPoint = this->convertToNodeSpace(touch->getLocation());
        if (buttonClose->getBoundingBox().containsPoint(startPoint))
        {
            hideInventory();
        }
        if (isSo && mainInventory && !mainInventory->getBoundingBox().containsPoint(this->convertToNodeSpace(touch->getLocation()))) {
            hideInventory();
            return true;
        }
        return false;
    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener2, layer);

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->onTouchBegan = [&](Touch *touch, Event *event)
    {
        if (isDraggingItem == false && isSo)
        {
            auto startPoint = this->convertToNodeSpace(touch->getLocation());
            for (auto &i : inventoryNodes)
            {
                if (i->getBoundingNode().containsPoint(startPoint))
                {
                    if (i->getBaseEquipment())
                    {
                        equipment = EquipmentFactory::createEquipment(i->getBaseEquipment()->getEquipmentName());
                        equipment->setScale(0.3);
                        equipment->setPosition(startPoint);
                        inventoryBorder->addChild(equipment, 25);
                        i->removeBaseEquipment();
                        currentNode = i;
                        isDraggingItem = true;
                        return true;
                    }
                    return false;
                }
            }
        }
        return false;
    };
    touchListener->onTouchMoved = [&](Touch *touch, Event *event)
    {
        if (isDraggingItem && isSo)
        {
            equipment->setPosition(this->convertToNodeSpace(touch->getLocation()));
        }
    };
    touchListener->onTouchEnded = [&](Touch *touch, Event *event)
    {
        if (isDraggingItem && isSo)
        {
            auto endPoint = this->convertToNodeSpace(touch->getLocation());
            int count = 0;
            for (auto &i : inventoryNodes)
            {
                if (i->getBoundingNode().containsPoint(endPoint))
                {
                    i->setBaseEquipment(equipment->getEquipmentName());
                    i->setQuantity(1);
                    count++;
                    break;
                }
            }
            if (count == 0)
            {
                currentNode->setBaseEquipment(equipment->getEquipmentName());
                currentNode->setQuantity(1);
                count++;
            }
            equipment->removeFromParentAndCleanup(true);
            equipment = nullptr;
        }
        isDraggingItem = false;

    };
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);


    mainInventory = Sprite::create("res/inventory-border.png");


    subInventory = Sprite::create("res/inventory-border.png");
    inventoryBorder->addChild(subInventory, 10);

    inventoryBorder->addChild(mainInventory, 12);
    float subInventoryScaleX = (visibleSize.width / 2 / (visibleSize.width / visibleSize.height)) / subInventory->getContentSize().width;
    float subInventoryScaleY = visibleSize.height / (visibleSize.width / visibleSize.height) / subInventory->getContentSize().height;
    subInventory->setScale(subInventoryScaleX, subInventoryScaleY);
    mainInventory->setScale(subInventoryScaleX, subInventoryScaleY);

    subInventory->setPosition(Vec2(-mainInventory->getContentSize().width * subInventoryScaleX / 2, 0));
    mainInventory->setPosition(Vec2(subInventory->getContentSize().width* subInventoryScaleX / 2 , 0));

    buttonClose = Sprite::create("res/c_header_close.png");
    buttonClose->setScale(0.4);
    buttonClose->retain();
    buttonClose->setPosition(Vec2(mainInventory->getPositionX() + mainInventory->getContentSize().width * subInventoryScaleX / 2 - buttonClose->getContentSize().width * 0.4, mainInventory->getPositionY() + mainInventory->getContentSize().height * subInventoryScaleY / 2 - buttonClose->getContentSize().height * 0.4));
    inventoryBorder->addChild(buttonClose, 50);

    auto characterSprite = Sprite::create("res/charactor-inventory.png");
    characterSprite->setPosition(subInventory->getPositionX(), subInventory->getPositionY());
    characterSprite->setFlippedX(true);
    characterSprite->setScale(0.8);
    inventoryBorder->addChild(characterSprite, 30);

    const int numRows = 7;
    const int numCols = 8;
    float squareSize = (subInventory->getContentSize().width * subInventoryScaleX) / 10;
    const float gapX = squareSize / 30;
    const float gapY = squareSize / 30;

    auto weaponNode = InventoryNode::createInventoryNode(squareSize);
    weaponNode->setPosition(subInventory->getPositionX() + (subInventory->getContentSize().width / 2), subInventory->getPositionY() + gapY * 15);
    auto weaponIcon = Sprite::create("res/weapon-icon.png");
    weaponIcon->setScale(0.2);
    weaponIcon->setAnchorPoint(Vec2(-0.25, -0.25));
    weaponIcon->setPosition(weaponNode->getPosition());
    inventoryBorder->addChild(weaponIcon, 51);
    inventoryBorder->addChild(weaponNode, 50);
    auto armorNode = InventoryNode::createInventoryNode(squareSize);
    armorNode->setPosition(subInventory->getPositionX() - (subInventory->getContentSize().width / 2) - squareSize, subInventory->getPositionY() + gapY * 15);
    auto armorIcon = Sprite::create("res/armor-icon.png");
    armorIcon->setScale(0.2);
    armorIcon->setPosition(armorNode->getPosition());
    armorIcon->setAnchorPoint(Vec2(-0.25, -0.25));
    inventoryBorder->addChild(armorIcon, 51);
    inventoryBorder->addChild(armorNode, 50);
    auto ringNode = InventoryNode::createInventoryNode(squareSize);
    ringNode->setPosition(subInventory->getPositionX() + (subInventory->getContentSize().width / 2), subInventory->getPositionY() - (squareSize + gapY) + gapY * 15);
    auto ringIcon = Sprite::create("res/ring-icon.png");
    ringIcon->setAnchorPoint(Vec2(-0.5, -0.25));
    ringIcon->setScale(0.2);
    ringIcon->setPosition(ringNode->getPosition());
    inventoryBorder->addChild(ringIcon, 51);
    inventoryBorder->addChild(ringNode, 50);
    auto gearNode = InventoryNode::createInventoryNode(squareSize);
    gearNode->setPosition(subInventory->getPositionX() - (subInventory->getContentSize().width / 2) - squareSize, subInventory->getPositionY() - (squareSize + gapY) + gapY * 15);
    auto gearIcon = Sprite::create("res/gear-icon.png");
    gearIcon->setAnchorPoint(Vec2(-0.25, -0.25));
    gearIcon->setScale(0.2);
    gearIcon->setPosition(gearNode->getPosition());
    inventoryBorder->addChild(gearIcon, 51);
    inventoryBorder->addChild(gearNode, 50);
    auto shoeNode = InventoryNode::createInventoryNode(squareSize);
    shoeNode->setPosition(subInventory->getPositionX() + (subInventory->getContentSize().width / 2), subInventory->getPositionY() - (squareSize + gapY) * 2 + gapY * 15);
    auto shoeIcon = Sprite::create("res/shoe-icon.png");
    shoeIcon->setAnchorPoint(Vec2(-0.5, -0.25));
    shoeIcon->setScale(0.2);
    shoeIcon->setPosition(shoeNode->getPosition());
    inventoryBorder->addChild(shoeIcon, 51);
    inventoryBorder->addChild(shoeNode, 50);
    auto hatNode = InventoryNode::createInventoryNode(squareSize);
    hatNode->setPosition(subInventory->getPositionX() - (subInventory->getContentSize().width / 2) - squareSize, subInventory->getPositionY() - (squareSize + gapY) * 2 + gapY * 15);
    auto hatIcon = Sprite::create("res/hat-icon.png");
    hatIcon->setAnchorPoint(Vec2(-0.25, -0.25));
    hatIcon->setScale(0.2);
    hatIcon->setPosition(hatNode->getPosition());
    inventoryBorder->addChild(hatIcon, 51);
    inventoryBorder->addChild(hatNode, 50);

    auto t = Vec2(subInventory->getContentSize().width * subInventoryScaleX * 0.08, subInventory->getContentSize().height * subInventoryScaleY * 0.26);
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            auto node = InventoryNode::createInventoryNode(squareSize);
            node->setPosition(t + Vec2(col * (squareSize + gapX), -row * (squareSize + gapY)));
            inventoryBorder->addChild(node, 20);
            inventoryNodes.push_back(node);
        }
    }
    for (auto &i : inventoryNodes)
    {
        if (i->getStatus() != "busy")
        {
            i->setBaseEquipment("Chipped Sword");
            i->setQuantity(1);
            break;
        }
    }
    hideInventory();



    return true;
}

void Inventory::showInventory() {
    inventoryBorder->setVisible(true);
    isSo = true;
}

void Inventory::hideInventory() {
    inventoryBorder->setVisible(false);
    isSo = false;
}