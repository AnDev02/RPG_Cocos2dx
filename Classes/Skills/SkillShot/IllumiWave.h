#ifndef __ILLUMI_WAVE_H__
#define __ILLUMI_WAVE_H__

#include "cocos2d.h"
#include "SkillShot.h"
USING_NS_CC;

class IllumiWave : public SkillShot
{
public:
    //Init
    bool init();

    bool onTouchBegan(Touch* touch, Event* event);

    void onTouchMoved(Touch* touch, Event* event);

    void onTouchEnded(Touch* touch, Event* event);

    void performSkill(Vec2 target);

    CREATE_FUNC(IllumiWave);

private:
    float lastAngleRotate;
    Vec2 dir;
};

#endif 
