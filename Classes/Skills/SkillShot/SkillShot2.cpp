#include "SkillShot2.h"
#include "PlayerCharacters/PlayerCharacter.h"
bool SkillShot2::init() {

    //AOE Range
    _aoeSprite = Sprite::create("skill/AOERangeSprite/SkillShotTarget.png");
    _aoeSprite->setOpacity(100);
    _aoeSprite->setScale(0.5);
    _aoeSprite->setAnchorPoint(Vec2(0, 0.5));
    this->addChild(_aoeSprite);
    _aoeSprite->setVisible(false);

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("skill/SkillSprite/fireball/fireball.plist", "skill/SkillSprite/fireball/fireball.png");
    //Skill Sprite
    _skillSprite = Sprite::createWithSpriteFrameName("fireball (1).png");
    _skillSprite->setAnchorPoint(Vec2(0, 0.5));
    _skillSprite->retain();
    //Skill Animate
    //Skill Animate
    _skillAnimate = Animate::create(Engine::createAnimation2("fireball", 40, 0.025));
    _skillAnimate->retain();

    //Skill Icon...
    _iconSprite = Sprite::create("skill/SkillSprite/15.png");
    _iconSprite->setScale(0.1);
    _iconSprite->retain();
    //SkillTree...
    _skillButton = SkillButton::create();
    _skillButton->setSkillButtonBorder(_iconSprite);
    _skillButton->setPosition(Vec2(-100, 0));
    this->addChild(_skillButton);
    _skillButton->setVisible(true);

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(SkillShot2::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(SkillShot2::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(SkillShot2::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, _skillButton);
    return true;
}