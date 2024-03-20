#include "Joystick.h"

USING_NS_CC;

Joystick::Joystick() : isPressed(false), currentDirection(Vec2::ZERO)
{
}

bool Joystick::init()
{
    if (!Node::init()) // Thay đổi đường dẫn hình ảnh joystick của bạn
    {
        return false;
    }

    joystickBorder = Sprite::create("res/joystick-border.png");
    joystickBorder->setPosition(Vec2(125, 125));
    joystickBorder->setOpacity(60);
    this->addChild(joystickBorder, 300);

    joystickBtn = Sprite::create("res/joystick-btn.png");
    joystickBtn->setPosition(Vec2(125, 125));
    joystickBtn->setOpacity(60);
    this->addChild(joystickBtn, 500);
    centerPos = joystickBtn->getPosition();

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(Joystick::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(Joystick::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(Joystick::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    return true;
}

bool Joystick::onTouchBegan(Touch *touch, Event *event)
{
    Vec2 touchLocationInNode = this->convertToNodeSpace(touch->getLocation());

    if (joystickBtn->getBoundingBox().containsPoint(touchLocationInNode))
    {
        isPressed = true;
        return true;
    }
    return false;
}

void Joystick::onTouchMoved(Touch *touch, Event *event)
{
    if (isPressed)
    {
        Vec2 touchLocationInNode = this->convertToNodeSpace(touch->getLocation());
        Vec2 direction = touchLocationInNode - centerPos;
        float distance = direction.length();

        float radius = joystickBorder->getContentSize().width / 2;

        if (distance > radius)
        {
            direction.normalize();
            direction *= radius;
            joystickBtn->setPosition(centerPos + direction);
        }
        else
        {
            joystickBtn->setPosition(touchLocationInNode);
        }
    }
}

void Joystick::onTouchEnded(Touch *touch, Event *event)
{
    prevPosBeforeRelease = joystickBtn->getPosition();
    joystickBtn->setPosition(centerPos);
    isPressed = false;
}

Vec2 Joystick::getDirection()
{
    if (isPressed)
        return joystickBtn->getPosition() - centerPos;
    else
    {
        if (prevPosBeforeRelease != Vec2::ZERO)
        {
            auto dir = prevPosBeforeRelease - centerPos;
            dir.normalize();
            return dir;
        }
        else
        {
            auto dir = Vec2(1, 0);
            dir.normalize();
            return dir;
        }
    }
}
