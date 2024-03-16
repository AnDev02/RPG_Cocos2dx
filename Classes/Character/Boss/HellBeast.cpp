#include "HellBeast.h"
#include "Engine/Engine.h"

bool HellBeast::init() {
    //Load All Animate
    this->loadAnimate();
    //Init All States
    this->attackState = new BossAttack(this);
    this->idleState = new BossIdle(this);
    this->roarState = new BossRoar(this);
    this->runState = new BossRun(this);
    this->walkState = new BossWalk(this);
    this->getHitState = new BossGetHit(this);
    this->deadState = new BossDead(this);

    direction = 12;//E

    //Detect PlayerCharacter Range of Boss
    detectionRadius = 250;

    //Attack Range
    attackRange = 50;

    //MovementSpeed
    MS = 100;

    //CurrentCombo
    currentCombo = 1;

    isTargetInAttackRange = false;

    //Init Boss's Sprite
    characterCurrentSprite = Sprite::createWithSpriteFrameName("hellbeast_attack1_E (1).png");

    //Init physics
    auto physicsBody = PhysicsBody::createBox(Size(20, 20), PhysicsMaterial(1.0f, 0.0f, 0.0f));
    physicsBody->setGravityEnable(false);
    this->setPhysicsBody(physicsBody);
    this->addChild(characterCurrentSprite);

    //Upđate Detect Target PlayerCharacter
    schedule(CC_SCHEDULE_SELECTOR(HellBeast::update), 0.1f);
    return true;
}

