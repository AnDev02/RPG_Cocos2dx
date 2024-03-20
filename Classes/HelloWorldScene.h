#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "./PlayerCharacters/PlayerCharacter.h"
#include "./PlayerCharacters/PlayerCharacterFactory.h"
#include "./Enemies/Enemy.h"
#include "./Enemies/EnemyFactory.h"
#include "./Game/Game.h"
class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    void menuCloseCallback(cocos2d::Ref* pSender);

    void update(float dt);
    void loadFighterToCache();
    void loadKnightToCache();
    void loadSkeletonToCache();
    void loadSlimeToCache();
    void loadHellBeastToCache();
    CREATE_FUNC(HelloWorld);
private:
    cocos2d::PhysicsWorld* world;
    Game* game;
    void setPhysicsWorld(cocos2d::PhysicsWorld* m_world) {
        m_world = world;
    }
    PlayerCharacter* playerCharacter;
    Enemy* enemy;
};

#endif // __HELLOWORLD_SCENE_H__
