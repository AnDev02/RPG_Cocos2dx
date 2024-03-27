#include "SkillFactory.h"

SkillBase* SkillFactory::createSkill(std::string skillType) {
	SkillBase* result;
	
	//AOE Skill
	if (skillType == "DarkHole") {
		result = DarkHole::create();
	}
	if (skillType == "ElectricArea") {
		result = ElectricArea::create();
	}
	if (skillType == "FireFlower") {
		result = FireFlower::create();
	}
	if (skillType == "IllumiArea") {
		result = IllumiArea::create();
	}
	if (skillType == "RumbleArea") {
		result = RumbleArea::create();
	}
	if (skillType == "ShadowArea") {
		result = ShadowArea::create();
	}
	if (skillType == "UltimateIllumiPower") {
		result = UltimateIllumiPower::create();
	}

	//Buff Skill
	if (skillType == "FireHurricane") {
		result = FireHurricane::create();
	}
	if (skillType == "FireShield") {
		result = FireShield::create();
	}
	if (skillType == "HealingBuff") {
		result = HealingBuff::create();
	}
	if (skillType == "IllumiShield") {
		result = IllumiShield::create();
	}
	if (skillType == "ShadowShield") {
		result = ShadowShield::create();
	}
	//Skill Shot
	if (skillType == "DarkBall") {
		result = DarkBall::create();
	}
	if (skillType == "DarkSpear") {
		result = DarkSpear::create();
	}
	if (skillType == "FireBall") {
		result = FireBall::create();
	}
	if (skillType == "IllumiBall") {
		result = IllumiBall::create();
	}
	if (skillType == "IllumiWave") {
		result = IllumiWave::create();
	}
	if (skillType == "ShadowHurricane") {
		result = ShadowHurricane::create();
	}
	if (skillType == "ShadowWave") {
		result = ShadowWave::create();
	}
	//Target Skill
	return result;
}