#ifndef __BUFF_SKILL_H__
#define __BUFF_SKILL_H__

#include "cocos2d.h"
#include "Skills/SkillBase.h"

USING_NS_CC;

class BuffSkill : public SkillBase
{
public:

    bool init();

    bool onTouchBegan(Touch* touch, Event* event);

    void onTouchMoved(Touch* touch, Event* event);

    void onTouchEnded(Touch* touch, Event* event);

    void performSkill(Vec2 target);

    void update(float dt);

    CREATE_FUNC(BuffSkill);
};

#endif 
