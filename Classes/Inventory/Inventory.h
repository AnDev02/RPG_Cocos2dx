#ifndef __INVENTORY_H__
#define __INVENTORY_H__

#include "cocos2d.h"
#include "../Equipment/EquipmentFactory.h"
#include "../Equipment/BaseEquipment.h"
#include "./InventoryNode.h"

USING_NS_CC;

class Inventory : public Node
{
public:
    static Inventory *createInventory();
    virtual bool init() override;
    void addEquipment();
    void addItem();
    void removeEquipment();
    void removeItem();
    void displayInventory();
private:
    Sprite* mainInventory;
    Sprite* subInventory;
    EventListenerTouchOneByOne *touchListener;
    BaseEquipment *equipment;
    std::vector<InventoryNode*> inventoryNodes;
    InventoryNode* currentNode;
    bool isDraggingItem = false;
    
};

#endif // __INVENTORY_H__