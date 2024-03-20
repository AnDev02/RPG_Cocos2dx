#include "EquipmentFactory.h"
#include "./BaseEquipment.h"
#include "./Type/Weapon/ChippedSword.h"
BaseEquipment *EquipmentFactory::createEquipment(std::string type)
{
    if (type == "Chipped Sword")
    {
        return ChippedSword::create();
    }

    return nullptr;
}