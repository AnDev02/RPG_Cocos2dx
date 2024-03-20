#ifndef __SHADOW_LORD_H__
#define __SHADOW_LORD_H__

#include "cocos2d.h"
#include "../Enemy.h"
USING_NS_CC;

class ShadowLord : public Enemy
{
public:
    virtual bool init();

    void loadAnimate();
    CREATE_FUNC(ShadowLord);
private:
};

#endif 
