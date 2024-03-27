#ifndef __AOE_SKILL_H__
#define __AOE_SKILL_H__

#include "cocos2d.h"
#include "Skills/SkillBase.h"
USING_NS_CC;

class AOESkill : public SkillBase
{
public:
    bool init();
    CREATE_FUNC(AOESkill);
};

#endif 
