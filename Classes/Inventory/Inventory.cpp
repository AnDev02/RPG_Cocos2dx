#include "Inventory.h"

Inventory *Inventory::createInventory()
{
    auto inventory = new (std::nothrow) Inventory();
    if (inventory && inventory->init())
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

bool Inventory::init()
{
    if (!Node::init())
    {
        return false;
    }

    auto layer = LayerColor::create(Color4B(0, 0, 0, 140));
    layer->setContentSize(Director::getInstance()->getVisibleSize());
    layer->setAnchorPoint(Vec2(0, 0));
    layer->setPosition(Vec2(-Director::getInstance()->getVisibleSize().width / 2, -Director::getInstance()->getVisibleSize().height / 2));
    this->addChild(layer, 1);
    hideInventory();

    auto touchListener2 = EventListenerTouchOneByOne::create();
    touchListener2->onTouchBegan = [&](Touch* touch, Event* event) {
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
                        this->addChild(equipment, 10);
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

    subInventory = Sprite::create("res/sub-inventory.png");
    subInventory->setAnchorPoint(Vec2(0, 0.5));
    subInventory->setPosition(Vec2(0, 0));
    this->addChild(subInventory, 10);

    mainInventory = Sprite::create("res/main-inventory.png");
    mainInventory->setAnchorPoint(Vec2(0, 0.5));
    mainInventory->setPosition(Vec2(subInventory->getContentSize().width, 0));
    this->addChild(mainInventory, 10);

    const int numRows = 4;
    const int numCols = 4;
    const float squareSize = mainInventory->getContentSize().width / 5.18;
    const float gapX = mainInventory->getContentSize().width / 30;
    const float gapY = mainInventory->getContentSize().width / 30;
    auto t = Vec2(mainInventory->getPosition().x + mainInventory->getContentSize().width / 15.4, mainInventory->getPosition().y + mainInventory->getContentSize().height / 4);
    for (int row = 0; row < numRows; ++row)
    {
        for (int col = 0; col < numCols; ++col)
        {
            auto node = InventoryNode::createInventoryNode(squareSize);
            node->setPosition(t + Vec2(col * (squareSize + gapX), -row * (squareSize + gapY)));
            this->addChild(node, 10);
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



    return true;
}

void Inventory::showInventory() {
    this->setVisible(true);
    isSo = true;
}

void Inventory::hideInventory() {
    this->setVisible(false);
    isSo = false;
}