#ifndef __KNIGHT_H__
#define __KNIGHT_H__

#include "cocos2d.h"
#include "../PlayerCharacter.h"
USING_NS_CC;

class Knight : public PlayerCharacter
{
public:
    virtual bool init();
    //Cac phuong thuc danh rieng cho Player
    void loadAnimate();
    CREATE_FUNC(Knight);

private:
};

#endif // 
