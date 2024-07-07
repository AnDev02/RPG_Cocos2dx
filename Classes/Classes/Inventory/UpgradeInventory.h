#ifndef __UPGRADE_INVENTORY_H__
#define __UPGRADE_INVENTORY_H__

#include "cocos2d.h"
#include "../Equipment/EquipmentFactory.h"
#include "../Equipment/BaseEquipment.h"
#include "../Item/ItemFactory.h"
#include "./InventoryNode.h"
#include "../UserInterface/InGame/UpgradeProgressBar.h"
#include "UserInterface/InGame/ItemDetails.h"
USING_NS_CC;
class Player;
class UpgradeInventory : public Node
{
public:
    static UpgradeInventory* createUpgradeInventory(Player* _player);
    virtual bool init(Player* _player);
    void addEquipment(std::string equipmentName, int equipmentLv, int quantity);
    void addItem(std::string itemName, int quantity);
    void dropItem(std::string itemName);
    void dropEquipment(std::string itemName);
    void removeEquipment(std::string equipmentName);
    void removeItem(std::string itemName);
    void showUpgradeInventory();
    void sort();
    void hideUpgradeInventory();
    bool isShow() const { return isSo; };
    void nextInventoryPage();
    void prevInventoryPage();
    void onPageChange();
    float widthSize;
    InventoryNode* weaponNode;
    InventoryNode* materialItem1;
    InventoryNode* materialItem2;
    InventoryNode* materialItem3;
    BaseEquipment* equipment;
    BaseItem* item;
    InventoryNode* currentNode;
    Node* playerStats;
    Label* dmgStat;
    Label* mpStat;
    Label* hpStat;
    Label* msStat;
    Label* cdrStat;
    Label* armStat;
    UpgradeProgressBar* upgradeProgressBar;
    std::vector<InventoryNode*> materialNodes;
    std::vector<InventoryNode*> inventoryNodes;
private:
    const int totalInventoryPage = 3;
    const int numRows = 5;
    const int numCols = 5;
    int currentInventoryPage = 0;
    Sprite* prevInvenButton = nullptr;
    Sprite* nextInvenButton = nullptr;
    Label* pageLabel = nullptr;
    void showEquipmentDetails(BaseEquipment* equipment, bool isInUpgrade);
    void showItemDetails(BaseItem* item, bool isInMaterialsNode);
    Sprite* buttonClose;
    Sprite* mainUpgradeInventory;
    Sprite* subUpgradeInventory;
    Sprite* sortButton;
    EventListenerTouchOneByOne* touchListener;
    int movingItemQuantity;
    bool compareUpgradeItem(const std::vector<std::tuple<std::string, int>>& tuples1, const std::vector<std::tuple<std::string, int>>& tuples2);
    Label* updateButton;
    Node* inventoryBorder;
    Player* player;
    bool isDraggingItem = false;
    bool isSo = false;
    bool isInUpgrade = false;

};

#endif // __UPGRADE_INVENTORY_H__