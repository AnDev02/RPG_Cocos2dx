#ifndef __TALENT_CAROUSEL__
#define __TALENT_CAROUSEL__

#include "cocos2d.h"
USING_NS_CC;
class SkillTree;
class Player;
class TalentProgressBar;
class TalentCarousel : public cocos2d::Node
{
public:
    static TalentCarousel* create(Player* player);
    virtual bool init(Player* player);
    bool onTouchBegan(Touch* touch, Event* event);
    bool onTouchMoved(Touch* touch, Event* event);
    bool onTouchEnded(Touch* touch, Event* event);
    void showTalentCarousel();
    Player* _player = nullptr;
    SkillTree* skillTreeAoe = nullptr;
    SkillTree* skillTreeBuff = nullptr;
    TalentProgressBar* progressBar;
    void hideComponents();
    void showComponents();
    void resetUI();
    std::vector<SkillTree*> listOfTrees;
    EventListenerTouchOneByOne* touchListener = nullptr;
private: 
    Sprite* talentBorder;
    Sprite* prevButton;
    Sprite* nextButton;
    Sprite* buttonClose;
    bool lastChoosedFirstTab;
    Sprite* fireTreeTabButton;
    Sprite* thunderTreeTabButton;
    int currentTree = 0;
};

#endif // __JOYSTICK_H__