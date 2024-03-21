#/****************************************************************************
# Copyright (c) 2013-2014 cocos2d-x.org
# Copyright (c) 2015-2017 Chukong Technologies Inc.
#
# http://www.cocos2d-x.org
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.
# ****************************************************************************/

cmake_minimum_required(VERSION 3.6)

set(APP_NAME SoulSlayer)

project(${APP_NAME})

if(XCODE)
    if(NOT DEFINED CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET)
        SET (CMAKE_XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET 8.0)
    endif()
endif()

if(NOT DEFINED BUILD_ENGINE_DONE) # to test SoulSlayer into root project
    set(COCOS2DX_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cocos2d)
    set(CMAKE_MODULE_PATH ${COCOS2DX_ROOT_PATH}/cmake/Modules/)

    include(CocosBuildSet)
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos ${ENGINE_BINARY_PATH}/cocos/core)
endif()

# record sources, headers, resources...
set(GAME_SOURCE)
set(GAME_HEADER)

set(GAME_RES_FOLDER
    "${CMAKE_CURRENT_SOURCE_DIR}/Resources"
    )
if(APPLE OR WINDOWS)
    cocos_mark_multi_resources(common_res_files RES_TO "Resources" FOLDERS ${GAME_RES_FOLDER})
endif()

# add cross-platforms source files and header files 
list(APPEND GAME_SOURCE
     Classes/AppDelegate.cpp
     Classes/HelloWorldScene.cpp
     Classes/Audio/AudioEngine.cpp
     Classes/Engine/Engine.cpp
     Classes/Game/Game.cpp
     Classes/Equipment/Type/Weapon/ChippedSword.cpp
     Classes/Equipment/EquipmentFactory.cpp
     Classes/Equipment/BaseEquipment.cpp
     Classes/Inventory/Inventory.cpp
     Classes/Inventory/InventoryNode.cpp
     Classes/BaseCharacter/BaseCharacter.cpp
     Classes/Enemies/ShadowLord/ShadowLord.cpp
     Classes/Enemies/Skeleton/Skeleton.cpp
     Classes/Enemies/Slime/Slime.cpp
     Classes/Enemies/Enemy.cpp
     Classes/Enemies/EnemyFactory.cpp
     Classes/PlayerCharacters/Fighter/Fighter.cpp
     Classes/PlayerCharacters/Knight/Knight.cpp
     Classes/PlayerCharacters/Warrior/Warrior.cpp
     Classes/PlayerCharacters/PlayerCharacter.cpp
     Classes/PlayerCharacters/PlayerCharacterFactory.cpp
     Classes/State/EnemiesState/EnemiesAttack.cpp
     Classes/State/EnemiesState/EnemiesDead.cpp
     Classes/State/EnemiesState/EnemiesIdle.cpp
     Classes/State/EnemiesState/EnemiesWalk.cpp
     Classes/State/PlayerCharacterState/PlayerCharacterAttack.cpp
     Classes/State/PlayerCharacterState/PlayerCharacterDead.cpp
     Classes/State/PlayerCharacterState/PlayerCharacterIdle.cpp
     Classes/State/PlayerCharacterState/PlayerCharacterSelect.cpp
     Classes/State/PlayerCharacterState/PlayerCharacterWalk.cpp
     Classes/State/BossState/BossAttack.cpp
     Classes/State/BossState/BossDead.cpp
     Classes/State/BossState/BossGetHit.cpp
     Classes/State/BossState/BossIdle.cpp
     Classes/State/BossState/BossRoar.cpp
     Classes/State/BossState/BossRun.cpp
     Classes/State/BossState/BossWalk.cpp
     Classes/UserInterface/InGame/Joystick.cpp
     Classes/LightEffect/Effect.cpp
     Classes/LightEffect/EffectSprite.cpp
     Classes/LightEffect/LightEffect.cpp
     Classes/Boss/Boss.cpp
     Classes/Boss/BossFactory.cpp
     Classes/Boss/HellBeast.cpp
     	Classes/MapDecoration/MapDecoration.cpp
Classes/Skills/SkillBase.cpp
Classes/Skills/SkillFactory.cpp
Classes/Skills/AOESkill/AOESkill.cpp
Classes/Skills/AOESkill/AOESkill1.cpp
Classes/Skills/AOESkill/AOESkill2.cpp
Classes/Skills/BuffSkill/BuffSkill.cpp
Classes/Skills/BuffSkill/BuffSkill1.cpp
Classes/Skills/BuffSkill/BuffSkill2.cpp
Classes/Skills/SkillShot/SkillShot.cpp
Classes/Skills/SkillShot/SkillShot1.cpp
Classes/Skills/SkillShot/SkillShot2.cpp
Classes/Skills/TargetSkill/TargetSkill.cpp
Classes/Skills/TargetSkill/TargetSkill1.cpp
Classes/Skills/TargetSkill/TargetSkill2.cpp
     )