void HellBeast::loadAnimate() {
    //Attack1
    attack1_E = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_E", 20, 0.05));
    attack1_NEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_NEE", 20, 0.05));
    attack1_NE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_NE", 20, 0.05));
    attack1_NNE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_NNE", 20, 0.05));
    attack1_N = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_N", 20, 0.05));
    attack1_NNW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_NNW", 20, 0.05));
    attack1_NW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_NW", 20, 0.05));
    attack1_NWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_NWW", 20, 0.05));
    attack1_W = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_W", 20, 0.05));
    attack1_SWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_SWW", 20, 0.05));
    attack1_SW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_SW", 20, 0.05));
    attack1_SSW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_SSW", 20, 0.05));
    attack1_S = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_S", 20, 0.05));
    attack1_SSE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_SSE", 20, 0.05));
    attack1_SE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_SE", 20, 0.05));
    attack1_SEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack1_SEE", 20, 0.05));

    //Attack2
    attack2_E = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_E", 24, 0.05));
    attack2_NEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_NEE", 24, 0.05));
    attack2_NE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_NE", 24, 0.05));
    attack2_NNE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_NNE", 24, 0.05));
    attack2_N = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_N", 24, 0.05));
    attack2_NNW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_NNW", 24, 0.05));
    attack2_NW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_NW", 24, 0.05));
    attack2_NWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_NWW", 24, 0.05));
    attack2_W = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_W", 24, 0.05));
    attack2_SWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_SWW", 24, 0.05));
    attack2_SW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_SW", 24, 0.05));
    attack2_SSW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_SSW", 24, 0.05));
    attack2_S = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_S", 24, 0.05));
    attack2_SSE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_SSE", 24, 0.05));
    attack2_SE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_SE", 24, 0.05));
    attack2_SEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack2_SEE", 24, 0.05));

    //Attack3
    attack3_E = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_E", 20, 0.05));
    attack3_NEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_NEE", 20, 0.05));
    attack3_NE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_NE", 20, 0.05));
    attack3_NNE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_NNE", 20, 0.05));
    attack3_N = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_N", 20, 0.05));
    attack3_NNW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_NNW", 20, 0.05));
    attack3_NW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_NW", 20, 0.05));
    attack3_NWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_NWW", 20, 0.05));
    attack3_W = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_W", 20, 0.05));
    attack3_SWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_SWW", 20, 0.05));
    attack3_SW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_SW", 20, 0.05));
    attack3_SSW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_SSW", 20, 0.05));
    attack3_S = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_S", 20, 0.05));
    attack3_SSE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_SSE", 20, 0.05));
    attack3_SE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_SE", 20, 0.05));
    attack3_SEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_attack3_SEE", 20, 0.05));

    //Death
    death_E = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_E", 30, 0.05));
    death_NEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_NEE", 30, 0.05));
    death_NE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_NE", 30, 0.05));
    death_NNE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_NNE", 30, 0.05));
    death_N = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_N", 30, 0.05));
    death_NNW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_NNW", 30, 0.05));
    death_NW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_NW", 30, 0.05));
    death_NWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_NWW", 30, 0.05));
    death_W = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_W", 30, 0.05));
    death_SWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_SWW", 30, 0.05));
    death_SW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_SW", 30, 0.05));
    death_SSW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_SSW", 30, 0.05));
    death_S = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_S", 30, 0.05));
    death_SSE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_SSE", 30, 0.05));
    death_SE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_SE", 30, 0.05));
    death_SEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_death_SEE", 30, 0.05));

    //Get Hit
    getHit_E = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_E", 16, 0.05));
    getHit_NEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_NEE", 16, 0.05));
    getHit_NE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_NE", 16, 0.05));
    getHit_NNE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_NNE", 16, 0.05));
    getHit_N = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_N", 16, 0.05));
    getHit_NNW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_NNW", 16, 0.05));
    getHit_NW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_NW", 16, 0.05));
    getHit_NWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_NWW", 16, 0.05));
    getHit_W = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_W", 16, 0.05));
    getHit_SWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_SWW", 16, 0.05));
    getHit_SW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_SW", 16, 0.05));
    getHit_SSW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_SSW", 16, 0.05));
    getHit_S = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_S", 16, 0.05));
    getHit_SSE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_SSE", 16, 0.05));
    getHit_SE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_SE", 16, 0.05));
    getHit_SEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_hit_SEE", 16, 0.05));

    //Run
    run_E = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_E", 20, 0.05));
    run_NEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_NEE", 20, 0.05));
    run_NE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_NE", 20, 0.05));
    run_NNE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_NNE", 20, 0.05));
    run_N = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_N", 20, 0.05));
    run_NNW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_NNW", 20, 0.05));
    run_NW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_NW", 20, 0.05));
    run_NWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_NWW", 20, 0.05));
    run_W = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_W", 20, 0.05));
    run_SWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_SWW", 20, 0.05));
    run_SW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_SW", 20, 0.05));
    run_SSW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_SSW", 20, 0.05));
    run_S = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_S", 20, 0.05));
    run_SSE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_SSE", 20, 0.05));
    run_SE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_SE", 20, 0.05));
    run_SEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_run_SEE", 20, 0.05));

    //Walk
    walk_E = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_E", 20, 0.05));
    walk_NEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_NEE", 20, 0.05));
    walk_NE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_NE", 20, 0.05));
    walk_NNE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_NNE", 20, 0.05));
    walk_N = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_N", 20, 0.05));
    walk_NNW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_NNW", 20, 0.05));
    walk_NW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_NW", 20, 0.05));
    walk_NWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_NWW", 20, 0.05));
    walk_W = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_W", 20, 0.05));
    walk_SWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_SWW", 20, 0.05));
    walk_SW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_SW", 20, 0.05));
    walk_SSW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_SSW", 20, 0.05));
    walk_S = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_S", 20, 0.05));
    walk_SSE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_SSE", 20, 0.05));
    walk_SE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_SE", 20, 0.05));
    walk_SEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_walk_SEE", 20, 0.05));

    //Roar
    roar_E = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_E", 40, 0.05));
    roar_NEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_NEE", 40, 0.05));
    roar_NE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_NE", 40, 0.05));
    roar_NNE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_NNE", 40, 0.05));
    roar_N = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_N", 40, 0.05));
    roar_NNW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_NNW", 40, 0.05));
    roar_NW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_NW", 40, 0.05));
    roar_NWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_NWW", 40, 0.05));
    roar_W = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_W", 40, 0.05));
    roar_SWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_SWW", 40, 0.05));
    roar_SW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_SW", 40, 0.05));
    roar_SSW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_SSW", 40, 0.05));
    roar_S = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_S", 40, 0.05));
    roar_SSE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_SSE", 40, 0.05));
    roar_SE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_SE", 40, 0.05));
    roar_SEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_roar_SEE", 40, 0.05));

    //Idle
    idle_E = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_E", 24, 0.05));
    idle_NEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_NEE", 24, 0.05));
    idle_NE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_NE", 24, 0.05));
    idle_NNE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_NNE", 24, 0.05));
    idle_N = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_N", 24, 0.05));
    idle_NNW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_NNW", 24, 0.05));
    idle_NW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_NW", 24, 0.05));
    idle_NWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_NWW", 24, 0.05));
    idle_W = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_W", 24, 0.05));
    idle_SWW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_SWW", 24, 0.05));
    idle_SW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_SW", 24, 0.05));
    idle_SSW = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_SSW", 24, 0.05));
    idle_S = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_S", 24, 0.05));
    idle_SSE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_SSE", 24, 0.05));
    idle_SE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_SE", 24, 0.05));
    idle_SEE = Animate::create(Engine::getInstance()->createAnimation2("hellbeast_idle_SEE", 24, 0.05));

    //Attack1
    attack1_E->retain(); //1
    attack1_NEE->retain(); //2
    attack1_NE->retain(); //3
    attack1_NNE->retain(); //4
    attack1_N->retain(); //5
    attack1_NNW->retain(); //6
    attack1_NW->retain(); //7
    attack1_NWW->retain(); //8
    attack1_W->retain(); //9
    attack1_SWW->retain(); //10
    attack1_SW->retain(); //11
    attack1_SSW->retain(); //12
    attack1_S->retain(); //13
    attack1_SSE->retain(); //14
    attack1_SE->retain(); //15
    attack1_SEE->retain(); //16

    //Attack2
    attack2_E->retain(); //2
    attack2_NEE->retain(); //2
    attack2_NE->retain(); //3
    attack2_NNE->retain(); //4
    attack2_N->retain(); //5
    attack2_NNW->retain(); //6
    attack2_NW->retain(); //7
    attack2_NWW->retain(); //8
    attack2_W->retain(); //9
    attack2_SWW->retain(); //20
    attack2_SW->retain(); //22
    attack2_SSW->retain(); //22
    attack2_S->retain(); //23
    attack2_SSE->retain(); //24
    attack2_SE->retain(); //25
    attack2_SEE->retain(); //16

    //Attack3
    attack3_E->retain(); //3
    attack3_NEE->retain(); //2
    attack3_NE->retain(); //3
    attack3_NNE->retain(); //4
    attack3_N->retain(); //5
    attack3_NNW->retain(); //6
    attack3_NW->retain(); //7
    attack3_NWW->retain(); //8
    attack3_W->retain(); //9
    attack3_SWW->retain(); //30
    attack3_SW->retain(); //33
    attack3_SSW->retain(); //32
    attack3_S->retain(); //33
    attack3_SSE->retain(); //34
    attack3_SE->retain(); //35
    attack3_SEE->retain(); //16

    //Death
    death_E->retain(); //1
    death_NEE->retain(); //2
    death_NE->retain(); //3
    death_NNE->retain(); //4
    death_N->retain(); //5
    death_NNW->retain(); //6
    death_NW->retain(); //7
    death_NWW->retain(); //8
    death_W->retain(); //9
    death_SWW->retain(); //10
    death_SW->retain(); //11
    death_SSW->retain(); //12
    death_S->retain(); //13
    death_SSE->retain(); //14
    death_SE->retain(); //15
    death_SEE->retain(); //16

    //Get Hit
    getHit_E->retain(); //1
    getHit_NEE->retain(); //2
    getHit_NE->retain(); //3
    getHit_NNE->retain(); //4
    getHit_N->retain(); //5
    getHit_NNW->retain(); //6
    getHit_NW->retain(); //7
    getHit_NWW->retain(); //8
    getHit_W->retain(); //9
    getHit_SWW->retain(); //10
    getHit_SW->retain(); //11
    getHit_SSW->retain(); //12
    getHit_S->retain(); //13
    getHit_SSE->retain(); //14
    getHit_SE->retain(); //15
    getHit_SEE->retain(); //16

    //Run
    run_E->retain(); //1
    run_NEE->retain(); //2
    run_NE->retain(); //3
    run_NNE->retain(); //4
    run_N->retain(); //5
    run_NNW->retain(); //6
    run_NW->retain(); //7
    run_NWW->retain(); //8
    run_W->retain(); //9
    run_SWW->retain(); //10
    run_SW->retain(); //11
    run_SSW->retain(); //12
    run_S->retain(); //13
    run_SSE->retain(); //14
    run_SE->retain(); //15
    run_SEE->retain(); //16

    //Walk
    walk_E->retain(); //1
    walk_NEE->retain(); //2
    walk_NE->retain(); //3
    walk_NNE->retain(); //4
    walk_N->retain(); //5
    walk_NNW->retain(); //6
    walk_NW->retain(); //7
    walk_NWW->retain(); //8
    walk_W->retain(); //9
    walk_SWW->retain(); //10
    walk_SW->retain(); //11
    walk_SSW->retain(); //12
    walk_S->retain(); //13
    walk_SSE->retain(); //14
    walk_SE->retain(); //15
    walk_SEE->retain(); //16

    //Roar
    roar_E->retain(); //1
    roar_NEE->retain(); //2
    roar_NE->retain(); //3
    roar_NNE->retain(); //4
    roar_N->retain(); //5
    roar_NNW->retain(); //6
    roar_NW->retain(); //7
    roar_NWW->retain(); //8
    roar_W->retain(); //9
    roar_SWW->retain(); //10
    roar_SW->retain(); //11
    roar_SSW->retain(); //12
    roar_S->retain(); //13
    roar_SSE->retain(); //14
    roar_SE->retain(); //15
    roar_SEE->retain(); //16

    //Idle
    idle_E->retain(); //1
    idle_NEE->retain(); //2
    idle_NE->retain(); //3
    idle_NNE->retain(); //4
    idle_N->retain(); //5
    idle_NNW->retain(); //6
    idle_NW->retain(); //7
    idle_NWW->retain(); //8
    idle_W->retain(); //9
    idle_SWW->retain(); //10
    idle_SW->retain(); //11
    idle_SSW->retain(); //12
    idle_S->retain(); //13
    idle_SSE->retain(); //14
    idle_SE->retain(); //15
    idle_SEE->retain(); //16
}