#ifndef __BASE_EQUIPMENT__
#define __BASE_EQUIPMENT__

#include "cocos2d.h"
#include "../Engine/Engine.h"
#include "./EquipmentFactory.h"
#include "./UserInterface/InGame/EquipmentDetails.h"
USING_NS_CC;

class BaseEquipment : public cocos2d::Sprite
{
public:
    Sprite* lootIndicator = nullptr;
    virtual bool init();
    enum Type {
        STANDARD = 1,
        ENHANCED = 2,
        RARE = 3,
        LEGENDARY = 4
    };
    Type getEquipmentType() const;
    enum Element {
        NONE,
        THUNDER,
        FIRE
    };
    struct LevelUpMaterials {
        std::vector<std::tuple<std::string, int>> materialsItem;
        int money;
    };
    struct EquipmentData {
        std::string name;
        int level;
        std::string iconPath;
    };
    EquipmentDetails* equipmentDetails = nullptr;
    Element getElement() const;
    void setElement(Element element);
    void setEquipmentType(Type);
    void setEquipmentDesc(std::string);
    std::string getEquipmentDesc() const;
    void setEquipmentStory(std::string);
    std::string getEquipmentStory() const;
    void setEquipmentName(std::string type);
    std::string getEquipmentName() const;
    void setDamage(float damage);
    float getDamage() const;
    void setSkillDamage(float damage);
    float getSkillDamage() const;
    void setMovementSpeed(float speed);
    float getMovementSpeed() const;
    void setArmor(float arm);
    float getArmor() const;
    float getMP() const;
    void setMP(float newMp);
    std::string getTypeName() const { return typeName; };
    void setTypeName(std::string newType) { typeName = newType; };
    // void setEquipmentSprite(Sprite *spr);
    // Sprite *getEquipmentSprite() const;
    void setCDR(float time) { CDR = time; };
    float getCDR() const { return CDR; };
    void setHP(float newHP) { HP = newHP; };
    float getHP() const { return HP; };
    void levelUp();
    void setLevel(int lv);
    int getLevel() const { return currentLevel; };
    int getMaxLevel() const { return maxLevel; };
    LevelUpMaterials getMaterialsToUpgrade(int level) const { return materialsToUpgrade[level - 1]; };
    void showLootIndicator() {
        if(lootIndicator) lootIndicator->setVisible(true);
        if(titleIndicator) titleIndicator->setVisible(true);
        if(itemNameIndicator) itemNameIndicator->setVisible(true);

        if (lootIndicator->getScaleX() != 3.5) {
            lootIndicator->setScale(3.5 * Director::getInstance()->getContentScaleFactor());
            lootIndicator->setPosition(Vec2(this->getContentSize().width * this->getScale() / 2, 0));
            this->setScale(0.2);
        }
    };
    std::vector<LevelUpMaterials> materialsToUpgrade;
    ~BaseEquipment();

    CREATE_FUNC(BaseEquipment);
private:
    Element element = Element::NONE;
    Type type;
    std::string story;
    std::string description;
    std::string name;
    std::string typeName;
    float damage = 0;
    float skillDamage = 0;
    float movementSpeed = 0;
    float armor = 0;
    float CDR = 0;
    float MP = 0;
    float HP = 0;
    int currentLevel = 0;
    int maxLevel = 5;
    int coinToUpgrade = 10;
protected:
    Sprite* titleIndicator = nullptr;
    Label* itemNameIndicator = nullptr;
};

#endif // __BASE_EQUIPMENT__