﻿#include"Obelisk.h"

bool Obelisk::init()
{
	if (!Node::init()) {
		return false;
	}
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/Interactive Object/Obelisk/Obelisk.plist", "map/Interactive Object/Obelisk/Obelisk.png");
    // tạo animation cho đối tượng kẻ địch Bread
    ObeliskAnimate = Animate::create(Engine::getInstance()->createAnimation1("Obelisk_",13,0.1));
    ObeliskAnimate->retain();
    // tạo Sprite cho đối tượng
    ObeliskSprite = Sprite::createWithSpriteFrameName("Obelisk_0.png");

    // tạo Physics Box cho Obelisk
    auto ObeliskBody = PhysicsBody::createBox(ObeliskSprite->getContentSize() - Size(5,5), PhysicsMaterial(1.0f, 0.0f, 0.0f));
    ObeliskBody->setContactTestBitmask(true);
    ObeliskBody->setCollisionBitmask(0);
   // ObeliskBody->setPositionOffset(Vec2(0, 0.0f));
    ObeliskBody->setGravityEnable(false);
    ObeliskBody->setDynamic(false);
    this->addComponent(ObeliskBody);
    ObeliskSprite->setScale(0.7);
    // Cài đặt giới hạn xoay cho physics body
    playObeliskAnimation();
    this->addChild(ObeliskSprite);
	return true;
}

Obelisk* Obelisk::createObelisk()
{
    return Obelisk::create();
}

void Obelisk::playObeliskAnimation()
{
    ObeliskSprite->runAction(RepeatForever::create(ObeliskAnimate));

}
