#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include "cocos2d.h"
USING_NS_CC;

class Character : public Node
{
public:
    virtual bool init();

    void takeDamage(float amountDamage);

    void dealDamage(Node* target);

    //Direction
    int getCurrentDirection() const{
        return this->direction;
    }
    void setCurrentDirection(int newDirection) {
        this->direction = newDirection;
    }
    //AttackRange
    float getAttackRange() const{
        return this->attackRange;
    }
    void setAttackRange(float newAttackRange) {
        this->attackRange = newAttackRange;
    }
    //MovementSpeed
    float getMovementSpeed() const {
        return this->MS;
    }
    void setMovementSpeed(float newMovementSpeed) {
        this->MS = newMovementSpeed;
    }

    //Sprite
    Sprite* getCurrentSprite() const {
        return this->characterCurrentSprite;
    }
    void setSprite(Sprite* newSprite) {
        characterCurrentSprite = newSprite;
    }

    CREATE_FUNC(Character);
protected:
    float HP;
    float MP;
    float armor;
    float CDR;
    float damage;
    float MS;
    int direction;
    float attackRange;
    Sprite* characterCurrentSprite;
    //std::vector<Skill*> skills;
};

#endif // __HELLOWORLD_SCENE_H__



