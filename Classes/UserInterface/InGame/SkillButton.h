#ifndef __SKILL_BUTTON_H__
#define __SKILL_BUTTON_H__

#include "cocos2d.h"
USING_NS_CC;
class SkillButton : public cocos2d::Node
{
public:
    SkillButton();

    // Khởi tạo SkillButton
    virtual bool init();

    //// Phương thức xử lý sự kiện chạm
    //bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    //void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);
    //void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

    // Trả về hướng của SkillButton
    Vec2 getDirection();
    bool getIsPress() const { return isPressed; };

    void setSkillButtonBorder(Sprite* newBorder) {

        skillButtonBorder = newBorder;
        this->addChild(skillButtonBorder);
    }

    Vec2 getPreviousPosBeforeRelease() {
        return this->prevPosBeforeRelease;
    }

    Vec2 getCurrentPos() {
        return this->currentPos;
    }
    Vec2 getCenterPos() {
        return this->centerPos;
    }
    CREATE_FUNC(SkillButton);



    bool isPressed;
    Sprite* skillButtonBorder;
    Sprite* skillButtonBtn;
    Vec2 prevPosBeforeRelease = Vec2::ZERO;
    Vec2 centerPos;
    Vec2 originalPosition;
    Vec2 currentDirection;
    Vec2 currentPos;
};

#endif // __JOYSTICK_H__