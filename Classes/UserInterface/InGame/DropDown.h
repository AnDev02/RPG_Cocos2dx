#ifndef __DROPDOWN__
#define __DROPDOWN__

#include "cocos2d.h"
USING_NS_CC;
class InGameUI;
class InventoryButton;
class TalentButton;
class Dropdown : public cocos2d::Node
{
public:
    static Dropdown* create();
    virtual bool init();
    bool onTouchBegan(Touch* touch, Event* event);
    Sprite* bg = nullptr;
    Sprite* iconSprite;
    void updateIconSpritePosition();
    bool didOpen() { return isOpen == true && isScaling == false; }
    InGameUI* inGameUI = nullptr;
    InventoryButton* inventoryButton = nullptr;
    TalentButton* talentButton = nullptr;
private:
    Sprite* toggleButton = nullptr;
    bool isOpen = false;
    bool isScaling = false;
};

#endif // __JOYSTICK_H__