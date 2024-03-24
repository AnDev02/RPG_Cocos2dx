﻿#include "BloodMoonTower.h"

bool BloodMoonTower::init()
{
    if (!Node::init())
    {
        return false;
    }
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/Interactive Object/Blood Moon Tower/BloodMoonTower.plist", "map/Interactive Object/Blood Moon Tower/BloodMoonTower.png");
    // tạo animation cho đối tượng kẻ địch Bread
    BloodMoonTowerAnimate = Animate::create(Engine::getInstance()->createAnimation1("BloodMoon_", 9, 0.1));
    BloodMoonTowerAnimate->retain();
    // tạo Sprite cho đối tượng
    BloodMoonTowerSprite = Sprite::createWithSpriteFrameName("BloodMoon_0.png");
    //BloodMoonTowerSprite->setScale(2);
    // tạo Physics Box cho BloodMoonTower
    auto BloodMoonTowerBody = PhysicsBody::createBox(BloodMoonTowerSprite->getContentSize() - Size(5, 5), PhysicsMaterial(1.0f, 0.0f, 0.0f));
    BloodMoonTowerBody->setContactTestBitmask(true);
    BloodMoonTowerBody->setCollisionBitmask(0);
    // BloodMoonTowerBody->setPositionOffset(Vec2(0, 0.0f));
    BloodMoonTowerBody->setGravityEnable(false);
    BloodMoonTowerBody->setDynamic(false);
    this->addComponent(BloodMoonTowerBody);
    BloodMoonTowerSprite->setScale(0.7);
    // Cài đặt giới hạn xoay cho physics body
    playBloodMoonTowerAnimation();
    this->addChild(BloodMoonTowerSprite);
    return true;
}

BloodMoonTower *BloodMoonTower::createBloodMoonTower()
{
    return BloodMoonTower::create();
}

void BloodMoonTower::playBloodMoonTowerAnimation()
{
    BloodMoonTowerSprite->runAction(RepeatForever::create(BloodMoonTowerAnimate));
}
