﻿#include "Skeleton.h"
#include "Engine/Engine.h"

bool Skeleton::init() {
    this->loadAnimate();

     direction = 1;
     characterCurrentSprite = Sprite::createWithSpriteFrameName("skeleton_default_idle_E_0.0_0.png");

     //Init physics
     auto physicsBody = PhysicsBody::createBox(Size(20, 20), PhysicsMaterial(1.0f, 0.0f, 0.0f));
     physicsBody->setGravityEnable(false);
     this->setPhysicsBody(physicsBody);
     this->addChild(characterCurrentSprite);

     this->idleState = new EnemiesIdle(this);
     this->attackState = new EnemiesAttack(this);
     this->walkState = new EnemiesWalk(this);
     this->deadState = new EnemiesDead(this);



	return true;
}

void Skeleton::loadAnimate() {
    //Default Walk
    defaultWalk_E = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_E_0.0_", 8, 0.1)); //1
    defaultWalk_NEE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_NEE_22.5_", 8, 0.1)); //2
    defaultWalk_NE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_NE_45.0_", 8, 0.1)); //3
    defaultWalk_NNE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_NNE_67.5_", 8, 0.1)); //4
    defaultWalk_N = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_N_90.0_", 8, 0.1)); //5
    defaultWalk_NNW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_NNW_112.5_", 8, 0.1)); //6
    defaultWalk_NW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_NW_135.0_", 8, 0.1)); //7
    defaultWalk_NWW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_NWW_157.5_", 8, 0.1)); //8
    defaultWalk_W = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_W_180.0_", 8, 0.1)); //9
    defaultWalk_SWW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_SWW_202.5_", 8, 0.1)); //10
    defaultWalk_SW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_SW_225.0_", 8, 0.1)); //11
    defaultWalk_SSW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_SSW_247.5_", 8, 0.1)); //12
    defaultWalk_S = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_S_270.0_", 8, 0.1)); //13
    defaultWalk_SSE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_SSE_292.5_", 8, 0.1)); //14
    defaultWalk_SE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_SE_315.0_", 8, 0.1)); //15
    defaultWalk_SEE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_walk_SEE_337.5_", 8, 0.1)); //16

    //Default Attack
    defaultAttack_E = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_E_0.0_", 8, 0.1)); //1
    defaultAttack_NEE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_NEE_22.5_", 8, 0.1)); //2
    defaultAttack_NE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_NE_45.0_", 8, 0.1)); //3
    defaultAttack_NNE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_NNE_67.5_", 8, 0.1)); //4
    defaultAttack_N = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_N_90.0_", 8, 0.1)); //5
    defaultAttack_NNW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_NNW_112.5_", 8, 0.1)); //6
    defaultAttack_NW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_NW_135.0_", 8, 0.1)); //7
    defaultAttack_NWW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_NWW_157.5_", 8, 0.1)); //8
    defaultAttack_W = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_W_180.0_", 8, 0.1)); //9
    defaultAttack_SWW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_SWW_202.5_", 8, 0.1)); //10
    defaultAttack_SW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_SW_225.0_", 8, 0.1)); //11
    defaultAttack_SSW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_SSW_247.5_", 8, 0.1)); //12
    defaultAttack_S = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_S_270.0_", 8, 0.1)); //13
    defaultAttack_SSE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_SSE_292.5_", 8, 0.1)); //14
    defaultAttack_SE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_SE_315.0_", 8, 0.1)); //15
    defaultAttack_SEE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_attack_SEE_337.5_", 8, 0.1)); //16

    //Default Idle
    defaultIdle_E = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_E_0.0_", 1, 0.1)); //1
    defaultIdle_NEE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_NEE_22.5_", 1, 0.1)); //2
    defaultIdle_NE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_NE_45.0_", 1, 0.1)); //3
    defaultIdle_NNE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_NNE_67.5_", 1, 0.1)); //4
    defaultIdle_N = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_N_90.0_", 1, 0.1)); //5
    defaultIdle_NNW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_NNW_112.5_", 1, 0.1)); //6
    defaultIdle_NW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_NW_135.0_", 1, 0.1)); //7
    defaultIdle_NWW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_NWW_157.5_", 1, 0.1)); //1
    defaultIdle_W = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_W_180.0_", 1, 0.1)); //9
    defaultIdle_SWW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_SWW_202.5_", 1, 0.1)); //10
    defaultIdle_SW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_SW_225.0_", 1, 0.1)); //11
    defaultIdle_SSW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_SSW_247.5_", 1, 0.1)); //12
    defaultIdle_S = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_S_270.0_", 1, 0.1)); //13
    defaultIdle_SSE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_SSE_292.5_", 1, 0.1)); //14
    defaultIdle_SE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_SE_315.0_", 1, 0.1)); //15
    defaultIdle_SEE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_default_idle_SEE_337.5_", 1, 0.1)); //16

    //Default Dead
    specialDeath_E = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_E_0.0_", 8, 0.1)); //1
    specialDeath_NEE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_NEE_22.5_", 8, 0.1)); //2
    specialDeath_NE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_NE_45.0_", 8, 0.1)); //3
    specialDeath_NNE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_NNE_67.5_", 8, 0.1)); //4
    specialDeath_N = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_N_90.0_", 8, 0.1)); //5
    specialDeath_NNW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_NNW_112.5_", 8, 0.1)); //6
    specialDeath_NW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_NW_135.0_", 8, 0.1)); //7
    specialDeath_NWW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_NWW_157.5_", 8, 0.1)); //8
    specialDeath_W = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_W_180.0_", 8, 0.1)); //9
    specialDeath_SWW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_SWW_202.5_", 8, 0.1)); //10
    specialDeath_SW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_SW_225.0_", 8, 0.1)); //11
    specialDeath_SSW = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_SSW_247.5_", 8, 0.1)); //12
    specialDeath_S = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_S_270.0_", 8, 0.1)); //13
    specialDeath_SSE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_SSE_292.5_", 8, 0.1)); //14
    specialDeath_SE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_SE_315.0_", 8, 0.1)); //15
    specialDeath_SEE = Animate::create(Engine::getInstance()->createAnimation1("skeleton_special_death_SEE_337.5_", 8, 0.1)); //16

    //Default Walk
    defaultWalk_E->retain(); //1
    defaultWalk_NEE->retain(); //2
    defaultWalk_NE->retain(); //3
    defaultWalk_NNE->retain(); //4
    defaultWalk_N->retain(); //5
    defaultWalk_NNW->retain(); //6
    defaultWalk_NW->retain(); //7
    defaultWalk_NWW->retain(); //8
    defaultWalk_W->retain(); //9
    defaultWalk_SWW->retain(); //10
    defaultWalk_SW->retain(); //11
    defaultWalk_SSW->retain(); //12
    defaultWalk_S->retain(); //13
    defaultWalk_SSE->retain(); //14
    defaultWalk_SE->retain(); //15
    defaultWalk_SEE->retain(); //16

    //Default Idle
    defaultIdle_E->retain(); //1
    defaultIdle_NEE->retain(); //2
    defaultIdle_NE->retain(); //3
    defaultIdle_NNE->retain(); //4
    defaultIdle_N->retain(); //5
    defaultIdle_NNW->retain(); //6
    defaultIdle_NW->retain(); //7
    defaultIdle_NWW->retain(); //8
    defaultIdle_W->retain(); //9
    defaultIdle_SWW->retain(); //10
    defaultIdle_SW->retain(); //11
    defaultIdle_SSW->retain(); //12
    defaultIdle_S->retain(); //13
    defaultIdle_SSE->retain(); //14
    defaultIdle_SE->retain(); //15
    defaultIdle_SEE->retain(); //16

    //Default Dead
    specialDeath_E->retain(); //1
    specialDeath_NEE->retain(); //2
    specialDeath_NE->retain(); //3
    specialDeath_NNE->retain(); //4
    specialDeath_N->retain(); //5
    specialDeath_NNW->retain(); //6
    specialDeath_NW->retain(); //7
    specialDeath_NWW->retain(); //8
    specialDeath_W->retain(); //9
    specialDeath_SWW->retain(); //10
    specialDeath_SW->retain(); //11
    specialDeath_SSW->retain(); //12
    specialDeath_S->retain(); //13
    specialDeath_SSE->retain(); //14
    specialDeath_SE->retain(); //15
    specialDeath_SEE->retain(); //16

    //Default Attack
    defaultAttack_E->retain(); //1
    defaultAttack_NEE->retain(); //2
    defaultAttack_NE->retain(); //3
    defaultAttack_NNE->retain(); //4
    defaultAttack_N->retain(); //5
    defaultAttack_NNW->retain(); //6
    defaultAttack_NW->retain(); //7
    defaultAttack_NWW->retain(); //8
    defaultAttack_W->retain(); //9
    defaultAttack_SWW->retain(); //10
    defaultAttack_SW->retain(); //11
    defaultAttack_SSW->retain(); //12
    defaultAttack_S->retain(); //13
    defaultAttack_SSE->retain(); //14
    defaultAttack_SE->retain(); //15
    defaultAttack_SEE->retain(); //16
}