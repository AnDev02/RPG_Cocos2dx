#include "HealingBuff.h"
#include "PlayerCharacters/PlayerCharacter.h"
#include <string>
bool HealingBuff::init() {

    //Skill Icon...
    _iconSprite = Sprite::create("skill/SkillSprite/SkillIcon/19.png");
    _iconSprite->setScale(0.1);
    _iconSprite->retain();

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("skill/SkillSprite/BuffSkill/healing_buff/healing_buff.plist", "skill/SkillSprite/BuffSkill/healing_buff/healing_buff.png");
    //Skill Sprite
    _skillSprite = Sprite::createWithSpriteFrameName("healing_buff (1).png");
    _skillSprite->setAnchorPoint(Vec2(0.5, 0));
    _skillSprite->setScale(0.3);
    _skillSprite->retain();

    //Skill Animate
    _skillAnimate = Animate::create(Engine::createAnimation2("healing_buff", 18, 0.05));
    _skillAnimate->retain();

    //SkillButton
    _skillButton = SkillButton::create();
    _skillButton->setSkillButtonBorder(_iconSprite);
    _skillButton->setPosition(Vec2(-100, 0));
    this->addChild(_skillButton);
    _skillButton->setVisible(true);

    //SkillTree...

    // Đăng ký sự kiện onTouch cho SkillButton
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(HealingBuff::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(HealingBuff::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(HealingBuff::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, _skillButton);
    schedule(CC_SCHEDULE_SELECTOR(HealingBuff::update), 0.05f);

    return true;
}

bool HealingBuff::onTouchBegan(Touch* touch, Event* event)
{

    Vec2 touchLocationInNode = _skillButton->convertToNodeSpace(touch->getLocation());

    if (_skillButton->skillButtonBtn->getBoundingBox().containsPoint(touchLocationInNode))
    {
        _skillButton->isPressed = true;
        _skillButton->cancelButton->setVisible(true);

        return true;
    }
    return false;
}

void HealingBuff::onTouchMoved(Touch* touch, Event* event)
{
    if (_skillButton->isPressed)
    {
        CCLOG("Moving");
        Vec2 touchLocationInNode = _skillButton->convertToNodeSpace(touch->getLocation());
        Vec2 direction = touchLocationInNode - _skillButton->centerPos;
        float distance = direction.length();

        float radius = 40;

        if (distance > radius)
        {
            direction.normalize();
            direction *= radius;
            _skillButton->skillButtonBtn->setPosition(_skillButton->centerPos + direction);
            _skillButton->currentPos = _skillButton->centerPos + direction;
        }
        else
        {
            _skillButton->skillButtonBtn->setPosition(touchLocationInNode);
            _skillButton->currentPos = touchLocationInNode;
        }

        Vec2 lastTouchLocationInNode = _skillButton->convertToNodeSpace(touch->getLocation());
        if (_skillButton->cancelButton->getBoundingBox().containsPoint(lastTouchLocationInNode)) {
            _skillButton->cancelButton->setOpacity(200);
        }
        else _skillButton->cancelButton->setOpacity(50);


    }
}

void HealingBuff::onTouchEnded(Touch* touch, Event* event)
{
    _skillButton->prevPosBeforeRelease = _skillButton->skillButtonBtn->getPosition();
    _skillButton->skillButtonBtn->setPosition(_skillButton->centerPos);
    _skillButton->isPressed = false;

    Vec2 lastTouchLocationInNode = _skillButton->convertToNodeSpace(touch->getLocation());
    if (_skillButton->cancelButton->getBoundingBox().containsPoint(lastTouchLocationInNode)) {
        _skillButton->cancelButton->setVisible(false);
        return;
    }

    performSkill(Vec2::ZERO);
    _skillButton->cancelButton->setVisible(false);
}

void HealingBuff::performSkill(Vec2 target) {

    this->addChild(_skillSprite);

    auto sqe = Sequence::create(Repeat::create(_skillAnimate, 10), RemoveSelf::create(), nullptr);
    _skillSprite->runAction(sqe);
}