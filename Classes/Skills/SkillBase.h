#ifndef __SKILL_BASE_H__
#define __SKILL_BASE_H__

#include "cocos2d.h"
#include "UserInterface/InGame/SkillButton.h"
#include "Engine/Engine.h"

USING_NS_CC;
class SkillBase : public Node
{
public:
    struct SkillTalent {
        std::string skillName;
        std::string iconPath;
        int unlockPoint;
        std::string description;
        std::string skillType;
        SkillBase::SkillTalent* parent;
        std::vector<SkillBase::SkillTalent*> children;
        bool isLock;
    };
    //Init
    bool init();

    bool onTouchBegan(Touch* touch, Event* event);

    void onTouchMoved(Touch* touch, Event* event);

    void onTouchEnded(Touch* touch, Event* event);

    void performSkill(Vec2 target);

    void update(float dt);

    int getUnlockScore() const { return this->unlockScore; };
    void unlock() {
        if (isLocked) {
            isLocked = false;
            this->removeChildByName("overlay");
        }
        /*...*/
    };
    bool isLock() const { return isLocked; };

    std::string getSkillName() const { return skillName; };

    void setSkillIconSprite(Sprite* spr) { _iconSprite = spr; };
    
    Sprite* getSkillIconSprite() const { return this->_iconSprite; };

    Size getSkillIconSize() const { return _iconSprite->getContentSize(); };

    SkillTalent* getSkillTalent() const { return skillTalent; };

    SkillTalent* skillTalent;
    ////About SkillTree
    SkillBase* parent;

    std::vector<SkillBase*> children;

    //protected:
    Sprite* _iconSprite;
    Sprite* _aoeSprite;
    Sprite* _skillSprite;

    Animate* _skillAnimate;

    SkillButton* _skillButton;

    Vec2 lastTarget;
    Vec2 cursorPos;

    float range;
    bool isLocked = true;
    int unlockScore;
    std::string skillName;
    std::string iconSpritePath;
};

#endif 
