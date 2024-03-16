#ifndef __WARRIOR_H__
#define __WARRIOR_H__

#include "cocos2d.h"
#include "PlayerCharacter.h"
USING_NS_CC;

class Warrior : public PlayerCharacter
{
public:
    virtual bool init();
    //Cac phuong thuc danh rieng cho Player
    CREATE_FUNC(Warrior);

private:
};

#endif // 
