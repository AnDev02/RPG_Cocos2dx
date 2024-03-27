#ifndef __DARK_SPEAR_H__
#define __DARK_SPEAR_H__

#include "cocos2d.h"
#include "SkillShot.h"
USING_NS_CC;

class DarkSpear : public SkillShot
{
public:
    //Init
    bool init();

    bool onTouchBegan(Touch* touch, Event* event);

    void onTouchMoved(Touch* touch, Event* event);

    void onTouchEnded(Touch* touch, Event* event);

    void performSkill(Vec2 target);

    CREATE_FUNC(DarkSpear);

private:
    float lastAngleRotate;
    Vec2 dir;
};

#endif 
