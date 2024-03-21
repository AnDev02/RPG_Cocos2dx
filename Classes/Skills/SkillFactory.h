#ifndef __SKILL_FACTORY_H__
#define __SKILL_FACTORY_H__

#include "cocos2d.h"
#include "SkillBase.h"
#include "SkillShot/SkillShot1.h"
#include "SkillShot/SkillShot2.h"
#include "AOESkill/AOESkill1.h"
#include "AOESkill/AOESkill2.h"
#include "BuffSkill/BuffSkill1.h"
#include "BuffSkill/BuffSkill2.h"
#include "TargetSkill/TargetSkill1.h"
#include "TargetSkill/TargetSkill2.h"

USING_NS_CC;

class SkillFactory
{
public:
    static SkillBase* createSkill(std::string skillType);
};

#endif 
