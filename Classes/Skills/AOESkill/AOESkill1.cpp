﻿#include "AOESkill1.h"
#include "PlayerCharacters/PlayerCharacter.h"
bool AOESkill1::init() {
	
    //AOE Range
    _aoeSprite = Sprite::create("skill/AOERangeSprite/CircleRange.png");
    _aoeSprite->setOpacity(100);
    this->addChild(_aoeSprite);
    _aoeSprite->setVisible(false);

    //Skill Icon...
    _iconSprite = Sprite::create("skill/SkillSprite/10.png");
    _iconSprite->setScale(0.1);
    _iconSprite->retain();
    //SkillTree...
    _skillButton = SkillButton::create();
    _skillButton->setSkillButtonBorder(_iconSprite);
    _skillButton->setPosition(Vec2(100, 0));
    this->addChild(_skillButton);
    _skillButton->setVisible(true);

    //// Đăng ký sự kiện chạm cho _iconSprite
    //auto touchListener = EventListenerTouchOneByOne::create();
    //touchListener->setSwallowTouches(true);
    //touchListener->onTouchBegan = CC_CALLBACK_2(SkillBase::onTouchBegan, this);
    //touchListener->onTouchEnded = CC_CALLBACK_2(SkillBase::onTouchEnded, this);
    //_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, _iconSprite);

    schedule(CC_SCHEDULE_SELECTOR(AOESkill1::update), 0.5f);
	return true;
}

void AOESkill1::update(float dt) {
    //if (_skillButton->getIsPress()) {
    //    float rate = _skillButton->getCurrentPos().distance(_skillButton->getCenterPos()) / 40;
    //    if(!this->_aoeSprite->isVisible())this->_aoeSprite->setVisible(true);

    //    auto dir = _skillButton->getDirection();
    //    dir.normalize();

    //    Vec2 aoeRangeSpritePos = this->getParent()->getPosition() + dir * rate * 150;
    //    this->_aoeSprite->setPosition(aoeRangeSpritePos);
    //}
}