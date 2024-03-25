#ifndef __INVENTORY_NODE_H__
#define __INVENTORY_NODE_H__

#include "cocos2d.h"
#include "../Equipment/EquipmentFactory.h"
#include "../Equipment/BaseEquipment.h"

USING_NS_CC;
class InventoryNode : public Node
{
public:
    static InventoryNode *createInventoryNode(float size);
    virtual bool init(float size);
    void setId(int id);
    int getId() const;
    Rect getBoundingNode() const;
    bool setBaseEquipment(std::string);
    BaseEquipment* getBaseEquipment() const;
    void setStatus(std::string stt);
    std::string getStatus() const;
    void setQuantity(int qtt);
    int getQuantity() const;
    bool removeBaseEquipment();
    bool decreaseBaseEquipment(int);
private:
    Sprite* nodeSpr;
    std::string status; // busy, free
    BaseEquipment* baseEquipment;
    int quantityItem;
    int id;
    float nodeScaleX;
    float nodeScaleY;
    bool isDraggingItem = false;
    Node* node;
};

#endif // __INVENTORY_NODE_H__