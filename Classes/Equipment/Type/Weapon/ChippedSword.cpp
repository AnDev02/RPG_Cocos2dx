#include "./ChippedSword.h"

// ChippedSword *ChippedSword::createChippedSword()
// {
//     auto chippedSword = new (std::nothrow) ChippedSword();
//     if (chippedSword && chippedSword->init())
//     {
//         chippedSword->autorelease();
//         return chippedSword;
//     }
//     else
//     {
//         delete chippedSword;
//         return nullptr;
//     }
// }

bool ChippedSword::init()
{
    if (!BaseEquipment::init())
    {
        return false;
    }
    // this->setEquipmentSprite(Sprite::create("sprites/equipment/Sword 2.png"));
    // this->getEquipmentSprite()->retain();
    this->setTexture("sprites/equipment/Sword 2.png");
    this->setDamage(20);
    this->setSkillDamage(5);
    this->setEquipmentName("Chipped Sword");
    this->setEquipmentLevel(BaseEquipment::Level::STANDARD);
    this->setEquipmentDesc("this is sword");
    this->setEquipmentStory("this is story");
    // this->addChild(this->getEquipmentSprite());
    this->retain();
    return true;
}