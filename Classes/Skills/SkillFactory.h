#ifndef __SKILL_FACTORY_H__
#define __SKILL_FACTORY_H__

#include "cocos2d.h"
#include "SkillBase.h"
#include "AOESkill/DarkHole.h"
#include "AOESkill/ElectricArea.h"
#include "AOESkill/FireFlower.h"
#include "AOESkill/IllumiArea.h"
#include "AOESkill/RumbleArea.h"
#include "AOESkill/ShadowArea.h"
#include "AOESkill/UltimateIllumiPower.h"

#include "BuffSkill/FireHurricane.h"
#include "BuffSkill/FireShield.h"
#include "BuffSkill/HealingBuff.h"
#include "BuffSkill/IllumiShield.h"
#include "BuffSkill/ShadowShield.h"

#include "SkillShot/DarkBall.h"
#include "SkillShot/DarkSpear.h"
#include "SkillShot/FireBall.h"
#include "SkillShot/IllumiBall.h"
#include "SkillShot/IllumiWave.h"
#include "SkillShot/ShadowHurricane.h"
#include "SkillShot/ShadowWave.h"

USING_NS_CC;

class SkillFactory
{
public:
    static SkillBase* createSkill(std::string skillType);
};

#endif 
