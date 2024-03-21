#include "SkillFactory.h"

SkillBase* SkillFactory::createSkill(std::string skillType) {
	SkillBase* result;
	if (skillType == "AOESkill1") {
		result = AOESkill1::create();
	}
	if (skillType == "AOESkill2") {
		result = AOESkill2::create();
	}
	if (skillType == "BuffSkill1") {
		result = BuffSkill1::create();
	}
	if (skillType == "BuffSkill2") {
		result = BuffSkill2::create();
	}
	if (skillType == "TargetSkill1") {
		result = TargetSkill1::create();
	}
	if (skillType == "TargetSkill2") {
		result = TargetSkill2::create();
	}
	if (skillType == "SkillShot1") {
		result = SkillShot1::create();
	}
	if (skillType == "SkillShot2") {
		result = SkillShot2::create();
	}
	return result;
}