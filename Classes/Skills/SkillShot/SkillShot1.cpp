#include "SkillShot1.h"
#include "PlayerCharacters/PlayerCharacter.h"
bool SkillShot1::init() {
	
    //AOE Range
    _aoeSprite = Sprite::create("skill/AOERangeSprite/SkillShotTarget.png");
    _aoeSprite->setOpacity(100);
    _aoeSprite->setAnchorPoint(Vec2(0, 0.5));
    this->addChild(_aoeSprite);
    _aoeSprite->setVisible(false);

    //Skill Icon...
    iconSpritePath = "skill/SkillSprite/14.png";
    _iconSprite = Sprite::create(iconSpritePath);
    _iconSprite->setScale(0.1);
    _iconSprite->retain();

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("skill/SkillSprite/fireball/fireball.plist", "skill/SkillSprite/fireball/fireball.png");
    //Skill Sprite
    _skillSprite = Sprite::createWithSpriteFrameName("fireball (1).png");
    _skillSprite->setAnchorPoint(Vec2(0, 0.5));
    _skillSprite->retain();

    //Skill Animate
    _skillAnimate = Animate::create(Engine::createAnimation2("fireball", 40, 0.025));
    _skillAnimate->retain();

    //SkillButton
    _skillButton = SkillButton::create();
    _skillButton->setSkillButtonBorder(_iconSprite);
    _skillButton->setPosition(Vec2(300, 0));
    this->addChild(_skillButton);
    _skillButton->setVisible(true);

    //SkillTree...

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(SkillShot1::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(SkillShot1::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(SkillShot1::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, _skillButton);
	return true;
}