list(APPEND GAME_HEADER
     Classes/AppDelegate.h
     Classes/HelloWorldScene.h
     Classes/Audio/AudioEngine.h
     Classes/Engine/Engine.h
     Classes/Game/Game.h
     Classes/Equipment/Type/Weapon/ChippedSword.h
     Classes/Equipment/EquipmentFactory.h
     Classes/Equipment/BaseEquipment.h
     Classes/Inventory/Inventory.h
     Classes/Inventory/InventoryNode.h
     Classes/BaseCharacter/BaseCharacter.h
     Classes/Enemies/ShadowLord/ShadowLord.h
     Classes/Enemies/Skeleton/Skeleton.h
     Classes/Enemies/Slime/Slime.h
     Classes/Enemies/Enemy.h
     Classes/Enemies/EnemyFactory.h
     Classes/PlayerCharacters/Fighter/Fighter.h
     Classes/PlayerCharacters/Knight/Knight.h
     Classes/PlayerCharacters/Warrior/Warrior.h
     Classes/PlayerCharacters/PlayerCharacter.h
     Classes/PlayerCharacters/PlayerCharacterFactory.h
     Classes/State/EnemiesState/EnemiesAttack.h
     Classes/State/EnemiesState/EnemiesDead.h
     Classes/State/EnemiesState/EnemiesIdle.h
     Classes/State/EnemiesState/EnemiesWalk.h
     Classes/State/EnemiesState/EnemiesStateBase.h
     Classes/State/PlayerCharacterState/PlayerCharacterAttack.h
     Classes/State/PlayerCharacterState/PlayerCharacterDead.h
     Classes/State/PlayerCharacterState/PlayerCharacterIdle.h
     Classes/State/PlayerCharacterState/PlayerCharacterSelect.h
     Classes/State/PlayerCharacterState/PlayerCharacterStateBase.h
     Classes/State/PlayerCharacterState/PlayerCharacterWalk.h
     Classes/State/BossState/BossAttack.h
     Classes/State/BossState/BossDead.h
     Classes/State/BossState/BossGetHit.h
     Classes/State/BossState/BossIdle.h
     Classes/State/BossState/BossRoar.h
     Classes/State/BossState/BossRun.h
     Classes/State/BossState/BossStateBase.h
     Classes/State/BossState/BossWalk.h
     Classes/UserInterface/InGame/Joystick.h
     Classes/LightEffect/Effect.h
     Classes/LightEffect/EffectSprite.h
     Classes/LightEffect/LightEffect.h
     Classes/Boss/Boss.h
     Classes/Boss/BossFactory.h
     Classes/Boss/HellBeast.h
          	Classes/MapDecoration/MapDecoration.h
Classes/Skills/SkillBase.h
Classes/Skills/SkillFactory.h
Classes/Skills/AOESkill/AOESkill.h
Classes/Skills/AOESkill/AOESkill1.h
Classes/Skills/AOESkill/AOESkill2.h
Classes/Skills/BuffSkill/BuffSkill.h
Classes/Skills/BuffSkill/BuffSkill1.h
Classes/Skills/BuffSkill/BuffSkill2.h
Classes/Skills/SkillShot/SkillShot.h
Classes/Skills/SkillShot/SkillShot1.h
Classes/Skills/SkillShot/SkillShot2.h
Classes/Skills/TargetSkill/TargetSkill.h
Classes/Skills/TargetSkill/TargetSkill1.h
Classes/Skills/TargetSkill/TargetSkill2.h





     )
     

