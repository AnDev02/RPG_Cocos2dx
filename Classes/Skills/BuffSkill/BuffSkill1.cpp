#include "BuffSkill1.h"
#include "PlayerCharacters/PlayerCharacter.h"
bool BuffSkill1::init() {
    //Skill Icon...
    _iconSprite = Sprite::create("skill/SkillSprite/11.png");
    _iconSprite->setScale(0.1);
    _iconSprite->retain();

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("skill/SkillSprite/zhonya/zhonya.plist", "skill/SkillSprite/zhonya/zhonya.png");
    //Skill Sprite
    _skillSprite = Sprite::createWithSpriteFrameName("zhonya (1).png");
    _skillSprite->setScale(0.5);
    _skillSprite->setAnchorPoint(Vec2(0.5, 0));
    _skillSprite->retain();

    //Skill Animate
    _skillAnimate = Animate::create(Engine::createAnimation2("zhonya", 15, 0.1));
    _skillAnimate->retain();
    
    //SkillTree...
    _skillButton = SkillButton::create();
    _skillButton->setSkillButtonBorder(_iconSprite);
    _skillButton->setPosition(Vec2(200, 0));
    this->addChild(_skillButton);
    _skillButton->setVisible(true);

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(BuffSkill1::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(BuffSkill1::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(BuffSkill1::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, _skillButton);
    return true;
}