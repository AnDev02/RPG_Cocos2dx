#ifndef __TARGET_SKILL_H__
#define __TARGET_SKILL_H__

#include "cocos2d.h"
#include "Skills/SkillBase.h"
class Enemy;
USING_NS_CC;

class TargetSkill : public SkillBase
{
public:
    bool init();

    bool onTouchBegan(Touch* touch, Event* event);

    void onTouchMoved(Touch* touch, Event* event);

    void onTouchEnded(Touch* touch, Event* event);

    void performSkill(Vec2 target);

    void update(float dt);

    CREATE_FUNC(TargetSkill);

protected:
    float applyRange;
    Sprite* _targetSprite;
    std::vector<Enemy*> enemies;
    
};

#endif 
