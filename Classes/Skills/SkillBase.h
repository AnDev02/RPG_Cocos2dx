#ifndef __SKILL_BASE_H__
#define __SKILL_BASE_H__

#include "cocos2d.h"
#include "UserInterface/InGame/SkillButton.h"


USING_NS_CC;

class SkillBase : public Node
{
public:
    //Init
    virtual bool init() = 0;

    virtual bool onTouchBegan(Touch* touch, Event* event) = 0;

    virtual void onTouchMoved(Touch* touch, Event* event) = 0;

    virtual void onTouchEnded(Touch* touch, Event* event) = 0;

    virtual void performSkill(Vec2 target) = 0;

    virtual void update(float dt) = 0;

    //// Phương thức xử lý sự kiện chạm
    //virtual bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);
    //virtual void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);

    ////About SkillTree
    //SkillBase* parent;

    //std::vector<SkillBase*> children;

    //virtual int getUnlockScore() = 0;

    //virtual void unlock() = 0;

    //virtual bool isLock() = 0;
    // 
    ////

protected:
    Sprite* _iconSprite;
    Sprite* _aoeSprite;
    Sprite* _skillSprite;
    SkillButton* _skillButton;

    Vec2 lastTarget;
    Vec2 cursorPos;

    float range;
    bool isLocked = true;
    int unlockScore;
    std::string skillName;
};

#endif 
