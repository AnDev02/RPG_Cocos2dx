#ifndef __TARGET_SKILL_H__
#define __TARGET_SKILL_H__

#include "cocos2d.h"
#include "Skills/SkillBase.h"
class Enemy;
USING_NS_CC;

class TargetSkill : public SkillBase
{
public:
    virtual bool init() override;

    virtual bool onTouchBegan(Touch* touch, Event* event) override;

    virtual void onTouchMoved(Touch* touch, Event* event) override;

    virtual void onTouchEnded(Touch* touch, Event* event) override;

    virtual void performSkill(Vec2 target) override;

    virtual void update(float dt) override;

    CREATE_FUNC(TargetSkill);

protected:
    float applyRange;
    Sprite* _targetSprite;
    std::vector<Enemy*> enemies;
    
};

#endif 
