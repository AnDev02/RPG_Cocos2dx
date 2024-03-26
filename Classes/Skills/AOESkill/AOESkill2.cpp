#include "AOESkill2.h"
#include "PlayerCharacters/PlayerCharacter.h"
bool AOESkill2::init() {

    //AOE Range
    _aoeSprite = Sprite::create("skill/AOERangeSprite/CircleRange.png");
    _aoeSprite->setOpacity(100);
    this->addChild(_aoeSprite);
    _aoeSprite->setVisible(false);

    //Skill Icon...
    iconSpritePath = "skill/SkillSprite/16.png";
    _iconSprite = Sprite::create(iconSpritePath);
    _iconSprite->setScale(0.1);
    _iconSprite->retain();


    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("skill/SkillSprite/thunder/thunder.plist", "skill/SkillSprite/thunder/thunder.png");
    //Skill Sprite
    _skillSprite = Sprite::createWithSpriteFrameName("thunder (1).png");
    _skillSprite->setAnchorPoint(Vec2(0.5, 0.5));
    _skillSprite->setScale(2);
    _skillSprite->retain();

    //Skill Animate
    _skillAnimate = Animate::create(Engine::createAnimation2("thunder", 13, 0.05));
    _skillAnimate->retain();

    //SkillButton
    _skillButton = SkillButton::create();
    _skillButton->setSkillButtonBorder(_iconSprite);
    _skillButton->setPosition(Vec2(100, 0));
    this->addChild(_skillButton);
    _skillButton->setVisible(true);

    ////SkillTree...

    // Đăng ký sự kiện onTouch cho SkillButton
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(AOESkill2::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(AOESkill2::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(AOESkill2::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, _skillButton);
    schedule(CC_SCHEDULE_SELECTOR(AOESkill2::update), 0.05f);

    return true;
}
void AOESkill2::update(float dt) {
    /*if (_skillButton->getIsPress()) {

        float rate = _skillButton->getCurrentPos().distance(_skillButton->getCenterPos()) / 40;
        if (!this->_aoeSprite->isVisible()) {

            this->_aoeSprite->setVisible(true);
        }

        auto dir = _skillButton->getDirection();
        dir.normalize();
        
        this->cursorPos = this->getPosition() + dir * rate * 100;
        this->_aoeSprite->setPosition(this->cursorPos);
    }*/
    /*else {
        if (this->_aoeSprite->isVisible()) {
            this->_aoeSprite->setVisible(false);

            auto sprite = Sprite::create("HelloWorld.png");
            Vec2 worldPosition = _aoeSprite->getParent()->convertToWorldSpace(_aoeSprite->getPosition());
            CCLOG("Perform FireBall to: %f, %f", worldPosition.x, worldPosition.y);
            sprite->setPosition(worldPosition);
            sprite->setScale(0.1);
            auto scene = this->getParent()->getScene();
            scene->addChild(sprite, 1000);
        }
    }*/
}