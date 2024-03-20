#ifndef __BASE_EQUIPMENT_H__
#define __BASE_EQUIPMENT_H__

#include "cocos2d.h"
#include "../Engine/Engine.h"
#include "./EquipmentFactory.h"
USING_NS_CC;

class BaseEquipment : public cocos2d::Sprite
{
public:
    virtual bool init();
    enum Level {
        STANDARD,
        ENHANCED, 
        RARE,
        LEGENDARY
    };
    void setEquipmentLevel(Level);
    Level getEquipmentLevel() const;
    void setEquipmentDesc(std::string);
    std::string getEquipmentDesc() const;
    void setEquipmentStory(std::string);
    std::string getEquipmentStory() const;
    void setEquipmentName(std::string type);
    std::string getEquipmentName() const;
    void setDamage(int damage);
    int getDamage() const;
    void setSkillDamage(int damage);
    int getSkillDamage() const;
    void setMovementSpeed(float speed);
    float getMovementSpeed() const;
    void setArmor(int arm);
    int getArmor() const;
    // void setEquipmentSprite(Sprite *spr);
    // Sprite *getEquipmentSprite() const;
    ~BaseEquipment();
    
    CREATE_FUNC(BaseEquipment);
private:
    Level level;
    std::string story;
    std::string description;
    std::string name;
    int damage;
    int skillDamage;
    float movementSpeed;
    int armor;
    // Sprite* equipmentSprite;
};

#endif // __BASE_EQUIPMENT_H__