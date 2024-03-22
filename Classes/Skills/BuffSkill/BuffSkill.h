#ifndef __BUFF_SKILL_H__
#define __BUFF_SKILL_H__

#include "cocos2d.h"
#include "Skills/SkillBase.h"

USING_NS_CC;

class BuffSkill : public SkillBase
{
public:

    virtual bool init() override;

    virtual bool onTouchBegan(Touch* touch, Event* event) override;

    virtual void onTouchMoved(Touch* touch, Event* event) override;

    virtual void onTouchEnded(Touch* touch, Event* event) override;

    virtual void performSkill(Vec2 target) override;

    virtual void update(float dt) override;

    CREATE_FUNC(BuffSkill);
};

#endif 
