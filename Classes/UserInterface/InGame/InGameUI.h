#ifndef __INGAME_UI__
#define __INGAME_UI__

#include "cocos2d.h"
USING_NS_CC;

class PlayerCharacter;
class Joystick;
class InGameUI : public cocos2d::Layer
{
public:
    static InGameUI* create(PlayerCharacter* player);
    virtual bool init(PlayerCharacter* player);
    void update(float dt);
private: 
    PlayerCharacter* _player;
    Joystick* _joystick;
};

#endif // __JOYSTICK_H__