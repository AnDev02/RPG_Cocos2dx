#include "Inventory.h"
#include "../PlayerCharacters/PlayerCharacter.h"
Inventory *Inventory::createInventory(float zoomLevel, PlayerCharacter* _player)
{
    auto inventory = new (std::nothrow) Inventory();
    if (inventory && inventory->init(zoomLevel, _player))
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

bool Inventory::init(float zoomLevel, PlayerCharacter* _player)
{
    if (!Node::init())
    {
        return false;
    }
    Size visibleSize = Director::getInstance()->getVisibleSize();
    inventoryBorder = Node::create();
    this->addChild(inventoryBorder);
    buttonClose = Sprite::create("res/c_header_close.png");
    buttonClose->setScale(0.4);
    buttonClose->retain();
    buttonClose->setPosition(Vec2((visibleSize.width - buttonClose->getContentSize().width) / zoomLevel, (visibleSize.height / 2 - buttonClose->getContentSize().height) / zoomLevel));
    inventoryBorder->addChild(buttonClose, 50);
    auto layer = LayerColor::create(Color4B(0, 0, 0, 255));
    layer->setContentSize(Director::getInstance()->getVisibleSize());
    layer->setAnchorPoint(Vec2(0, 0));
    layer->setPosition(Vec2(-Director::getInstance()->getVisibleSize().width / 2, -Director::getInstance()->getVisibleSize().height / 2));

    inventoryBorder->addChild(layer, 1);

    auto touchListener2 = EventListenerTouchOneByOne::create();
    touchListener2->onTouchBegan = [&](Touch* touch, Event* event) {
        auto startPoint = this->convertToNodeSpace(touch->getLocation());
        CCLOG("buttonClose1 %f, %f", buttonClose->getPositionX(), buttonClose->getPositionY());
        CCLOG("buttonClose2 %f, %f", buttonClose->getContentSize().width, buttonClose->getContentSize().height);
        if (buttonClose->getBoundingBox().containsPoint(startPoint))
        {
            CCLOG("close");
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
    subInventory->setPosition(Vec2(0, 0));
    inventoryBorder->addChild(subInventory, 10);

    mainInventory->setAnchorPoint(Vec2(0, 0.5));
    inventoryBorder->addChild(mainInventory, 12);
    float subInventoryScaleX = (visibleSize.width / 2 / zoomLevel) / subInventory->getContentSize().width;
    float subInventoryScaleY = visibleSize.height / zoomLevel / subInventory->getContentSize().height;
    subInventory->setScale(subInventoryScaleX, subInventoryScaleY);
    mainInventory->setScale(subInventoryScaleX, subInventoryScaleY);

    subInventory->setPosition(Vec2((subInventory->getContentSize().width * subInventoryScaleX) / 2, 0));
    mainInventory->setPosition(Vec2((subInventory->getContentSize().width * subInventoryScaleX) / 2 + subInventory->getContentSize().width * (subInventoryScaleX / 2), 0));

    const int numRows = 7;
    const int numCols = 8;
    float squareSize = (subInventory->getContentSize().width * subInventoryScaleX) / 10;
    const float gapX = squareSize / 30;
    const float gapY = squareSize / 30;

    
    auto t = Vec2(subInventory->getContentSize().width * subInventoryScaleX / 9 / 1.3, -(subInventory->getContentSize().height * subInventoryScaleY / 4)) + Vec2(subInventory->getContentSize().width * subInventoryScaleX / 2 + subInventory->getContentSize().width * (subInventoryScaleX / 2), subInventory->getContentSize().height * subInventoryScaleY / 2);
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