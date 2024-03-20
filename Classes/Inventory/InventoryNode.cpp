#include "InventoryNode.h"

InventoryNode *InventoryNode::createInventoryNode(float size)
{
    auto inventoryNode = new (std::nothrow) InventoryNode();
    if (inventoryNode && inventoryNode->init(size))
    {
        inventoryNode->autorelease();
        return inventoryNode;
    }
    else
    {
        delete inventoryNode;
        return nullptr;
    }
}

bool InventoryNode::init(float size)
{
    if (!Node::init())
    {
        return false;
    }
    this->setContentSize(Size(size, size));

    return true;
}

void InventoryNode::setId(int id)
{
    this->id = id;
}

int InventoryNode::getId() const
{
    return this->id;
}

Rect InventoryNode::getBoundingNode() const
{
    return this->getBoundingBox();
}

bool InventoryNode::setBaseEquipment(std::string be)
{
    if (this->getStatus() != "busy")
    {
        this->baseEquipment = EquipmentFactory::createEquipment(be);
        if (this->baseEquipment)
        {
            this->setStatus("busy");
            this->baseEquipment->setScale(0.3);
            this->baseEquipment->setPosition(Vec2(this->baseEquipment->getContentSize().width * 0.269, this->baseEquipment->getContentSize().height * 0.269));
            this->addChild(this->baseEquipment);
        }
        return true;
    }
    return false;
}

bool InventoryNode::removeBaseEquipment()
{
    if (this->getQuantity() != 0)
    {
        this->baseEquipment->removeFromParentAndCleanup(true);
        this->baseEquipment = nullptr;
        this->setQuantity(0);
        this->setStatus("free");
        return true;
    }
    return false;
}

bool InventoryNode::decreaseBaseEquipment(int quantity)
{
    if (this->quantityItem >= quantity)
    {
        this->quantityItem -= quantity;
        if (this->getQuantity() <= 0)
        {
            this->setStatus("free");
        }
        return true;
    }
    return false;
}

BaseEquipment *InventoryNode::getBaseEquipment() const
{
    return this->baseEquipment;
}

void InventoryNode::setStatus(std::string stt)
{
    this->status = stt;
}

std::string InventoryNode::getStatus() const
{
    return this->status;
}

void InventoryNode::setQuantity(int qtt)
{
    this->quantityItem = qtt;
}

int InventoryNode::getQuantity() const
{
    return this->quantityItem;
}