if(ANDROID)
    # change APP_NAME to the share library name for Android, it's value depend on AndroidManifest.xml
    set(APP_NAME MyGame)
    list(APPEND GAME_SOURCE
         proj.android/app/jni/hellocpp/main.cpp
         )
elseif(LINUX)
    list(APPEND GAME_SOURCE
         proj.linux/main.cpp
         )
elseif(WINDOWS)
    list(APPEND GAME_HEADER
         proj.win32/main.h
         proj.win32/resource.h
         )
    list(APPEND GAME_SOURCE
         proj.win32/main.cpp
         proj.win32/game.rc
         ${common_res_files}
         )
elseif(APPLE)
    if(IOS)
        list(APPEND GAME_HEADER
             proj.ios_mac/ios/AppController.h
             proj.ios_mac/ios/RootViewController.h
             )
        set(APP_UI_RES
            proj.ios_mac/ios/LaunchScreen.storyboard
            proj.ios_mac/ios/LaunchScreenBackground.png
            proj.ios_mac/ios/Images.xcassets
            )
        list(APPEND GAME_SOURCE
             proj.ios_mac/ios/main.m
             proj.ios_mac/ios/AppController.mm
             proj.ios_mac/ios/RootViewController.mm
             proj.ios_mac/ios/Prefix.pch
             ${APP_UI_RES}
             )
    elseif(MACOSX)
        set(APP_UI_RES
            proj.ios_mac/mac/Icon.icns
            proj.ios_mac/mac/Info.plist
            )
        list(APPEND GAME_SOURCE
             proj.ios_mac/mac/main.cpp
             proj.ios_mac/mac/Prefix.pch
             ${APP_UI_RES}
             )
    endif()
    list(APPEND GAME_SOURCE ${common_res_files})
endif()

# mark app complie info and libs info
set(all_code_files
    ${GAME_HEADER}
    ${GAME_SOURCE}
    )
if(NOT ANDROID)
    add_executable(${APP_NAME} ${all_code_files})
else()
    add_library(${APP_NAME} SHARED ${all_code_files})
    add_subdirectory(${COCOS2DX_ROOT_PATH}/cocos/platform/android ${ENGINE_BINARY_PATH}/cocos/platform)
    target_link_libraries(${APP_NAME} -Wl,--whole-archive cpp_android_spec -Wl,--no-whole-archive)
endif()

target_link_libraries(${APP_NAME} cocos2d)
target_include_directories(${APP_NAME}
        PRIVATE Classes
        PRIVATE ${COCOS2DX_ROOT_PATH}/cocos/audio/include/
)

# mark app resources
setup_cocos_app_config(${APP_NAME})
if(APPLE)
    set_target_properties(${APP_NAME} PROPERTIES RESOURCE "${APP_UI_RES}")

    if(MACOSX)
        set_xcode_property(${APP_NAME} INFOPLIST_FILE "${CMAKE_CURRENT_SOURCE_DIR}/proj.ios_mac/mac/Info.plist")
    elseif(IOS)
        set_xcode_property(${APP_NAME} INFOPLIST_FILE "${CMAKE_CURRENT_SOURCE_DIR}/proj.ios_mac/ios/Info.plist")
        set_xcode_property(${APP_NAME} ASSETCATALOG_COMPILER_APPICON_NAME "AppIcon")
    endif()

    # For code-signing, set the DEVELOPMENT_TEAM:
    #set_xcode_property(${APP_NAME} DEVELOPMENT_TEAM "GRLXXXX2K9")
elseif(WINDOWS)
    cocos_copy_target_dll(${APP_NAME})
endif()

if(LINUX OR WINDOWS)
    cocos_get_resource_path(APP_RES_DIR ${APP_NAME})
    cocos_copy_target_res(${APP_NAME} LINK_TO ${APP_RES_DIR} FOLDERS ${GAME_RES_FOLDER})
endif()
