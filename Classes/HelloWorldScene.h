#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Character/PlayerCharacter/PlayerCharacter.h"
#include "Character/PlayerCharacter/PlayerCharacterFactory.h"
#include "Character/Enemy/Enemies.h"
#include "Character/Enemy/EnemiesFactory.h"
#include "Character/Boss/BossFactory.h"
#include "Character/Boss/Boss.h"
USING_NS_CC;

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void update(float dt);

    //PlayerCharacter
    void loadFighterToCache();
    void loadKnightToCache();

    //Enemies
    void loadSkeletonToCache();
    void loadSlimeToCache();

    //Boss
    void loadHellBeastToCache();

    CREATE_FUNC(HelloWorld);
private:
    cocos2d::PhysicsWorld* world;
    void setPhysicsWorld(cocos2d::PhysicsWorld* m_world) {
        m_world = world;
    }
    PlayerCharacter* playerCharacter;
    Enemies* enemy;
    Boss* boss;
};

#endif // __HELLOWORLD_SCENE_H__
