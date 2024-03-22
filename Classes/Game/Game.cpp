#include "Game.h"
#include "Skills/SkillFactory.h"
#include "Skills/SkillBase.h"
#include "UserInterface/InGame/Minimap.h"
#include "UserInterface/InGame/InventoryButton.h"

Scene *Game::createGame()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -98));
    scene->getPhysicsWorld()->setSubsteps(10);
    auto layer = Game::create();
    layer->setName("GameInstance");
    layer->setPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}

bool Game::init()
{
    if (!Scene::initWithPhysics())
    {
        return false;
    }

    visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    schedule(CC_SCHEDULE_SELECTOR(Game::updatePlayer), 0.06f);
    schedule(CC_SCHEDULE_SELECTOR(Game::updateUserInterface), 0.0f);

    this->schedule([this](float dt)
                   { this->updateCamera(dt); },
                   "update_camera");

    // zoomLevel cua camera
    zoomLevel = (visibleSize.width / visibleSize.height);

    auto emitter = ParticleRain::create();
    addChild(emitter, 10);

    cocos2d::TMXTiledMap *_tileMap = new TMXTiledMap();
    _tileMap->initWithTMXFile("map/Map0.tmx");
    this->addChild(_tileMap);



    _player = PlayerCharacterFactory::createPlayerCharacter("Knight");
    _player->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    _player->currentState = _player->idleState;
    _player->currentState->EnterState();
    this->addChild(_player);

    minimap = MinimapLayer::create("map/Map0.tmx", _player);
    minimap->setPosition(_player->getPosition() / zoomLevel);
    minimap->setScale(minimap->MINIMAP_SCALE_FACTOR);
    this->addChild(minimap);

    inventory = Inventory::createInventory();
    inventory->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    inventory->setScale(3);
    this->addChild(inventory, 6);

    inventoryButton = InventoryButton::create(inventory);
    inventoryButton->setPosition(_player->getPosition());
    this->addChild(inventoryButton, 5);

    //BOSS
  /*  boss = BossFactory::createBoss("HellBeast");
    boss->setPosition(Vec2(900, 500));
    boss->setName("HellBeast");
    this->addChild(boss);
    boss->currentState = boss->roarState;
    boss->currentState->EnterState();*/
    return true;
}


void Game::updatePlayer(float dt)
{
    /*enemy->currentState->UpdateState();*/
    _player->currentState->UpdateState();
    //boss->currentState->UpdateState();
}

void Game::updateCamera(float deltaT)
{
     float movementspeed = _player->getMovementSpeed();
     Vec2 newposition = _player->getPosition();
     Scene *currentscene = Director::getInstance()->getRunningScene();
      currentscene->setScale(zoomLevel);
     Vec2 cameraposition = Vec2(-newposition.x * zoomLevel + (visibleSize.width / 2 * zoomLevel),
                               -newposition.y * zoomLevel + (visibleSize.height / 2 * zoomLevel));
     currentscene->setPosition(cameraposition);
     minimap->setPosition((cameraposition * -1 / zoomLevel) + (Vec2(visibleSize.width / 4, visibleSize.height / 4) / zoomLevel));
}

void Game::updateUserInterface(float dt) {
    inventoryButton->setPosition(_player->getPosition() - Vec2(-(visibleSize.width / 6 / zoomLevel), visibleSize.height / 2 / zoomLevel - (inventoryButton->getSpriteSize().height * 2)));
    if(inventory->isShow())
        inventory->setPosition(_player->getPosition());
}