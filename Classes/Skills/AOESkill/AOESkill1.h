#ifndef __AOE_SKILL1_H__
#define __AOE_SKILL1_H__

#include "cocos2d.h"
#include "AOESkill.h"
USING_NS_CC;

class AOESkill1 : public AOESkill
{
public:
    virtual bool init();
    void update(float dt);
    CREATE_FUNC(AOESkill1);
};

#endif 
