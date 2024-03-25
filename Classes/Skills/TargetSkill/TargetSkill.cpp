#include "TargetSkill.h"
#include "HelloWorldScene.h"
#include "Enemies/Enemy.h"
#include "Game/Game.h"

bool TargetSkill::init() {
    return true;
}

bool TargetSkill::onTouchBegan(Touch* touch, Event* event)
{

    Vec2 touchLocationInNode = _skillButton->convertToNodeSpace(touch->getLocation());

    if (_skillButton->skillButtonBtn->getBoundingBox().containsPoint(touchLocationInNode))
    {
        _skillButton->isPressed = true;
        this->_aoeSprite->setVisible(true);
        return true;
    }
    return false;
}

void TargetSkill::onTouchMoved(Touch* touch, Event* event)
{
    if (_skillButton->isPressed)
    {
        CCLOG("Moving");
        Vec2 touchLocationInNode = _skillButton->convertToNodeSpace(touch->getLocation());
        Vec2 direction = touchLocationInNode - _skillButton->centerPos;
        float distance = direction.length();

        float radius = 40;

        if (distance > radius)
        {
            direction.normalize();
            direction *= radius;
            _skillButton->skillButtonBtn->setPosition(_skillButton->centerPos + direction);
            _skillButton->currentPos = _skillButton->centerPos + direction;
        }
        else
        {
            _skillButton->skillButtonBtn->setPosition(touchLocationInNode);
            _skillButton->currentPos = touchLocationInNode;
        }
        //Detect all Enemies and Boss be added to scene
          // Lấy scene chính từ Director
        Scene* currentScene = Director::getInstance()->getRunningScene();
        if (currentScene) {
            HelloWorld* helloWorld = dynamic_cast<HelloWorld*>(currentScene->getChildByName("HelloWorldInstance"));
            if (helloWorld) {
                Game* game = helloWorld->game;
                auto children = game->getChildren();
                for (const auto& child : children) {
                    auto enemy = dynamic_cast<Enemy*>(child);
                    if (enemy) {
                        Vec2 enemyInWorldCoor = enemy->getParent()->convertToWorldSpace(enemy->getPosition());
                        Vec2 enemyInSkillCoor = this->convertToNodeSpace(enemyInWorldCoor);

                        float distance = enemyInSkillCoor.distance(this->getPosition());

                        if (distance <= applyRange) {
                            //If enemy in range and not have target then: 
                            if (!enemy->getChildByName("Target")) {
                                auto target = Sprite::create("skill/AOERangeSprite/Target.png");
                                target->setName("Target");
                                enemy->addChild(target);
                                enemies.push_back(enemy);
                            }
                        }
                        else {
                            if (enemy->getChildByName("Target")) {
                                auto sprite = enemy->getChildByName("Target");
                                enemy->removeChild(sprite);
                                auto it = std::find(enemies.begin(), enemies.end(), enemy);
                                // If found, erase it
                                if (it != enemies.end()) {
                                    enemies.erase(it);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    CCLOG("%d", enemies.size());
}

void TargetSkill::onTouchEnded(Touch* touch, Event* event)
{
    _skillButton->prevPosBeforeRelease = _skillButton->skillButtonBtn->getPosition();
    _skillButton->skillButtonBtn->setPosition(_skillButton->centerPos);
    _skillButton->isPressed = false;

    Vec2 pos = this->convertToWorldSpace(this->_aoeSprite->getPosition());
    performSkill(pos);
    this->_aoeSprite->setVisible(false);
}

void TargetSkill::performSkill(Vec2 target) {
    std::vector<Enemy*> enemiesRemove;
    for (auto enemy : enemies) {
        CCLOG("LULE");
        auto sprite = enemy->getChildByName("Target");
        auto skillSprite = Sprite::createWithSpriteFrameName("darkpower (1).png");
        skillSprite->setAnchorPoint(Vec2(0.5, 0.25));
        skillSprite->setScale(applyRange/skillSprite->getContentSize().width, applyRange / skillSprite->getContentSize().height);
        skillSprite->setPosition(sprite->getPosition());
        enemy->removeChild(sprite);
        enemy->addChild(skillSprite);

        //Skill Animate
        Animate* skillAnimate = Animate::create(Engine::createAnimation2("darkpower", 15, 0.1));

        auto sqe = Sequence::create(skillAnimate, RemoveSelf::create(), nullptr);

        skillSprite->runAction(sqe);
        enemiesRemove.push_back(enemy);
    }
    for(auto enemyRemove : enemiesRemove){
        //Remove from enemies
        auto it = std::find(enemies.begin(), enemies.end(), enemyRemove);
        // If found, erase it
        if (it != enemies.end()) {
                enemies.erase(it);
            }
    }
        

}
void TargetSkill::update(float dt) {

}