#include "TargetSkill1.h"
#include "PlayerCharacters/PlayerCharacter.h"
bool TargetSkill1::init() {
	
    //AOE Range
    _aoeSprite = Sprite::create("skill/AOERangeSprite/CircleRange.png");
    _aoeSprite->setOpacity(100);
    this->addChild(_aoeSprite);
    _aoeSprite->setVisible(false);

    //Target sprite
    _targetSprite = Sprite::create("skill/AOERangeSprite/Target.png");
    _targetSprite->setName("Target");
    _targetSprite->retain();

    //Skill Icon...
    _iconSprite = Sprite::create("skill/SkillSprite/16.png");
    _iconSprite->setScale(0.1);
    _iconSprite->retain();

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("skill/SkillSprite/darkpower/darkpower.plist", "skill/SkillSprite/darkpower/darkpower.png");
    //Skill Sprite
    _skillSprite = Sprite::createWithSpriteFrameName("darkpower (1).png");
    _skillSprite->setScale(0.1);
    _skillSprite->setAnchorPoint(Vec2(0.5, 0));
    _skillSprite->retain();

    //Skill Animate
    _skillAnimate = Animate::create(Engine::createAnimation2("darkpower", 15, 0.1));
    _skillAnimate->retain();

    //SkillTree...
    _skillButton = SkillButton::create();
    _skillButton->setSkillButtonBorder(_iconSprite);
    _skillButton->setPosition(Vec2(-200, 0));
    this->addChild(_skillButton);
    _skillButton->setVisible(true);

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(TargetSkill1::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(TargetSkill1::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(TargetSkill1::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, _skillButton);
	return true;
}