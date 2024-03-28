#ifndef __TALENT_CAROUSEL__
#define __TALENT_CAROUSEL__

#include "cocos2d.h"
USING_NS_CC;

class SkillTree;
class PlayerCharacter;
class TalentCarousel : public cocos2d::Node
{
public:
    static TalentCarousel* create(PlayerCharacter* player);
    virtual bool init(PlayerCharacter* player);
    bool onTouchBegan(Touch* touch, Event* event);
    bool onTouchMoved(Touch* touch, Event* event);
    bool onTouchEnded(Touch* touch, Event* event);
    void showTalentCarousel();
private: 
    Sprite* talentBorder;
    Sprite* prevButton;
    Sprite* nextButton;
    Sprite* buttonClose;
    std::vector<SkillTree*> listOfTrees;
    int currentTree = 0;
};

#endif // __JOYSTICK_H__