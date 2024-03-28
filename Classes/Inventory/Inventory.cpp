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
    //this->setAnchorPoint(Vec2(0.5, 0.5));

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

    const int numRows = 7;
    const int numCols = 8;
    float squareSize = (subInventory->getContentSize().width * subInventoryScaleX) / 10;
    const float gapX = squareSize / 30;
    const float gapY = squareSize / 30;

    //auto t = Vec2(20, 60);
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