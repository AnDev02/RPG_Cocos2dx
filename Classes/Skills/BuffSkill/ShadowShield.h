#ifndef __SHADOW_SHIELD_H__
#define __SHADOW_SHIELD_H__

#include "cocos2d.h"
#include "BuffSkill.h"
USING_NS_CC;

class ShadowShield : public BuffSkill
{
public:
    //Init
    bool init();

    bool onTouchBegan(Touch* touch, Event* event);

    void onTouchMoved(Touch* touch, Event* event);

    void onTouchEnded(Touch* touch, Event* event);

    void performSkill(Vec2 target);

    CREATE_FUNC(ShadowShield);
};

#endif 
