﻿#include "SkillShot2.h"
#include "PlayerCharacters/PlayerCharacter.h"
bool SkillShot2::init() {

    //AOE Range
    _aoeSprite = Sprite::create("skill/AOERangeSprite/CircleRange.png");
    _aoeSprite->setOpacity(100);
    this->addChild(_aoeSprite);
    _aoeSprite->setVisible(false);

    //Skill Icon...
    _iconSprite = Sprite::create("skill/SkillSprite/15.png");
    _iconSprite->setScale(0.1);
    _iconSprite->retain();
    //SkillTree...
    _skillButton = SkillButton::create();
    _skillButton->setSkillButtonBorder(_iconSprite);
    _skillButton->setPosition(Vec2(300, 0));
    this->addChild(_skillButton);
    _skillButton->setVisible(true);

    //// Đăng ký sự kiện chạm cho _iconSprite
    //auto touchListener = EventListenerTouchOneByOne::create();
    //touchListener->setSwallowTouches(true);
    //touchListener->onTouchBegan = CC_CALLBACK_2(SkillBase::onTouchBegan, this);
    //touchListener->onTouchEnded = CC_CALLBACK_2(SkillBase::onTouchEnded, this);
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, _iconSprite);
    /*auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(SkillBase::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(SkillBase::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(SkillBase::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, _skillButton);
    schedule(CC_SCHEDULE_SELECTOR(AOESkill2::update), 0.05f);*/
    return true;
}