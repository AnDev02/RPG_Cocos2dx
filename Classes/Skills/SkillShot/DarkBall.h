#ifndef __DARK_BALL_H__
#define __DARK_BALL_H__

#include "cocos2d.h"
#include "SkillShot.h"
USING_NS_CC;

class DarkBall : public SkillShot
{
public:
    //Init
    bool init();

    bool onTouchBegan(Touch* touch, Event* event);

    void onTouchMoved(Touch* touch, Event* event);

    void onTouchEnded(Touch* touch, Event* event);

    void performSkill(Vec2 target);

    CREATE_FUNC(DarkBall);

private:
    float lastAngleRotate;
    Vec2 dir;
};

#endif 
