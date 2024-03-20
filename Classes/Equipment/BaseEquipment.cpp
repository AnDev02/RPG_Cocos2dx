#include "BaseEquipment.h"

// BaseEquipment *BaseEquipment::createEquipment()
// {
//     auto equipment = new (std::nothrow) BaseEquipment();
//     if (equipment && equipment->init())
//     {
//         equipment->autorelease();
//         return equipment;
//     }
//     else
//     {
//         delete equipment;
//         return nullptr;
//     }
// }

bool BaseEquipment::init()
{
    if (!Sprite::init())
    {
        return false;
    }
    this->retain();
    return true;
}

void BaseEquipment::setEquipmentLevel(Level lv)
{
    this->level = lv;
}

BaseEquipment::Level BaseEquipment::getEquipmentLevel() const
{
    return this->level;
};

void BaseEquipment::setEquipmentDesc(std::string des)
{
    this->description = des;
}

std::string BaseEquipment::getEquipmentDesc() const
{
    return this->description;
}

void BaseEquipment::setEquipmentName(std::string n)
{
    this->name = n;
}

std::string BaseEquipment::getEquipmentName() const
{
    
    return this->name;
}

void BaseEquipment::setEquipmentStory(std::string str)
{
    this->story = str;
}

std::string BaseEquipment::getEquipmentStory() const
{
    return this->story;
}

void BaseEquipment::setDamage(int damage)
{
    this->damage = damage;
}

int BaseEquipment::getDamage() const
{
    return this->damage;
}

void BaseEquipment::setSkillDamage(int damage)
{
    this->skillDamage = damage;
}

int BaseEquipment::getSkillDamage() const
{
    return this->skillDamage;
}

void BaseEquipment::setMovementSpeed(float speed)
{
    this->movementSpeed = speed;
}

float BaseEquipment::getMovementSpeed() const
{
    return this->movementSpeed;
}

void BaseEquipment::setArmor(int arm)
{
    this->armor = arm;
}

int BaseEquipment::getArmor() const
{
    return this->armor;
}

// void BaseEquipment::setEquipmentSprite(Sprite *spr)
// {
//     this->equipmentSprite = spr;
// }
// Sprite *BaseEquipment::getEquipmentSprite() const
// {
//     return this->equipmentSprite;
// }

BaseEquipment::~BaseEquipment() {
this->release();
}