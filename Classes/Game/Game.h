#ifndef __GAME_H__
#define __GAME_H__

#include "cocos2d.h"
#include "../PlayerCharacters/PlayerCharacter.h"
#include "../PlayerCharacters/PlayerCharacterFactory.h"
#include "../Enemies/Enemy.h"
#include "../Enemies/EnemyFactory.h"
#include "../UserInterface/InGame/Joystick.h"
#include "../Boss/BossFactory.h"
#include "../UserInterface/InGame/Minimap.h"
#include "../Inventory/Inventory.h"

USING_NS_CC;
class InventoryButton;
class Game : public cocos2d::Scene
{
public:
    static Scene *createGame();
    virtual bool init();
    CREATE_FUNC(Game);
private:
    void updateCamera(float dt);
    void updatePlayer(float dt);
    void updateUserInterface(float dt);
    InventoryButton* inventoryButton;
    MinimapLayer* minimap;
    PlayerCharacter* _player;
    float zoomLevel;
    Joystick* _joystick;
    Size visibleSize;
    Boss* boss;
    Inventory* inventory;
    cocos2d::PhysicsWorld* world;
    void setPhysicsWorld(cocos2d::PhysicsWorld* m_world) {
        m_world = world;
    }
};

#endif // __GAME_H__