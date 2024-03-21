#ifndef __BUFF_SKILL_H__
#define __BUFF_SKILL_H__

#include "cocos2d.h"
#include "Skills/SkillBase.h"
USING_NS_CC;

class BuffSkill : public SkillBase
{
public:
    //Init
    virtual bool init() override;

    //About Implement Skill
    virtual void activate() override;

    virtual void deactivate() override;

    virtual void onMouseMove(Event* event) override;

    virtual void performSkill(Vec2 target) override;

    ////About SkillTree
    //SkillBase* parent;

    //std::vector<SkillBase*> children;

    //virtual int getUnlockScore() override;

    //virtual void unlock() override;

    //virtual bool isLock() override;
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
