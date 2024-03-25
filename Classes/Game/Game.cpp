#include "Game.h"
#include "Skills/SkillFactory.h"
#include "Skills/SkillBase.h"
#include "UserInterface/InGame/Minimap.h"
#include "UserInterface/InGame/InventoryButton.h"
#include "MapDecoration/MapDecoration.h"
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
    _tileMap->initWithTMXFile("map/BossRoom1.tmx");
    this->addChild(_tileMap);
    MapDecoration* mapDecoration = MapDecoration::getInstance(_tileMap);
    MapDecoration::getInstance()->loadDecoration("flames");
    MapDecoration::getInstance()->loadDecoration("subservients working");
    MapDecoration::getInstance()->loadDecoration("torch");
    MapDecoration::getInstance()->loadDecoration("Obelisk");
    MapDecoration::getInstance()->loadDecoration("End Point");
    MapDecoration::getInstance()->loadDecoration("BloodMoon Tower");



    _player = PlayerCharacterFactory::createPlayerCharacter("Knight");
    _player->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    _player->currentState = _player->idleState;
    _player->currentState->EnterState();
    this->addChild(_player);

    minimap = MinimapLayer::create("map/BossRoom1.tmx", _player);
    minimap->setPosition(_player->getPosition() / zoomLevel);
    minimap->setScale(minimap->MINIMAP_SCALE_FACTOR);
    this->addChild(minimap);

    inventory = Inventory::createInventory(zoomLevel, _player);
    inventory->setScale(1);
    this->addChild(inventory, 20);

    inventoryButton = InventoryButton::create(inventory);
    inventoryButton->setPosition(_player->getPosition());
    inventoryButton->setScale(0.3);
    this->addChild(inventoryButton, 5);

    healthBar = HealthBar::create("res/health-bar-border.png", "res/health-bar-inside.png", 10000, 5000);
    healthBar->setPosition(_player->getPosition());
    healthBar->decreaseHealth(7000);
    healthBar->decreaseMana(2500);
    healthBar->setScale(0.2);
    this->addChild(healthBar, 5);

    _joystick = Joystick::create();
    _joystick->setPosition(_player->getPosition());
    _joystick->setScale(0.7);
    this->addChild(_joystick);

    //BOSS
    // boss = BossFactory::createBoss("HellBeast");
    //boss->setPosition(Vec2(900, 500));
    //boss->setName("HellBeast");
    //this->addChild(boss);
    //boss->currentState = boss->roarState;
    //boss->currentState->EnterState();
    return true;
}

void Game::updatePlayer(float dt)
{
    /*enemy->currentState->UpdateState();*/
    if(_joystick)
        _player->movementDirection = _joystick->getDirection();
    _player->currentState->UpdateState();
    //boss->currentState->UpdateState();
}

void Game::updateCamera(float deltaT)
{
     float movementspeed = _player->getMovementSpeed();
     Vec2 newposition = _player->getPosition();
     Scene *currentscene = Director::getInstance()->getRunningScene();
      currentscene->setScale(zoomLevel);
      Vec2 cameraposition = Vec2((-newposition.x + visibleSize.width * 0.5) * zoomLevel,
                                 (-newposition.y + visibleSize.height * 0.5) * zoomLevel);
     currentscene->setPosition(cameraposition);
     minimap->setPosition((cameraposition * -1 / zoomLevel) + (Vec2(visibleSize.width / 3.5, visibleSize.height / 6.2) / zoomLevel));
}

void Game::updateUserInterface(float dt) {
    //minimap->setPosition(_player->getPosition());

    inventoryButton->setPosition(_player->getPosition() - Vec2(-(visibleSize.width / 4 / zoomLevel), visibleSize.height / 2 / zoomLevel - (inventoryButton->getSpriteSize().height)));
    if(inventory->isShow()) inventory->setPosition(_player->getPosition() - Vec2((visibleSize.width / 2 / zoomLevel), 0));
    CCLOG("%f healthBar->getHeight()", healthBar->getHeight());
    healthBar->setPosition(_player->getPosition() - Vec2(0, visibleSize.height / 2 / zoomLevel - healthBar->getHeight()));
    //visibleSize.height / 2 / zoomLevel - (healthBar->getHeight())
    _joystick->setPosition(_player->getPosition() - Vec2((visibleSize.width / 2.7 / zoomLevel), visibleSize.height / 2 / zoomLevel - (_joystick->getSize().height * 0.8)));
}