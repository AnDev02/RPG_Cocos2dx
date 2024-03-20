#ifndef __SLIME_H__
#define __SLIME_H__

#include "cocos2d.h"
#include "../Enemy.h"
USING_NS_CC;

class Slime : public Enemy
{
public:
    virtual bool init();
    //Cac phuong thuc danh rieng cho Enemies
    void loadAnimate();

    CREATE_FUNC(Slime);
private:
};

#endif 
