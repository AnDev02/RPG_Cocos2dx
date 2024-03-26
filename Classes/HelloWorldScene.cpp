#include "HelloWorldScene.h"
#include "./Inventory/Inventory.h"
USING_NS_CC;

Scene *HelloWorld::createScene()
{
    auto scene = Scene::createWithPhysics();
    scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    scene->getPhysicsWorld()->setGravity(Vec2(0, -98));
    scene->getPhysicsWorld()->setSubsteps(10);
    auto layer = HelloWorld::create();
    layer->setName("HelloWorldInstance");
    layer->setPhysicsWorld(scene->getPhysicsWorld());
    scene->addChild(layer);
    return scene;
}

static void problemLoading(const char *filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool HelloWorld::init()
{
    if (!Scene::init())
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();


    // loadFighterToCache();
    loadKnightToCache();

    // loadHellBeastToCache();
   // loadSlimeToCache();
    game = Game::create();
    if (game)
    {
        this->addChild(game);
    }
    // loadSkeletonToCache();

    // playerCharacter = PlayerCharacterFactory::createPlayerCharacter("Knight");
    // playerCharacter->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    // this->addChild(playerCharacter);

    /*CCLOG("Content size is: %f, %f", )*/

    // playerCharacter->currentState = playerCharacter->idleState;
    // playerCharacter->currentState->EnterState();


    // schedule(CC_SCHEDULE_SELECTOR(HelloWorld::update), 0.06f);
    return true;
}

void HelloWorld::menuCloseCallback(Ref *pSender)
{
    Director::getInstance()->end();
}

void HelloWorld::update(float dt)
{
    /*enemy->currentState->UpdateState();*/
    /*playerCharacter->currentState->UpdateState();*/
}

// Player Character
void HelloWorld::loadFighterToCache()
{
    // Armed Idle
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/E/fighter_armed_idle_E.plist", "playable character/fighter/fighter_armed_idle/E/fighter_armed_idle_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/N/fighter_armed_idle_N.plist", "playable character/fighter/fighter_armed_idle/N/fighter_armed_idle_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/NE/fighter_armed_idle_NE.plist", "playable character/fighter/fighter_armed_idle/NE/fighter_armed_idle_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/NEE/fighter_armed_idle_NEE.plist", "playable character/fighter/fighter_armed_idle/NEE/fighter_armed_idle_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/NNE/fighter_armed_idle_NNE.plist", "playable character/fighter/fighter_armed_idle/NNE/fighter_armed_idle_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/NNW/fighter_armed_idle_NNW.plist", "playable character/fighter/fighter_armed_idle/NNW/fighter_armed_idle_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/NW/fighter_armed_idle_NW.plist", "playable character/fighter/fighter_armed_idle/NW/fighter_armed_idle_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/NWW/fighter_armed_idle_NWW.plist", "playable character/fighter/fighter_armed_idle/NWW/fighter_armed_idle_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/S/fighter_armed_idle_S.plist", "playable character/fighter/fighter_armed_idle/S/fighter_armed_idle_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/SE/fighter_armed_idle_SE.plist", "playable character/fighter/fighter_armed_idle/SE/fighter_armed_idle_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/SEE/fighter_armed_idle_SEE.plist", "playable character/fighter/fighter_armed_idle/SEE/fighter_armed_idle_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/SSE/fighter_armed_idle_SSE.plist", "playable character/fighter/fighter_armed_idle/SSE/fighter_armed_idle_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/SSW/fighter_armed_idle_SSW.plist", "playable character/fighter/fighter_armed_idle/SSW/fighter_armed_idle_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/SW/fighter_armed_idle_SW.plist", "playable character/fighter/fighter_armed_idle/SW/fighter_armed_idle_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/SWW/fighter_armed_idle_SWW.plist", "playable character/fighter/fighter_armed_idle/SWW/fighter_armed_idle_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_idle/W/fighter_armed_idle_W.plist", "playable character/fighter/fighter_armed_idle/W/fighter_armed_idle_W.png");

    // Armed Attack
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/E/fighter_armed_attack_E.plist", "playable character/fighter/fighter_armed_attack/E/fighter_armed_attack_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/N/fighter_armed_attack_N.plist", "playable character/fighter/fighter_armed_attack/N/fighter_armed_attack_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/NE/fighter_armed_attack_NE.plist", "playable character/fighter/fighter_armed_attack/NE/fighter_armed_attack_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/NEE/fighter_armed_attack_NEE.plist", "playable character/fighter/fighter_armed_attack/NEE/fighter_armed_attack_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/NNE/fighter_armed_attack_NNE.plist", "playable character/fighter/fighter_armed_attack/NNE/fighter_armed_attack_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/NNW/fighter_armed_attack_NNW.plist", "playable character/fighter/fighter_armed_attack/NNW/fighter_armed_attack_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/NW/fighter_armed_attack_NW.plist", "playable character/fighter/fighter_armed_attack/NW/fighter_armed_attack_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/NWW/fighter_armed_attack_NWW.plist", "playable character/fighter/fighter_armed_attack/NWW/fighter_armed_attack_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/S/fighter_armed_attack_S.plist", "playable character/fighter/fighter_armed_attack/S/fighter_armed_attack_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/SE/fighter_armed_attack_SE.plist", "playable character/fighter/fighter_armed_attack/SE/fighter_armed_attack_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/SEE/fighter_armed_attack_SEE.plist", "playable character/fighter/fighter_armed_attack/SEE/fighter_armed_attack_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/SSE/fighter_armed_attack_SSE.plist", "playable character/fighter/fighter_armed_attack/SSE/fighter_armed_attack_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/SSW/fighter_armed_attack_SSW.plist", "playable character/fighter/fighter_armed_attack/SSW/fighter_armed_attack_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/SW/fighter_armed_attack_SW.plist", "playable character/fighter/fighter_armed_attack/SW/fighter_armed_attack_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/SWW/fighter_armed_attack_SWW.plist", "playable character/fighter/fighter_armed_attack/SWW/fighter_armed_attack_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_attack/W/fighter_armed_attack_W.plist", "playable character/fighter/fighter_armed_attack/W/fighter_armed_attack_W.png");

    // Arm Walk
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/E/fighter_armed_walk_E.plist", "playable character/fighter/fighter_armed_walk/E/fighter_armed_walk_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/N/fighter_armed_walk_N.plist", "playable character/fighter/fighter_armed_walk/N/fighter_armed_walk_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/NE/fighter_armed_walk_NE.plist", "playable character/fighter/fighter_armed_walk/NE/fighter_armed_walk_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/NEE/fighter_armed_walk_NEE.plist", "playable character/fighter/fighter_armed_walk/NEE/fighter_armed_walk_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/NNE/fighter_armed_walk_NNE.plist", "playable character/fighter/fighter_armed_walk/NNE/fighter_armed_walk_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/NNW/fighter_armed_walk_NNW.plist", "playable character/fighter/fighter_armed_walk/NNW/fighter_armed_walk_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/NW/fighter_armed_walk_NW.plist", "playable character/fighter/fighter_armed_walk/NW/fighter_armed_walk_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/NWW/fighter_armed_walk_NWW.plist", "playable character/fighter/fighter_armed_walk/NWW/fighter_armed_walk_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/S/fighter_armed_walk_S.plist", "playable character/fighter/fighter_armed_walk/S/fighter_armed_walk_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/SE/fighter_armed_walk_SE.plist", "playable character/fighter/fighter_armed_walk/SE/fighter_armed_walk_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/SEE/fighter_armed_walk_SEE.plist", "playable character/fighter/fighter_armed_walk/SEE/fighter_armed_walk_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/SSE/fighter_armed_walk_SSE.plist", "playable character/fighter/fighter_armed_walk/SSE/fighter_armed_walk_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/SSW/fighter_armed_walk_SSW.plist", "playable character/fighter/fighter_armed_walk/SSW/fighter_armed_walk_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/SW/fighter_armed_walk_SW.plist", "playable character/fighter/fighter_armed_walk/SW/fighter_armed_walk_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/SWW/fighter_armed_walk_SWW.plist", "playable character/fighter/fighter_armed_walk/SWW/fighter_armed_walk_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_armed_walk/W/fighter_armed_walk_W.plist", "playable character/fighter/fighter_armed_walk/W/fighter_armed_walk_W.png");
    // Default Walk
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/E/fighter_default_walk_E.plist", "playable character/fighter/fighter_default_walk/E/fighter_default_walk_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/N/fighter_default_walk_N.plist", "playable character/fighter/fighter_default_walk/N/fighter_default_walk_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/NE/fighter_default_walk_NE.plist", "playable character/fighter/fighter_default_walk/NE/fighter_default_walk_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/NEE/fighter_default_walk_NEE.plist", "playable character/fighter/fighter_default_walk/NEE/fighter_default_walk_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/NNE/fighter_default_walk_NNE.plist", "playable character/fighter/fighter_default_walk/NNE/fighter_default_walk_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/NNW/fighter_default_walk_NNW.plist", "playable character/fighter/fighter_default_walk/NNW/fighter_default_walk_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/NW/fighter_default_walk_NW.plist", "playable character/fighter/fighter_default_walk/NW/fighter_default_walk_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/NWW/fighter_default_walk_NWW.plist", "playable character/fighter/fighter_default_walk/NWW/fighter_default_walk_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/S/fighter_default_walk_S.plist", "playable character/fighter/fighter_default_walk/S/fighter_default_walk_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/SE/fighter_default_walk_SE.plist", "playable character/fighter/fighter_default_walk/SE/fighter_default_walk_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/SEE/fighter_default_walk_SEE.plist", "playable character/fighter/fighter_default_walk/SEE/fighter_default_walk_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/SSE/fighter_default_walk_SSE.plist", "playable character/fighter/fighter_default_walk/SSE/fighter_default_walk_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/SSW/fighter_default_walk_SSW.plist", "playable character/fighter/fighter_default_walk/SSW/fighter_default_walk_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/SW/fighter_default_walk_SW.plist", "playable character/fighter/fighter_default_walk/SW/fighter_default_walk_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/SWW/fighter_default_walk_SWW.plist", "playable character/fighter/fighter_default_walk/SWW/fighter_default_walk_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_default_walk/W/fighter_default_walk_W.plist", "playable character/fighter/fighter_default_walk/W/fighter_default_walk_W.png");

    // Special Death
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/E/fighter_special_death_E.plist", "playable character/fighter/fighter_special_death/E/fighter_special_death_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/N/fighter_special_death_N.plist", "playable character/fighter/fighter_special_death/N/fighter_special_death_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/NE/fighter_special_death_NE.plist", "playable character/fighter/fighter_special_death/NE/fighter_special_death_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/NEE/fighter_special_death_NEE.plist", "playable character/fighter/fighter_special_death/NEE/fighter_special_death_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/NNE/fighter_special_death_NNE.plist", "playable character/fighter/fighter_special_death/NNE/fighter_special_death_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/NNW/fighter_special_death_NNW.plist", "playable character/fighter/fighter_special_death/NNW/fighter_special_death_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/NW/fighter_special_death_NW.plist", "playable character/fighter/fighter_special_death/NW/fighter_special_death_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/NWW/fighter_special_death_NWW.plist", "playable character/fighter/fighter_special_death/NWW/fighter_special_death_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/S/fighter_special_death_S.plist", "playable character/fighter/fighter_special_death/S/fighter_special_death_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/SE/fighter_special_death_SE.plist", "playable character/fighter/fighter_special_death/SE/fighter_special_death_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/SEE/fighter_special_death_SEE.plist", "playable character/fighter/fighter_special_death/SEE/fighter_special_death_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/SSE/fighter_special_death_SSE.plist", "playable character/fighter/fighter_special_death/SSE/fighter_special_death_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/SSW/fighter_special_death_SSW.plist", "playable character/fighter/fighter_special_death/SSW/fighter_special_death_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/SW/fighter_special_death_SW.plist", "playable character/fighter/fighter_special_death/SW/fighter_special_death_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/SWW/fighter_special_death_SWW.plist", "playable character/fighter/fighter_special_death/SWW/fighter_special_death_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_death/W/fighter_special_death_W.plist", "playable character/fighter/fighter_special_death/W/fighter_special_death_W.png");

    // Special Select
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/E/fighter_special_select_E.plist", "playable character/fighter/fighter_special_select/E/fighter_special_select_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/N/fighter_special_select_N.plist", "playable character/fighter/fighter_special_select/N/fighter_special_select_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/NE/fighter_special_select_NE.plist", "playable character/fighter/fighter_special_select/NE/fighter_special_select_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/NEE/fighter_special_select_NEE.plist", "playable character/fighter/fighter_special_select/NEE/fighter_special_select_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/NNE/fighter_special_select_NNE.plist", "playable character/fighter/fighter_special_select/NNE/fighter_special_select_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/NNW/fighter_special_select_NNW.plist", "playable character/fighter/fighter_special_select/NNW/fighter_special_select_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/NW/fighter_special_select_NW.plist", "playable character/fighter/fighter_special_select/NW/fighter_special_select_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/NWW/fighter_special_select_NWW.plist", "playable character/fighter/fighter_special_select/NWW/fighter_special_select_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/S/fighter_special_select_S.plist", "playable character/fighter/fighter_special_select/S/fighter_special_select_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/SE/fighter_special_select_SE.plist", "playable character/fighter/fighter_special_select/SE/fighter_special_select_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/SEE/fighter_special_select_SEE.plist", "playable character/fighter/fighter_special_select/SEE/fighter_special_select_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/SSE/fighter_special_select_SSE.plist", "playable character/fighter/fighter_special_select/SSE/fighter_special_select_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/SSW/fighter_special_select_SSW.plist", "playable character/fighter/fighter_special_select/SSW/fighter_special_select_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/SW/fighter_special_select_SW.plist", "playable character/fighter/fighter_special_select/SW/fighter_special_select_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/SWW/fighter_special_select_SWW.plist", "playable character/fighter/fighter_special_select/SWW/fighter_special_select_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/fighter/fighter_special_select/W/fighter_special_select_W.plist", "playable character/fighter/fighter_special_select/W/fighter_special_select_W.png");
}
// Knight
void HelloWorld::loadKnightToCache()
{
    // Armed Idle
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/E/knight_armed_idle_E.plist", "playable character/knight/knight_armed_idle/E/knight_armed_idle_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/N/knight_armed_idle_N.plist", "playable character/knight/knight_armed_idle/N/knight_armed_idle_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/NE/knight_armed_idle_NE.plist", "playable character/knight/knight_armed_idle/NE/knight_armed_idle_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/NEE/knight_armed_idle_NEE.plist", "playable character/knight/knight_armed_idle/NEE/knight_armed_idle_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/NNE/knight_armed_idle_NNE.plist", "playable character/knight/knight_armed_idle/NNE/knight_armed_idle_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/NNW/knight_armed_idle_NNW.plist", "playable character/knight/knight_armed_idle/NNW/knight_armed_idle_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/NW/knight_armed_idle_NW.plist", "playable character/knight/knight_armed_idle/NW/knight_armed_idle_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/NWW/knight_armed_idle_NWW.plist", "playable character/knight/knight_armed_idle/NWW/knight_armed_idle_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/S/knight_armed_idle_S.plist", "playable character/knight/knight_armed_idle/S/knight_armed_idle_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/SE/knight_armed_idle_SE.plist", "playable character/knight/knight_armed_idle/SE/knight_armed_idle_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/SEE/knight_armed_idle_SEE.plist", "playable character/knight/knight_armed_idle/SEE/knight_armed_idle_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/SSE/knight_armed_idle_SSE.plist", "playable character/knight/knight_armed_idle/SSE/knight_armed_idle_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/SSW/knight_armed_idle_SSW.plist", "playable character/knight/knight_armed_idle/SSW/knight_armed_idle_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/SW/knight_armed_idle_SW.plist", "playable character/knight/knight_armed_idle/SW/knight_armed_idle_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/SWW/knight_armed_idle_SWW.plist", "playable character/knight/knight_armed_idle/SWW/knight_armed_idle_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_idle/W/knight_armed_idle_W.plist", "playable character/knight/knight_armed_idle/W/knight_armed_idle_W.png");

    // Armed Attack
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/E/knight_armed_attack_E.plist", "playable character/knight/knight_armed_attack/E/knight_armed_attack_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/N/knight_armed_attack_N.plist", "playable character/knight/knight_armed_attack/N/knight_armed_attack_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/NE/knight_armed_attack_NE.plist", "playable character/knight/knight_armed_attack/NE/knight_armed_attack_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/NEE/knight_armed_attack_NEE.plist", "playable character/knight/knight_armed_attack/NEE/knight_armed_attack_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/NNE/knight_armed_attack_NNE.plist", "playable character/knight/knight_armed_attack/NNE/knight_armed_attack_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/NNW/knight_armed_attack_NNW.plist", "playable character/knight/knight_armed_attack/NNW/knight_armed_attack_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/NW/knight_armed_attack_NW.plist", "playable character/knight/knight_armed_attack/NW/knight_armed_attack_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/NWW/knight_armed_attack_NWW.plist", "playable character/knight/knight_armed_attack/NWW/knight_armed_attack_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/S/knight_armed_attack_S.plist", "playable character/knight/knight_armed_attack/S/knight_armed_attack_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/SE/knight_armed_attack_SE.plist", "playable character/knight/knight_armed_attack/SE/knight_armed_attack_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/SEE/knight_armed_attack_SEE.plist", "playable character/knight/knight_armed_attack/SEE/knight_armed_attack_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/SSE/knight_armed_attack_SSE.plist", "playable character/knight/knight_armed_attack/SSE/knight_armed_attack_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/SSW/knight_armed_attack_SSW.plist", "playable character/knight/knight_armed_attack/SSW/knight_armed_attack_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/SW/knight_armed_attack_SW.plist", "playable character/knight/knight_armed_attack/SW/knight_armed_attack_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/SWW/knight_armed_attack_SWW.plist", "playable character/knight/knight_armed_attack/SWW/knight_armed_attack_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_attack/W/knight_armed_attack_W.plist", "playable character/knight/knight_armed_attack/W/knight_armed_attack_W.png");

    // Arm Walk
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/E/knight_armed_walk_E.plist", "playable character/knight/knight_armed_walk/E/knight_armed_walk_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/N/knight_armed_walk_N.plist", "playable character/knight/knight_armed_walk/N/knight_armed_walk_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/NE/knight_armed_walk_NE.plist", "playable character/knight/knight_armed_walk/NE/knight_armed_walk_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/NEE/knight_armed_walk_NEE.plist", "playable character/knight/knight_armed_walk/NEE/knight_armed_walk_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/NNE/knight_armed_walk_NNE.plist", "playable character/knight/knight_armed_walk/NNE/knight_armed_walk_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/NNW/knight_armed_walk_NNW.plist", "playable character/knight/knight_armed_walk/NNW/knight_armed_walk_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/NW/knight_armed_walk_NW.plist", "playable character/knight/knight_armed_walk/NW/knight_armed_walk_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/NWW/knight_armed_walk_NWW.plist", "playable character/knight/knight_armed_walk/NWW/knight_armed_walk_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/S/knight_armed_walk_S.plist", "playable character/knight/knight_armed_walk/S/knight_armed_walk_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/SE/knight_armed_walk_SE.plist", "playable character/knight/knight_armed_walk/SE/knight_armed_walk_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/SEE/knight_armed_walk_SEE.plist", "playable character/knight/knight_armed_walk/SEE/knight_armed_walk_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/SSE/knight_armed_walk_SSE.plist", "playable character/knight/knight_armed_walk/SSE/knight_armed_walk_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/SSW/knight_armed_walk_SSW.plist", "playable character/knight/knight_armed_walk/SSW/knight_armed_walk_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/SW/knight_armed_walk_SW.plist", "playable character/knight/knight_armed_walk/SW/knight_armed_walk_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/SWW/knight_armed_walk_SWW.plist", "playable character/knight/knight_armed_walk/SWW/knight_armed_walk_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_armed_walk/W/knight_armed_walk_W.plist", "playable character/knight/knight_armed_walk/W/knight_armed_walk_W.png");
    // Default Walk
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/E/knight_default_walk_E.plist", "playable character/knight/knight_default_walk/E/knight_default_walk_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/N/knight_default_walk_N.plist", "playable character/knight/knight_default_walk/N/knight_default_walk_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/NE/knight_default_walk_NE.plist", "playable character/knight/knight_default_walk/NE/knight_default_walk_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/NEE/knight_default_walk_NEE.plist", "playable character/knight/knight_default_walk/NEE/knight_default_walk_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/NNE/knight_default_walk_NNE.plist", "playable character/knight/knight_default_walk/NNE/knight_default_walk_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/NNW/knight_default_walk_NNW.plist", "playable character/knight/knight_default_walk/NNW/knight_default_walk_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/NW/knight_default_walk_NW.plist", "playable character/knight/knight_default_walk/NW/knight_default_walk_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/NWW/knight_default_walk_NWW.plist", "playable character/knight/knight_default_walk/NWW/knight_default_walk_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/S/knight_default_walk_S.plist", "playable character/knight/knight_default_walk/S/knight_default_walk_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/SE/knight_default_walk_SE.plist", "playable character/knight/knight_default_walk/SE/knight_default_walk_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/SEE/knight_default_walk_SEE.plist", "playable character/knight/knight_default_walk/SEE/knight_default_walk_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/SSE/knight_default_walk_SSE.plist", "playable character/knight/knight_default_walk/SSE/knight_default_walk_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/SSW/knight_default_walk_SSW.plist", "playable character/knight/knight_default_walk/SSW/knight_default_walk_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/SW/knight_default_walk_SW.plist", "playable character/knight/knight_default_walk/SW/knight_default_walk_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/SWW/knight_default_walk_SWW.plist", "playable character/knight/knight_default_walk/SWW/knight_default_walk_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_default_walk/W/knight_default_walk_W.plist", "playable character/knight/knight_default_walk/W/knight_default_walk_W.png");

    // Special Death
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/E/knight_special_death_E.plist", "playable character/knight/knight_special_death/E/knight_special_death_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/N/knight_special_death_N.plist", "playable character/knight/knight_special_death/N/knight_special_death_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/NE/knight_special_death_NE.plist", "playable character/knight/knight_special_death/NE/knight_special_death_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/NEE/knight_special_death_NEE.plist", "playable character/knight/knight_special_death/NEE/knight_special_death_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/NNE/knight_special_death_NNE.plist", "playable character/knight/knight_special_death/NNE/knight_special_death_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/NNW/knight_special_death_NNW.plist", "playable character/knight/knight_special_death/NNW/knight_special_death_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/NW/knight_special_death_NW.plist", "playable character/knight/knight_special_death/NW/knight_special_death_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/NWW/knight_special_death_NWW.plist", "playable character/knight/knight_special_death/NWW/knight_special_death_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/S/knight_special_death_S.plist", "playable character/knight/knight_special_death/S/knight_special_death_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/SE/knight_special_death_SE.plist", "playable character/knight/knight_special_death/SE/knight_special_death_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/SEE/knight_special_death_SEE.plist", "playable character/knight/knight_special_death/SEE/knight_special_death_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/SSE/knight_special_death_SSE.plist", "playable character/knight/knight_special_death/SSE/knight_special_death_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/SSW/knight_special_death_SSW.plist", "playable character/knight/knight_special_death/SSW/knight_special_death_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/SW/knight_special_death_SW.plist", "playable character/knight/knight_special_death/SW/knight_special_death_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/SWW/knight_special_death_SWW.plist", "playable character/knight/knight_special_death/SWW/knight_special_death_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_death/W/knight_special_death_W.plist", "playable character/knight/knight_special_death/W/knight_special_death_W.png");

    // Special Select
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/E/knight_special_select_E.plist", "playable character/knight/knight_special_select/E/knight_special_select_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/N/knight_special_select_N.plist", "playable character/knight/knight_special_select/N/knight_special_select_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/NE/knight_special_select_NE.plist", "playable character/knight/knight_special_select/NE/knight_special_select_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/NEE/knight_special_select_NEE.plist", "playable character/knight/knight_special_select/NEE/knight_special_select_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/NNE/knight_special_select_NNE.plist", "playable character/knight/knight_special_select/NNE/knight_special_select_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/NNW/knight_special_select_NNW.plist", "playable character/knight/knight_special_select/NNW/knight_special_select_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/NW/knight_special_select_NW.plist", "playable character/knight/knight_special_select/NW/knight_special_select_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/NWW/knight_special_select_NWW.plist", "playable character/knight/knight_special_select/NWW/knight_special_select_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/S/knight_special_select_S.plist", "playable character/knight/knight_special_select/S/knight_special_select_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/SE/knight_special_select_SE.plist", "playable character/knight/knight_special_select/SE/knight_special_select_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/SEE/knight_special_select_SEE.plist", "playable character/knight/knight_special_select/SEE/knight_special_select_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/SSE/knight_special_select_SSE.plist", "playable character/knight/knight_special_select/SSE/knight_special_select_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/SSW/knight_special_select_SSW.plist", "playable character/knight/knight_special_select/SSW/knight_special_select_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/SW/knight_special_select_SW.plist", "playable character/knight/knight_special_select/SW/knight_special_select_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/SWW/knight_special_select_SWW.plist", "playable character/knight/knight_special_select/SWW/knight_special_select_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("playable character/knight/knight_special_select/W/knight_special_select_W.plist", "playable character/knight/knight_special_select/W/knight_special_select_W.png");
}

// Enemies
// Skeleton
void HelloWorld::loadSkeletonToCache()
{
    // SKELETON
    // Default Walk
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/E/skeleton_default_walk_E.plist", "enemy/skeleton/skeleton_default_walk/E/skeleton_default_walk_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/N/skeleton_default_walk_N.plist", "enemy/skeleton/skeleton_default_walk/N/skeleton_default_walk_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/NE/skeleton_default_walk_NE.plist", "enemy/skeleton/skeleton_default_walk/NE/skeleton_default_walk_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/NEE/skeleton_default_walk_NEE.plist", "enemy/skeleton/skeleton_default_walk/NEE/skeleton_default_walk_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/NNE/skeleton_default_walk_NNE.plist", "enemy/skeleton/skeleton_default_walk/NNE/skeleton_default_walk_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/NNW/skeleton_default_walk_NNW.plist", "enemy/skeleton/skeleton_default_walk/NNW/skeleton_default_walk_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/NW/skeleton_default_walk_NW.plist", "enemy/skeleton/skeleton_default_walk/NW/skeleton_default_walk_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/NWW/skeleton_default_walk_NWW.plist", "enemy/skeleton/skeleton_default_walk/NWW/skeleton_default_walk_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/S/skeleton_default_walk_S.plist", "enemy/skeleton/skeleton_default_walk/S/skeleton_default_walk_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/SE/skeleton_default_walk_SE.plist", "enemy/skeleton/skeleton_default_walk/SE/skeleton_default_walk_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/SEE/skeleton_default_walk_SEE.plist", "enemy/skeleton/skeleton_default_walk/SEE/skeleton_default_walk_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/SSE/skeleton_default_walk_SSE.plist", "enemy/skeleton/skeleton_default_walk/SSE/skeleton_default_walk_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/SSW/skeleton_default_walk_SSW.plist", "enemy/skeleton/skeleton_default_walk/SSW/skeleton_default_walk_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/SW/skeleton_default_walk_SW.plist", "enemy/skeleton/skeleton_default_walk/SW/skeleton_default_walk_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/SWW/skeleton_default_walk_SWW.plist", "enemy/skeleton/skeleton_default_walk/SWW/skeleton_default_walk_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_walk/W/skeleton_default_walk_W.plist", "enemy/skeleton/skeleton_default_walk/W/skeleton_default_walk_W.png");

    // Default idle
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/E/skeleton_default_idle_E.plist", "enemy/skeleton/skeleton_default_idle/E/skeleton_default_idle_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/N/skeleton_default_idle_N.plist", "enemy/skeleton/skeleton_default_idle/N/skeleton_default_idle_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/NE/skeleton_default_idle_NE.plist", "enemy/skeleton/skeleton_default_idle/NE/skeleton_default_idle_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/NEE/skeleton_default_idle_NEE.plist", "enemy/skeleton/skeleton_default_idle/NEE/skeleton_default_idle_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/NNE/skeleton_default_idle_NNE.plist", "enemy/skeleton/skeleton_default_idle/NNE/skeleton_default_idle_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/NNW/skeleton_default_idle_NNW.plist", "enemy/skeleton/skeleton_default_idle/NNW/skeleton_default_idle_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/NW/skeleton_default_idle_NW.plist", "enemy/skeleton/skeleton_default_idle/NW/skeleton_default_idle_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/NWW/skeleton_default_idle_NWW.plist", "enemy/skeleton/skeleton_default_idle/NWW/skeleton_default_idle_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/S/skeleton_default_idle_S.plist", "enemy/skeleton/skeleton_default_idle/S/skeleton_default_idle_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/SE/skeleton_default_idle_SE.plist", "enemy/skeleton/skeleton_default_idle/SE/skeleton_default_idle_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/SEE/skeleton_default_idle_SEE.plist", "enemy/skeleton/skeleton_default_idle/SEE/skeleton_default_idle_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/SSE/skeleton_default_idle_SSE.plist", "enemy/skeleton/skeleton_default_idle/SSE/skeleton_default_idle_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/SSW/skeleton_default_idle_SSW.plist", "enemy/skeleton/skeleton_default_idle/SSW/skeleton_default_idle_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/SW/skeleton_default_idle_SW.plist", "enemy/skeleton/skeleton_default_idle/SW/skeleton_default_idle_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/SWW/skeleton_default_idle_SWW.plist", "enemy/skeleton/skeleton_default_idle/SWW/skeleton_default_idle_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_idle/W/skeleton_default_idle_W.plist", "enemy/skeleton/skeleton_default_idle/W/skeleton_default_idle_W.png");
    // Default attack
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/E/skeleton_default_attack_E.plist", "enemy/skeleton/skeleton_default_attack/E/skeleton_default_attack_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/N/skeleton_default_attack_N.plist", "enemy/skeleton/skeleton_default_attack/N/skeleton_default_attack_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/NE/skeleton_default_attack_NE.plist", "enemy/skeleton/skeleton_default_attack/NE/skeleton_default_attack_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/NEE/skeleton_default_attack_NEE.plist", "enemy/skeleton/skeleton_default_attack/NEE/skeleton_default_attack_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/NNE/skeleton_default_attack_NNE.plist", "enemy/skeleton/skeleton_default_attack/NNE/skeleton_default_attack_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/NNW/skeleton_default_attack_NNW.plist", "enemy/skeleton/skeleton_default_attack/NNW/skeleton_default_attack_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/NW/skeleton_default_attack_NW.plist", "enemy/skeleton/skeleton_default_attack/NW/skeleton_default_attack_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/NWW/skeleton_default_attack_NWW.plist", "enemy/skeleton/skeleton_default_attack/NWW/skeleton_default_attack_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/S/skeleton_default_attack_S.plist", "enemy/skeleton/skeleton_default_attack/S/skeleton_default_attack_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/SE/skeleton_default_attack_SE.plist", "enemy/skeleton/skeleton_default_attack/SE/skeleton_default_attack_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/SEE/skeleton_default_attack_SEE.plist", "enemy/skeleton/skeleton_default_attack/SEE/skeleton_default_attack_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/SSE/skeleton_default_attack_SSE.plist", "enemy/skeleton/skeleton_default_attack/SSE/skeleton_default_attack_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/SSW/skeleton_default_attack_SSW.plist", "enemy/skeleton/skeleton_default_attack/SSW/skeleton_default_attack_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/SW/skeleton_default_attack_SW.plist", "enemy/skeleton/skeleton_default_attack/SW/skeleton_default_attack_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/SWW/skeleton_default_attack_SWW.plist", "enemy/skeleton/skeleton_default_attack/SWW/skeleton_default_attack_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_default_attack/W/skeleton_default_attack_W.plist", "enemy/skeleton/skeleton_default_attack/W/skeleton_default_attack_W.png");

    // Default Walk
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/E/skeleton_special_death_E.plist", "enemy/skeleton/skeleton_special_death/E/skeleton_special_death_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/N/skeleton_special_death_N.plist", "enemy/skeleton/skeleton_special_death/N/skeleton_special_death_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/NE/skeleton_special_death_NE.plist", "enemy/skeleton/skeleton_special_death/NE/skeleton_special_death_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/NEE/skeleton_special_death_NEE.plist", "enemy/skeleton/skeleton_special_death/NEE/skeleton_special_death_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/NNE/skeleton_special_death_NNE.plist", "enemy/skeleton/skeleton_special_death/NNE/skeleton_special_death_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/NNW/skeleton_special_death_NNW.plist", "enemy/skeleton/skeleton_special_death/NNW/skeleton_special_death_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/NW/skeleton_special_death_NW.plist", "enemy/skeleton/skeleton_special_death/NW/skeleton_special_death_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/NWW/skeleton_special_death_NWW.plist", "enemy/skeleton/skeleton_special_death/NWW/skeleton_special_death_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/S/skeleton_special_death_S.plist", "enemy/skeleton/skeleton_special_death/S/skeleton_special_death_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/SE/skeleton_special_death_SE.plist", "enemy/skeleton/skeleton_special_death/SE/skeleton_special_death_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/SEE/skeleton_special_death_SEE.plist", "enemy/skeleton/skeleton_special_death/SEE/skeleton_special_death_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/SSE/skeleton_special_death_SSE.plist", "enemy/skeleton/skeleton_special_death/SSE/skeleton_special_death_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/SSW/skeleton_special_death_SSW.plist", "enemy/skeleton/skeleton_special_death/SSW/skeleton_special_death_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/SW/skeleton_special_death_SW.plist", "enemy/skeleton/skeleton_special_death/SW/skeleton_special_death_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/SWW/skeleton_special_death_SWW.plist", "enemy/skeleton/skeleton_special_death/SWW/skeleton_special_death_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/skeleton/skeleton_special_death/W/skeleton_special_death_W.plist", "enemy/skeleton/skeleton_special_death/W/skeleton_special_death_W.png");
}
// Slime
void HelloWorld::loadSlimeToCache()
{
    // Default Walk
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/E/slime_default_walk_E.plist", "enemy/slime/slime_default_walk/E/slime_default_walk_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/N/slime_default_walk_N.plist", "enemy/slime/slime_default_walk/N/slime_default_walk_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/NE/slime_default_walk_NE.plist", "enemy/slime/slime_default_walk/NE/slime_default_walk_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/NEE/slime_default_walk_NEE.plist", "enemy/slime/slime_default_walk/NEE/slime_default_walk_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/NNE/slime_default_walk_NNE.plist", "enemy/slime/slime_default_walk/NNE/slime_default_walk_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/NNW/slime_default_walk_NNW.plist", "enemy/slime/slime_default_walk/NNW/slime_default_walk_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/NW/slime_default_walk_NW.plist", "enemy/slime/slime_default_walk/NW/slime_default_walk_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/NWW/slime_default_walk_NWW.plist", "enemy/slime/slime_default_walk/NWW/slime_default_walk_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/S/slime_default_walk_S.plist", "enemy/slime/slime_default_walk/S/slime_default_walk_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/SE/slime_default_walk_SE.plist", "enemy/slime/slime_default_walk/SE/slime_default_walk_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/SEE/slime_default_walk_SEE.plist", "enemy/slime/slime_default_walk/SEE/slime_default_walk_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/SSE/slime_default_walk_SSE.plist", "enemy/slime/slime_default_walk/SSE/slime_default_walk_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/SSW/slime_default_walk_SSW.plist", "enemy/slime/slime_default_walk/SSW/slime_default_walk_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/SW/slime_default_walk_SW.plist", "enemy/slime/slime_default_walk/SW/slime_default_walk_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/SWW/slime_default_walk_SWW.plist", "enemy/slime/slime_default_walk/SWW/slime_default_walk_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_walk/W/slime_default_walk_W.plist", "enemy/slime/slime_default_walk/W/slime_default_walk_W.png");

    // Default idle
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/E/slime_default_idle_E.plist", "enemy/slime/slime_default_idle/E/slime_default_idle_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/N/slime_default_idle_N.plist", "enemy/slime/slime_default_idle/N/slime_default_idle_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/NE/slime_default_idle_NE.plist", "enemy/slime/slime_default_idle/NE/slime_default_idle_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/NEE/slime_default_idle_NEE.plist", "enemy/slime/slime_default_idle/NEE/slime_default_idle_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/NNE/slime_default_idle_NNE.plist", "enemy/slime/slime_default_idle/NNE/slime_default_idle_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/NNW/slime_default_idle_NNW.plist", "enemy/slime/slime_default_idle/NNW/slime_default_idle_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/NW/slime_default_idle_NW.plist", "enemy/slime/slime_default_idle/NW/slime_default_idle_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/NWW/slime_default_idle_NWW.plist", "enemy/slime/slime_default_idle/NWW/slime_default_idle_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/S/slime_default_idle_S.plist", "enemy/slime/slime_default_idle/S/slime_default_idle_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/SE/slime_default_idle_SE.plist", "enemy/slime/slime_default_idle/SE/slime_default_idle_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/SEE/slime_default_idle_SEE.plist", "enemy/slime/slime_default_idle/SEE/slime_default_idle_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/SSE/slime_default_idle_SSE.plist", "enemy/slime/slime_default_idle/SSE/slime_default_idle_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/SSW/slime_default_idle_SSW.plist", "enemy/slime/slime_default_idle/SSW/slime_default_idle_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/SW/slime_default_idle_SW.plist", "enemy/slime/slime_default_idle/SW/slime_default_idle_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/SWW/slime_default_idle_SWW.plist", "enemy/slime/slime_default_idle/SWW/slime_default_idle_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_default_idle/W/slime_default_idle_W.plist", "enemy/slime/slime_default_idle/W/slime_default_idle_W.png");

    // Default Walk
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/E/slime_special_death_E.plist", "enemy/slime/slime_special_death/E/slime_special_death_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/N/slime_special_death_N.plist", "enemy/slime/slime_special_death/N/slime_special_death_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/NE/slime_special_death_NE.plist", "enemy/slime/slime_special_death/NE/slime_special_death_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/NEE/slime_special_death_NEE.plist", "enemy/slime/slime_special_death/NEE/slime_special_death_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/NNE/slime_special_death_NNE.plist", "enemy/slime/slime_special_death/NNE/slime_special_death_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/NNW/slime_special_death_NNW.plist", "enemy/slime/slime_special_death/NNW/slime_special_death_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/NW/slime_special_death_NW.plist", "enemy/slime/slime_special_death/NW/slime_special_death_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/NWW/slime_special_death_NWW.plist", "enemy/slime/slime_special_death/NWW/slime_special_death_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/S/slime_special_death_S.plist", "enemy/slime/slime_special_death/S/slime_special_death_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/SE/slime_special_death_SE.plist", "enemy/slime/slime_special_death/SE/slime_special_death_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/SEE/slime_special_death_SEE.plist", "enemy/slime/slime_special_death/SEE/slime_special_death_SEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/SSE/slime_special_death_SSE.plist", "enemy/slime/slime_special_death/SSE/slime_special_death_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/SSW/slime_special_death_SSW.plist", "enemy/slime/slime_special_death/SSW/slime_special_death_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/SW/slime_special_death_SW.plist", "enemy/slime/slime_special_death/SW/slime_special_death_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/SWW/slime_special_death_SWW.plist", "enemy/slime/slime_special_death/SWW/slime_special_death_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("enemy/slime/slime_special_death/W/slime_special_death_W.plist", "enemy/slime/slime_special_death/W/slime_special_death_W.png");
}


//Boss
void HelloWorld::loadHellBeastToCache() {
    //Attack1
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_E/hellbeast_attack1_E.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_E/hellbeast_attack1_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_NEE/hellbeast_attack1_NEE.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_NEE/hellbeast_attack1_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_NE/hellbeast_attack1_NE.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_NE/hellbeast_attack1_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_NNE/hellbeast_attack1_NNE.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_NNE/hellbeast_attack1_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_N/hellbeast_attack1_N.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_N/hellbeast_attack1_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_NNW/hellbeast_attack1_NNW.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_NNW/hellbeast_attack1_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_NW/hellbeast_attack1_NW.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_NW/hellbeast_attack1_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_NWW/hellbeast_attack1_NWW.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_NWW/hellbeast_attack1_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_W/hellbeast_attack1_W.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_W/hellbeast_attack1_W.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_SWW/hellbeast_attack1_SWW.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_SWW/hellbeast_attack1_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_SW/hellbeast_attack1_SW.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_SW/hellbeast_attack1_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_SSW/hellbeast_attack1_SSW.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_SSW/hellbeast_attack1_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_S/hellbeast_attack1_S.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_S/hellbeast_attack1_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_SSE/hellbeast_attack1_SSE.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_SSE/hellbeast_attack1_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_SE/hellbeast_attack1_SE.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_SE/hellbeast_attack1_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack1/hellbeast_attack1_SEE/hellbeast_attack1_SEE.plist", "boss/HellBeast/HellBeastAttack1/hellbeast_attack1_SEE/hellbeast_attack1_SEE.png");
    //Attack2
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_E/hellbeast_attack2_E.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_E/hellbeast_attack2_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_NEE/hellbeast_attack2_NEE.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_NEE/hellbeast_attack2_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_NE/hellbeast_attack2_NE.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_NE/hellbeast_attack2_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_NNE/hellbeast_attack2_NNE.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_NNE/hellbeast_attack2_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_N/hellbeast_attack2_N.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_N/hellbeast_attack2_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_NNW/hellbeast_attack2_NNW.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_NNW/hellbeast_attack2_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_NW/hellbeast_attack2_NW.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_NW/hellbeast_attack2_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_NWW/hellbeast_attack2_NWW.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_NWW/hellbeast_attack2_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_W/hellbeast_attack2_W.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_W/hellbeast_attack2_W.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_SWW/hellbeast_attack2_SWW.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_SWW/hellbeast_attack2_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_SW/hellbeast_attack2_SW.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_SW/hellbeast_attack2_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_SSW/hellbeast_attack2_SSW.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_SSW/hellbeast_attack2_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_S/hellbeast_attack2_S.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_S/hellbeast_attack2_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_SSE/hellbeast_attack2_SSE.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_SSE/hellbeast_attack2_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_SE/hellbeast_attack2_SE.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_SE/hellbeast_attack2_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack2/hellbeast_attack2_SEE/hellbeast_attack2_SEE.plist", "boss/HellBeast/HellBeastAttack2/hellbeast_attack2_SEE/hellbeast_attack2_SEE.png");
    //Attack3
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_E/hellbeast_hit_E.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_E/hellbeast_hit_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_NEE/hellbeast_hit_NEE.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_NEE/hellbeast_hit_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_NE/hellbeast_hit_NE.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_NE/hellbeast_hit_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_NNE/hellbeast_hit_NNE.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_NNE/hellbeast_hit_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_N/hellbeast_hit_N.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_N/hellbeast_hit_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_NNW/hellbeast_hit_NNW.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_NNW/hellbeast_hit_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_NW/hellbeast_hit_NW.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_NW/hellbeast_hit_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_NWW/hellbeast_hit_NWW.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_NWW/hellbeast_hit_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_W/hellbeast_hit_W.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_W/hellbeast_hit_W.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_SWW/hellbeast_hit_SWW.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_SWW/hellbeast_hit_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_SW/hellbeast_hit_SW.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_SW/hellbeast_hit_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_SSW/hellbeast_hit_SSW.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_SSW/hellbeast_hit_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_S/hellbeast_hit_S.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_S/hellbeast_hit_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_SSE/hellbeast_hit_SSE.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_SSE/hellbeast_hit_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_SE/hellbeast_hit_SE.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_SE/hellbeast_hit_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastHit/hellbeast_hit_SEE/hellbeast_hit_SEE.plist", "boss/HellBeast/HellBeastHit/hellbeast_hit_SEE/hellbeast_hit_SEE.png");
    //Death
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_E/hellbeast_death_E.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_E/hellbeast_death_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_NEE/hellbeast_death_NEE.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_NEE/hellbeast_death_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_NE/hellbeast_death_NE.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_NE/hellbeast_death_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_NNE/hellbeast_death_NNE.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_NNE/hellbeast_death_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_N/hellbeast_death_N.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_N/hellbeast_death_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_NNW/hellbeast_death_NNW.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_NNW/hellbeast_death_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_NW/hellbeast_death_NW.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_NW/hellbeast_death_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_NWW/hellbeast_death_NWW.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_NWW/hellbeast_death_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_W/hellbeast_death_W.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_W/hellbeast_death_W.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_SWW/hellbeast_death_SWW.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_SWW/hellbeast_death_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_SW/hellbeast_death_SW.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_SW/hellbeast_death_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_SSW/hellbeast_death_SSW.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_SSW/hellbeast_death_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_S/hellbeast_death_S.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_S/hellbeast_death_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_SSE/hellbeast_death_SSE.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_SSE/hellbeast_death_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_SE/hellbeast_death_SE.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_SE/hellbeast_death_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastDeath/hellbeast_death_SEE/hellbeast_death_SEE.plist", "boss/HellBeast/HellBeastDeath/hellbeast_death_SEE/hellbeast_death_SEE.png");
    //Hit
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_E/hellbeast_attack3_E.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_E/hellbeast_attack3_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_NEE/hellbeast_attack3_NEE.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_NEE/hellbeast_attack3_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_NE/hellbeast_attack3_NE.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_NE/hellbeast_attack3_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_NNE/hellbeast_attack3_NNE.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_NNE/hellbeast_attack3_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_N/hellbeast_attack3_N.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_N/hellbeast_attack3_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_NNW/hellbeast_attack3_NNW.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_NNW/hellbeast_attack3_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_NW/hellbeast_attack3_NW.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_NW/hellbeast_attack3_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_NWW/hellbeast_attack3_NWW.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_NWW/hellbeast_attack3_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_W/hellbeast_attack3_W.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_W/hellbeast_attack3_W.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_SWW/hellbeast_attack3_SWW.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_SWW/hellbeast_attack3_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_SW/hellbeast_attack3_SW.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_SW/hellbeast_attack3_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_SSW/hellbeast_attack3_SSW.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_SSW/hellbeast_attack3_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_S/hellbeast_attack3_S.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_S/hellbeast_attack3_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_SSE/hellbeast_attack3_SSE.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_SSE/hellbeast_attack3_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_SE/hellbeast_attack3_SE.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_SE/hellbeast_attack3_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastAttack3/hellbeast_attack3_SEE/hellbeast_attack3_SEE.plist", "boss/HellBeast/HellBeastAttack3/hellbeast_attack3_SEE/hellbeast_attack3_SEE.png");
    //Idle
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_E/hellbeast_idle_E.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_E/hellbeast_idle_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_NEE/hellbeast_idle_NEE.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_NEE/hellbeast_idle_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_NE/hellbeast_idle_NE.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_NE/hellbeast_idle_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_NNE/hellbeast_idle_NNE.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_NNE/hellbeast_idle_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_N/hellbeast_idle_N.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_N/hellbeast_idle_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_NNW/hellbeast_idle_NNW.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_NNW/hellbeast_idle_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_NW/hellbeast_idle_NW.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_NW/hellbeast_idle_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_NWW/hellbeast_idle_NWW.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_NWW/hellbeast_idle_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_W/hellbeast_idle_W.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_W/hellbeast_idle_W.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_SWW/hellbeast_idle_SWW.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_SWW/hellbeast_idle_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_SW/hellbeast_idle_SW.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_SW/hellbeast_idle_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_SSW/hellbeast_idle_SSW.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_SSW/hellbeast_idle_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_S/hellbeast_idle_S.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_S/hellbeast_idle_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_SSE/hellbeast_idle_SSE.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_SSE/hellbeast_idle_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_SE/hellbeast_idle_SE.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_SE/hellbeast_idle_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastIdle/hellbeast_idle_SEE/hellbeast_idle_SEE.plist", "boss/HellBeast/HellBeastIdle/hellbeast_idle_SEE/hellbeast_idle_SEE.png");
    //Roar
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_E/hellbeast_roar_E.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_E/hellbeast_roar_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_NEE/hellbeast_roar_NEE.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_NEE/hellbeast_roar_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_NE/hellbeast_roar_NE.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_NE/hellbeast_roar_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_NNE/hellbeast_roar_NNE.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_NNE/hellbeast_roar_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_N/hellbeast_roar_N.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_N/hellbeast_roar_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_NNW/hellbeast_roar_NNW.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_NNW/hellbeast_roar_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_NW/hellbeast_roar_NW.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_NW/hellbeast_roar_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_NWW/hellbeast_roar_NWW.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_NWW/hellbeast_roar_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_W/hellbeast_roar_W.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_W/hellbeast_roar_W.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_SWW/hellbeast_roar_SWW.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_SWW/hellbeast_roar_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_SW/hellbeast_roar_SW.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_SW/hellbeast_roar_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_SSW/hellbeast_roar_SSW.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_SSW/hellbeast_roar_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_S/hellbeast_roar_S.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_S/hellbeast_roar_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_SSE/hellbeast_roar_SSE.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_SSE/hellbeast_roar_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_SE/hellbeast_roar_SE.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_SE/hellbeast_roar_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRoar/hellbeast_roar_SEE/hellbeast_roar_SEE.plist", "boss/HellBeast/HellBeastRoar/hellbeast_roar_SEE/hellbeast_roar_SEE.png");
    //Run
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_E/hellbeast_run_E.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_E/hellbeast_run_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_NEE/hellbeast_run_NEE.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_NEE/hellbeast_run_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_NE/hellbeast_run_NE.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_NE/hellbeast_run_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_NNE/hellbeast_run_NNE.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_NNE/hellbeast_run_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_N/hellbeast_run_N.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_N/hellbeast_run_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_NNW/hellbeast_run_NNW.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_NNW/hellbeast_run_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_NW/hellbeast_run_NW.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_NW/hellbeast_run_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_NWW/hellbeast_run_NWW.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_NWW/hellbeast_run_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_W/hellbeast_run_W.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_W/hellbeast_run_W.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_SWW/hellbeast_run_SWW.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_SWW/hellbeast_run_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_SW/hellbeast_run_SW.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_SW/hellbeast_run_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_SSW/hellbeast_run_SSW.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_SSW/hellbeast_run_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_S/hellbeast_run_S.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_S/hellbeast_run_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_SSE/hellbeast_run_SSE.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_SSE/hellbeast_run_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_SE/hellbeast_run_SE.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_SE/hellbeast_run_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastRun/hellbeast_run_SEE/hellbeast_run_SEE.plist", "boss/HellBeast/HellBeastRun/hellbeast_run_SEE/hellbeast_run_SEE.png");
    //Walk
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_E/hellbeast_walk_E.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_E/hellbeast_walk_E.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_NEE/hellbeast_walk_NEE.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_NEE/hellbeast_walk_NEE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_NE/hellbeast_walk_NE.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_NE/hellbeast_walk_NE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_NNE/hellbeast_walk_NNE.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_NNE/hellbeast_walk_NNE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_N/hellbeast_walk_N.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_N/hellbeast_walk_N.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_NNW/hellbeast_walk_NNW.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_NNW/hellbeast_walk_NNW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_NW/hellbeast_walk_NW.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_NW/hellbeast_walk_NW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_NWW/hellbeast_walk_NWW.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_NWW/hellbeast_walk_NWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_W/hellbeast_walk_W.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_W/hellbeast_walk_W.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_SWW/hellbeast_walk_SWW.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_SWW/hellbeast_walk_SWW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_SW/hellbeast_walk_SW.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_SW/hellbeast_walk_SW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_SSW/hellbeast_walk_SSW.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_SSW/hellbeast_walk_SSW.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_S/hellbeast_walk_S.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_S/hellbeast_walk_S.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_SSE/hellbeast_walk_SSE.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_SSE/hellbeast_walk_SSE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_SE/hellbeast_walk_SE.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_SE/hellbeast_walk_SE.png");
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("boss/HellBeast/HellBeastWalk/hellbeast_walk_SEE/hellbeast_walk_SEE.plist", "boss/HellBeast/HellBeastWalk/hellbeast_walk_SEE/hellbeast_walk_SEE.png");
}
