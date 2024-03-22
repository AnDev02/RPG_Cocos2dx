#ifndef __AOE_SKILL2_H__
#define __AOE_SKILL2_H__

#include "cocos2d.h"
#include "AOESkill.h"
USING_NS_CC;

class AOESkill2 : public AOESkill
{
public:
    virtual bool init();
    void update(float dt);
    CREATE_FUNC(AOESkill2);
    
};

#endif 
