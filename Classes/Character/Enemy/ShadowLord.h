#ifndef __SHADOW_LORD_H__
#define __SHADOW_LORD_H__

#include "cocos2d.h"
#include "Enemies.h"
USING_NS_CC;

class ShadowLord : public Enemies
{
public:
    virtual bool init();
    //Cac phuong thuc danh rieng cho Enemies

    CREATE_FUNC(ShadowLord);
private:
};

#endif 
