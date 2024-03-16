#ifndef __FIGHTER_H__
#define __FIGHTER_H__

#include "cocos2d.h"
#include "PlayerCharacter.h"
USING_NS_CC;

class Fighter : public PlayerCharacter
{
public:
    virtual bool init();
    //Cac phuong thuc danh rieng cho Player
    void loadAnimate();
    CREATE_FUNC(Fighter);

private:
};

#endif // 
