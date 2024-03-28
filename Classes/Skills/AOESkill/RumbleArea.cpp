#include "RumbleArea.h"
#include "PlayerCharacters/PlayerCharacter.h"
#include <string>
bool RumbleArea::init() {


    skillTalent = new SkillTalent;
    skillTalent->skillName = "RumbleArea";
    skillTalent->iconPath = "skill/SkillSprite/SkillIcon/14.png";
    skillTalent->unlockPoint = 10;
    skillTalent->description = "good";
    skillTalent->skillType = "AOE";
    skillTalent->isLock = true;

    //AOE Range
    _aoeSprite = Sprite::create("skill/AOERangeSprite/RectangleRange.png");
    _aoeSprite->setOpacity(100);
    _aoeSprite->setAnchorPoint(Vec2(0, 0.5));
    this->addChild(_aoeSprite);
    _aoeSprite->setVisible(false);

    //Skill Icon...
    _iconSprite = Sprite::create("skill/SkillSprite/SkillIcon/14.png");
    _iconSprite->setScale(0.1);
    _iconSprite->retain();

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("skill/SkillSprite/AOESkill/rumble_area/rumble_area.plist", "skill/SkillSprite/AOESkill/rumble_area/rumble_area.png");
    //Skill Sprite
    _skillSprite = Sprite::createWithSpriteFrameName("rumble_area (1).png");
    _skillSprite->setAnchorPoint(Vec2(0, 0.5));
    _skillSprite->retain();

    //Skill Animate
    _skillAnimate = Animate::create(Engine::createAnimation2("rumble_area", 31, 0.05));
    _skillAnimate->retain();

    //SkillButton
    _skillButton = SkillButton::create();
    _skillButton->setSkillButtonBorder(_iconSprite);
    _skillButton->setPosition(Vec2(200, 100));
    this->addChild(_skillButton);
    _skillButton->setVisible(true);

    //SkillTree...

    // Đăng ký sự kiện onTouch cho SkillButton
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(RumbleArea::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(RumbleArea::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(RumbleArea::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, _skillButton);
    schedule(CC_SCHEDULE_SELECTOR(RumbleArea::update), 0.05f);

    return true;
}

bool RumbleArea::onTouchBegan(Touch* touch, Event* event)
{

    Vec2 touchLocationInNode = _skillButton->convertToNodeSpace(touch->getLocation());

    if (_skillButton->skillButtonBtn->getBoundingBox().containsPoint(touchLocationInNode))
    {
        _skillButton->isPressed = true;
        this->_aoeSprite->setVisible(true);
        _skillButton->cancelButton->setVisible(true);
        return true;
    }
    return false;
}

void RumbleArea::onTouchMoved(Touch* touch, Event* event)
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

        // Calculate the angle between the vector and the x-axis
        float angleRadians = atan2(direction.y, direction.x);
        float angleDegrees = CC_RADIANS_TO_DEGREES(-angleRadians); // Convert radians to degrees

        CCLOG("Angle: %f", angleDegrees);
        // Rotate the sprite to face the direction
        _aoeSprite->setRotation(angleDegrees);
        lastAngleRotate = angleDegrees;

        dir = direction;

    }
}

void RumbleArea::onTouchEnded(Touch* touch, Event* event)
{
    _skillButton->prevPosBeforeRelease = _skillButton->skillButtonBtn->getPosition();
    _skillButton->skillButtonBtn->setPosition(_skillButton->centerPos);
    _skillButton->isPressed = false;

    Vec2 lastTouchLocationInNode = _skillButton->convertToNodeSpace(touch->getLocation());
    if (_skillButton->cancelButton->getBoundingBox().containsPoint(lastTouchLocationInNode)) {
        this->_aoeSprite->setVisible(false);
        _skillButton->cancelButton->setVisible(false);
        return;
    }

    Vec2 pos = this->convertToWorldSpace(this->_aoeSprite->getPosition());
    performSkill(pos);
    this->_aoeSprite->setVisible(false);
    _skillButton->cancelButton->setVisible(false);
}

void RumbleArea::performSkill(Vec2 target) {

    if (!_skillSprite->getParent()) {
        Vec2 applyPosition = this->getParent()->getParent()->convertToNodeSpace(target);
        _skillSprite->setScale(0.75);
        _skillSprite->setRotation(lastAngleRotate);
        _skillSprite->setPosition(applyPosition);
        auto scene = this->getParent()->getScene();
        scene->addChild(_skillSprite);
        _skillSprite->runAction(Sequence::create(_skillAnimate, RemoveSelf::create(), nullptr));
    }
}