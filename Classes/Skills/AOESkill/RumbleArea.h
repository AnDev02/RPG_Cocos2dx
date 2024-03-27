#ifndef __RUMBLE_AREA_H__
#define __RUMBLE_AREA_H__

#include "cocos2d.h"
#include "AOESkill.h"
USING_NS_CC;

class RumbleArea : public AOESkill
{
public:
    //Init
    bool init();

    bool onTouchBegan(Touch* touch, Event* event);

    void onTouchMoved(Touch* touch, Event* event);

    void onTouchEnded(Touch* touch, Event* event);

    void performSkill(Vec2 target);

    CREATE_FUNC(RumbleArea);
private:
    Vec2 dir;
    float lastAngleRotate;
};

#endif 
