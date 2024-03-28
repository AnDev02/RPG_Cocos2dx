#ifndef __SKILL_TREE__
#define __SKILL_TREE__

#include "cocos2d.h"
#include "SkillBase.h"
#include "SkillFactory.h"
USING_NS_CC;
class PlayerCharacter;
class SkillTree : public cocos2d::Node
{
public:
	static SkillTree* createSkillTree(PlayerCharacter* player, SkillBase::SkillTalent* skillRoot);
	virtual bool init(PlayerCharacter* player, SkillBase::SkillTalent* skillRoot);
	void drawTree(SkillBase::SkillTalent* node, Vec2 position, float xSpacing, float ySpacing, SkillBase::SkillTalent* parent);
	~SkillTree();
	float treeHeight = 0;
private:
	Size visibleSize;
	std::vector<std::tuple<SkillBase::SkillTalent*, Node*> > skillRects;
	Label* moneyLabel;
	int childrenQuan = 0;
};

#endif // __SKILL_TREE__
