#ifndef __SKILL_BASE_H__
#define __SKILL_BASE_H__

#include "cocos2d.h"

USING_NS_CC;

class SkillBase : public Node
{
public:
    //Init
    virtual bool init() = 0;

    //About Implement Skill
    virtual void activate() = 0;

    virtual void deactivate() = 0;

    virtual void onMouseMove(Event* event) = 0;

    virtual void performSkill(Vec2 target) = 0;

    ////About SkillTree
    //SkillBase* parent;

    //std::vector<SkillBase*> children;

    //virtual int getUnlockScore() = 0;

    //virtual void unlock() = 0;

    //virtual bool isLock() = 0;
    ////
protected:
    Sprite* _aoeSprite;
    Sprite* _iconSprite;
    Sprite* _skillSprite;

    Vec2 lastTarget;
    Vec2 cursorPos;

    bool isLocked = true;
    int unlockScore;
    std::string skillName;
};

#endif 
