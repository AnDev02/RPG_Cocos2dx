#ifndef __SKILL_SHOT_H__
#define __SKILL_SHOT_H__

#include "cocos2d.h"
#include "Skills/SkillBase.h"
USING_NS_CC;

class SkillShot : public SkillBase
{
public:

    bool init();

    bool onTouchBegan(Touch* touch, Event* event);

    void onTouchMoved(Touch* touch, Event* event);

    void onTouchEnded(Touch* touch, Event* event);

    void performSkill(Vec2 target);

    void update(float dt);

    CREATE_FUNC(SkillShot);
private:
    Vec2 dir;
    float lastAngleRotate;
};

#endif 
