#include "Knight.h"
#include "Engine/Engine.h"

bool Knight::init() {
    if (!PlayerCharacter::init()) return false;
    //Load Animate
    this->loadAnimate();

    //Create direction
    direction = 1;

    //Init Knight Sprite
    characterCurrentSprite = Sprite::createWithSpriteFrameName("knight_armed_idle_E_0.0_0.png");

    //MovementSpeed
    MS = 170;

    //Init physics
    auto physicsBody = PhysicsBody::createBox(Size(20, 20), PhysicsMaterial(1.0f, 0.0f, 0.0f));
    physicsBody->setGravityEnable(false);
    this->setPhysicsBody(physicsBody);
    this->addChild(characterCurrentSprite);

    this->idleState = new PlayerCharacterIdle(this);
    this->attackState = new PlayerCharacterAttack(this);
    this->walkState = new PlayerCharacterWalk(this);
    this->deadState = new PlayerCharacterDead(this);
    this->selectState = new PlayerCharacterSelect(this);




    //update
    schedule(CC_SCHEDULE_SELECTOR(PlayerCharacter::update), 0.1f);

    // Tạo một nghe sự kiện chuột
    auto mouseListener = EventListenerMouse::create();

    // Đặt hàm xử lý sự kiện cho sự kiện click chuột
    mouseListener->onMouseDown = CC_CALLBACK_1(Knight::onMouseDown, this);

    // Thêm nghe sự kiện vào danh sách nghe sự kiện
    _eventDispatcher->addEventListenerWithSceneGraphPriority(mouseListener, this);

    auto keyboardListener = cocos2d::EventListenerKeyboard::create();
    keyboardListener->onKeyPressed = CC_CALLBACK_2(PlayerCharacter::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(keyboardListener, this);
    return true;
}



void Knight::loadAnimate() {
    //Arm Attack  
    armAttack_E = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_E_0.0_", 8, 0.1)); //1
    armAttack_NEE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_NEE_22.5_", 8, 0.1)); //2
    armAttack_NE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_NE_45.0_", 8, 0.1)); //3
    armAttack_NNE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_NNE_67.5_", 8, 0.1)); //4
    armAttack_N = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_N_90.0_", 8, 0.1)); //5
    armAttack_NNW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_NNW_112.5_", 8, 0.1)); //6
    armAttack_NW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_NW_135.0_", 8, 0.1)); //7
    armAttack_NWW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_NWW_157.5_", 8, 0.1)); //8
    armAttack_W = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_W_180.0_", 8, 0.1)); //9
    armAttack_SWW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_SWW_202.5_", 8, 0.1)); //10
    armAttack_SW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_SW_225.0_", 8, 0.1)); //11
    armAttack_SSW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_SSW_247.5_", 8, 0.1)); //12
    armAttack_S = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_S_270.0_", 8, 0.1)); //13
    armAttack_SSE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_SSE_292.5_", 8, 0.1)); //14
    armAttack_SE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_SE_315.0_", 8, 0.1)); //15
    armAttack_SEE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_attack_SEE_337.5_", 8, 0.1)); //16



    ////Arm Walk
    armWalk_E = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_E_0.0_", 8, 0.1)); //1
    armWalk_NEE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_NEE_22.5_", 8, 0.1)); //2
    armWalk_NE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_NE_45.0_", 8, 0.1)); //3
    armWalk_NNE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_NNE_67.5_", 8, 0.1)); //4
    armWalk_N = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_N_90.0_", 8, 0.1)); //5
    armWalk_NNW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_NNW_112.5_", 8, 0.1)); //6
    armWalk_NW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_NW_135.0_", 8, 0.1)); //7
    armWalk_NWW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_NWW_157.5_", 8, 0.1)); //8
    armWalk_W = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_W_180.0_", 8, 0.1)); //9
    armWalk_SWW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_SWW_202.5_", 8, 0.1)); //10
    armWalk_SW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_SW_225.0_", 8, 0.1)); //11
    armWalk_SSW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_SSW_247.5_", 8, 0.1)); //12
    armWalk_S = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_S_270.0_", 8, 0.1)); //13
    armWalk_SSE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_SSE_292.5_", 8, 0.1)); //14
    armWalk_SE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_SE_315.0_", 8, 0.1)); //15
    armWalk_SEE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_walk_SEE_337.5_", 8, 0.1)); //16
    //knight_armed_walk_SE_315.0_

   //Default Walk
    defaultWalk_E = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_E_0.0_", 8, 0.1)); //1
    defaultWalk_NEE = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_NEE_22.5_", 8, 0.1)); //2
    defaultWalk_NE = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_NE_45.0_", 8, 0.1)); //3
    defaultWalk_NNE = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_NNE_67.5_", 8, 0.1)); //4
    defaultWalk_N = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_N_90.0_", 8, 0.1)); //5
    defaultWalk_NNW = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_NNW_112.5_", 8, 0.1)); //6
    defaultWalk_NW = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_NW_135.0_", 8, 0.1)); //7
    defaultWalk_NWW = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_NWW_157.5_", 8, 0.1)); //8
    defaultWalk_W = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_W_180.0_", 8, 0.1)); //9
    defaultWalk_SWW = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_SWW_202.5_", 8, 0.1)); //10
    defaultWalk_SW = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_SW_225.0_", 8, 0.1)); //11
    defaultWalk_SSW = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_SSW_247.5_", 8, 0.1)); //12
    defaultWalk_S = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_S_270.0_", 8, 0.1)); //13
    defaultWalk_SSE = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_SSE_292.5_", 8, 0.1)); //14
    defaultWalk_SE = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_SE_315.0_", 8, 0.1)); //15
    defaultWalk_SEE = Animate::create(Engine::getInstance()->createAnimation1("knight_default_walk_SEE_337.5_", 8, 0.1)); //16

    //Special Dead
    specialDeath_E = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_E_0.0_", 8, 0.1)); //1
    specialDeath_NEE = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_NEE_22.5_", 8, 0.1)); //2
    specialDeath_NE = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_NE_45.0_", 8, 0.1)); //3
    specialDeath_NNE = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_NNE_67.5_", 8, 0.1)); //4
    specialDeath_N = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_N_90.0_", 8, 0.1)); //5
    specialDeath_NNW = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_NNW_112.5_", 8, 0.1)); //6
    specialDeath_NW = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_NW_135.0_", 8, 0.1)); //7
    specialDeath_NWW = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_NWW_157.5_", 8, 0.1)); //8
    specialDeath_W = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_W_180.0_", 8, 0.1)); //9
    specialDeath_SWW = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_SWW_202.5_", 8, 0.1)); //10
    specialDeath_SW = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_SW_225.0_", 8, 0.1)); //11
    specialDeath_SSW = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_SSW_247.5_", 8, 0.1)); //12
    specialDeath_S = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_S_270.0_", 8, 0.1)); //13
    specialDeath_SSE = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_SSE_292.5_", 8, 0.1)); //14
    specialDeath_SE = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_SE_315.0_", 8, 0.1)); //15
    specialDeath_SEE = Animate::create(Engine::getInstance()->createAnimation1("knight_special_death_SEE_337.5_", 8, 0.1)); //16

    //Special Select
    specialSelect_E = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_E_0.0_", 8, 0.1)); //1
    specialSelect_NEE = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_NEE_22.5_", 8, 0.1)); //2
    specialSelect_NE = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_NE_45.0_", 8, 0.1)); //3
    specialSelect_NNE = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_NNE_67.5_", 8, 0.1)); //4
    specialSelect_N = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_N_90.0_", 8, 0.1)); //5
    specialSelect_NNW = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_NNW_112.5_", 8, 0.1)); //6
    specialSelect_NW = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_NW_135.0_", 8, 0.1)); //7
    specialSelect_NWW = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_NWW_157.5_", 8, 0.1)); //8
    specialSelect_W = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_W_180.0_", 8, 0.1)); //9
    specialSelect_SWW = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_SWW_202.5_", 8, 0.1)); //10
    specialSelect_SW = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_SW_225.0_", 8, 0.1)); //11
    specialSelect_SSW = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_SSW_247.5_", 8, 0.1)); //12
    specialSelect_S = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_S_270.0_", 8, 0.1)); //13
    specialSelect_SSE = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_SSE_292.5_", 8, 0.1)); //14
    specialSelect_SE = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_SE_315.0_", 8, 0.1)); //15
    specialSelect_SEE = Animate::create(Engine::getInstance()->createAnimation1("knight_special_select_SEE_337.5_", 8, 0.1)); //16

    //Arm Attack
    armAttack_E->retain(); //1
    armAttack_NEE->retain(); //2
    armAttack_NE->retain(); //3
    armAttack_NNE->retain(); //4
    armAttack_N->retain(); //5
    armAttack_NNW->retain(); //6
    armAttack_NW->retain(); //7
    armAttack_NWW->retain(); //8
    armAttack_W->retain(); //9
    armAttack_SWW->retain(); //10
    armAttack_SW->retain(); //11
    armAttack_SSW->retain(); //12
    armAttack_S->retain(); //13
    armAttack_SSE->retain(); //14
    armAttack_SE->retain(); //15
    armAttack_SEE->retain(); //16

    //Arm Walk
    armWalk_E->retain(); //1
    armWalk_NEE->retain(); //2
    armWalk_NE->retain(); //3
    armWalk_NNE->retain(); //4
    armWalk_N->retain(); //5
    armWalk_NNW->retain(); //6
    armWalk_NW->retain(); //7
    armWalk_NWW->retain(); //8
    armWalk_W->retain(); //9
    armWalk_SWW->retain(); //10
    armWalk_SW->retain(); //11
    armWalk_SSW->retain(); //12
    armWalk_S->retain(); //13
    armWalk_SSE->retain(); //14
    armWalk_SE->retain(); //15
    armWalk_SEE->retain(); //16

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

    //Special Dead
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

    //Special Select
    specialSelect_E->retain(); //1
    specialSelect_NEE->retain(); //2
    specialSelect_NE->retain(); //3
    specialSelect_NNE->retain(); //4
    specialSelect_N->retain(); //5
    specialSelect_NNW->retain(); //6
    specialSelect_NW->retain(); //7
    specialSelect_NWW->retain(); //8
    specialSelect_W->retain(); //9
    specialSelect_SWW->retain(); //10
    specialSelect_SW->retain(); //11
    specialSelect_SSW->retain(); //12
    specialSelect_S->retain(); //13
    specialSelect_SSE->retain(); //14
    specialSelect_SE->retain(); //15
    specialSelect_SEE->retain(); //16

    //Armed Idle
    armIdle_E = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_E_0.0_", 1, 0.1)); //1
    armIdle_NEE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_NEE_22.5_", 1, 0.1)); //2
    armIdle_NE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_NE_45.0_", 1, 0.1)); //3
    armIdle_NNE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_NNE_67.5_", 1, 0.1)); //4
    armIdle_N = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_N_90.0_", 1, 0.1)); //5
    armIdle_NNW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_NNW_112.5_", 1, 0.1)); //6
    armIdle_NW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_NW_135.0_", 1, 0.1)); //7
    armIdle_NWW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_NWW_157.5_", 1, 0.1)); //8
    armIdle_W = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_W_180.0_", 1, 0.1)); //9
    armIdle_SWW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_SWW_202.5_", 1, 0.1)); //10
    armIdle_SW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_SW_225.0_", 1, 0.1)); //11
    armIdle_SSW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_SSW_247.5_", 1, 0.1)); //12
    armIdle_S = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_S_270.0_", 1, 0.1)); //13
    armIdle_SSE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_SSE_292.5_", 1, 0.1)); //14
    armIdle_SE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_SE_315.0_", 1, 0.1)); //15
    armIdle_SEE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_SEE_337.5_", 1, 0.1)); //16

    armIdle_E->retain(); //1
    armIdle_NEE->retain(); //2
    armIdle_NE->retain(); //3
    armIdle_NNE->retain(); //4
    armIdle_N->retain(); //5
    armIdle_NNW->retain(); //6
    armIdle_NW->retain(); //7
    armIdle_NWW->retain(); //8
    armIdle_W->retain(); //9
    armIdle_SWW->retain(); //10
    armIdle_SW->retain(); //11
    armIdle_SSW->retain(); //12
    armIdle_S->retain(); //13
    armIdle_SSE->retain(); //14
    armIdle_SE->retain(); //15
    armIdle_SEE->retain(); //16
    ////Default Idle
    // armIdle_E = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_E_0.0_", 8, 0.1)); //1
    // armIdle_NEE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_NEE_22.5_", 8, 0.1)); //2
    // armIdle_NE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_NE_45.0_", 8, 0.1)); //3
    // armIdle_NNE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_NNE_67.5_", 8, 0.1)); //4
    // armIdle_N = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_N_90.0_", 8, 0.1)); //5
    // armIdle_NNW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_NNW_112.5_", 8, 0.1)); //6
    // armIdle_NW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_NW_135.0_", 8, 0.1)); //7
    // armIdle_NWW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_NWW_157.5_", 8, 0.1)); //8
    // armIdle_W = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_W_180.0_", 8, 0.1)); //9
    // armIdle_SWW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_SWW_202.5_", 8, 0.1)); //10
    // armIdle_SW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_SW_225.0_", 8, 0.1)); //11
    // armIdle_SSW = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_SSW_247.5_", 8, 0.1)); //12
    // armIdle_S = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_S_270.0_", 8, 0.1)); //13
    // armIdle_SSE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_SSE_292.5_", 8, 0.1)); //14
    // armIdle_SE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_SE_315.0_", 8, 0.1)); //15
    // armIdle_SEE = Animate::create(Engine::getInstance()->createAnimation1("knight_armed_idle_SEE_337.5_", 8, 0.1)); //16
}