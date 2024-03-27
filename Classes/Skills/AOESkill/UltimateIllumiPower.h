#ifndef __ULTIMATE_ILLUMI_POWER_H__
#define __ULTIMATE_ILLUMI_POWER_H__

#include "cocos2d.h"
#include "AOESkill.h"
USING_NS_CC;

class UltimateIllumiPower : public AOESkill
{
public:
    //Init
    bool init();

    bool onTouchBegan(Touch* touch, Event* event);

    void onTouchMoved(Touch* touch, Event* event);

    void onTouchEnded(Touch* touch, Event* event);

    void performSkill(Vec2 target);

    CREATE_FUNC(UltimateIllumiPower);
private:
    Vec2 dir;
    float lastAngleRotate;
};

#endif 
