#ifndef __BUFF_SKILL_H__
#define __BUFF_SKILL_H__

#include "cocos2d.h"
#include "Skills/SkillBase.h"
USING_NS_CC;

class BuffSkill : public SkillBase
{
public:
    bool init();
    CREATE_FUNC(BuffSkill);
};

#endif 
