#include "BuffSkill.h"

bool BuffSkill::init() {
    return true;
}

bool BuffSkill::onTouchBegan(Touch* touch, Event* event)
{

    Vec2 touchLocationInNode = _skillButton->convertToNodeSpace(touch->getLocation());

    if (_skillButton->skillButtonBtn->getBoundingBox().containsPoint(touchLocationInNode))
    {
        _skillButton->isPressed = true;
        return true;
    }
    return false;
}

void BuffSkill::onTouchMoved(Touch* touch, Event* event)
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

    }
}

void BuffSkill::onTouchEnded(Touch* touch, Event* event)
{
    _skillButton->prevPosBeforeRelease = _skillButton->skillButtonBtn->getPosition();
    _skillButton->skillButtonBtn->setPosition(_skillButton->centerPos);
    _skillButton->isPressed = false;

    performSkill(Vec2::ZERO);
}

void BuffSkill::performSkill(Vec2 target) {
    if (!_skillSprite->getParent()) {
        this->getParent()->addChild(_skillSprite, -1);
        auto sqe = Sequence::create(_skillAnimate, RemoveSelf::create(), nullptr);
        _skillSprite->runAction(sqe);
    }
}
void BuffSkill::update(float dt) {

}