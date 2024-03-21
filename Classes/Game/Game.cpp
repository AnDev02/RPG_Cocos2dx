#include "Game.h"
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
    schedule(CC_SCHEDULE_SELECTOR(Game::updateUserInterface), 0.06f);

    this->schedule([this](float dt)
                   { this->updateCamera(dt); },
                   "update_camera");

    // zoomLevel cua camera
    zoomLevel = (visibleSize.width / visibleSize.height) * 1.5625;

    auto emitter = ParticleRain::create();
    addChild(emitter, 10);

    cocos2d::TMXTiledMap *_tileMap = new TMXTiledMap();
    _tileMap->initWithTMXFile("map/Map1.tmx");
    this->addChild(_tileMap);
    MapDecoration* mapDecoration = MapDecoration::getInstance(_tileMap);
    MapDecoration::getInstance()->loadDecoration("flames");
    MapDecoration::getInstance()->loadDecoration("subservients working");
    MapDecoration::getInstance()->loadDecoration("torch");
    MapDecoration::getInstance()->loadDecoration("Obelisk");


    _player = PlayerCharacterFactory::createPlayerCharacter("Knight");
    _player->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    _player->currentState = _player->idleState;
    _player->currentState->EnterState();
    this->addChild(_player);

    //BOSS
    boss = BossFactory::createBoss("HellBeast");
    boss->setPosition(Vec2(900, 500));
    boss->setName("HellBeast");
    this->addChild(boss);
    boss->currentState = boss->roarState;
    boss->currentState->EnterState();




    return true;
}


void Game::updatePlayer(float dt)
{
    /*enemy->currentState->UpdateState();*/
    _player->currentState->UpdateState();
    boss->currentState->UpdateState();
    
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
}

void Game::updateUserInterface(float dt) {
}