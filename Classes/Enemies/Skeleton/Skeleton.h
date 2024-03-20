#ifndef __SKELETON_H__
#define __SKELETON_H__

#include "cocos2d.h"
#include "../Enemy.h"
USING_NS_CC;

class Skeleton : public Enemy
{
public:
    virtual bool init();
    //Cac phuong thuc danh rieng cho Enemies
    void loadAnimate();

    CREATE_FUNC(Skeleton);
private:
};

#endif 
