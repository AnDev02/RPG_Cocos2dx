#include "DarkHole.h"
#include "PlayerCharacters/PlayerCharacter.h"
#include "Skills/SkillFactory.h"
#include <string>
bool DarkHole::init() {

   /* struct SkillTalent {
        std::string skillName;
        std::string iconPath;
        int unlockPoint;
        std::string description;
        std::string skillType;
        SkillBase::SkillTalent* parent;
        std::vector<SkillBase::SkillTalent*> children;
        bool isLock;
    };*/

    skillTalent = new SkillTalent;
    skillTalent->skillName = "DarkHole";
    skillTalent->iconPath = "skill/SkillSprite/SkillIcon/10.png";
    skillTalent->unlockPoint = 10;
    skillTalent->description = "black like squid";
    skillTalent->skillType = "AOE";
    skillTalent->parent = nullptr;
    skillTalent->children.push_back(SkillFactory::createSkill("ElectricArea")->getSkillTalent());
    skillTalent->children.push_back(SkillFactory::createSkill("FireFlower")->getSkillTalent());
    skillTalent->children.push_back(SkillFactory::createSkill("IllumiArea")->getSkillTalent());
    skillTalent->isLock = true;
	
    //AOE Range
    _aoeSprite = Sprite::create("skill/AOERangeSprite/CircleRange.png");
    _aoeSprite->setOpacity(100);
    this->addChild(_aoeSprite);
    _aoeSprite->setVisible(false);

    //Skill Icon...
    _iconSprite = Sprite::create(skillTalent->iconPath);
    _iconSprite->setScale(0.1);
    _iconSprite->retain();

    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("skill/SkillSprite/AOESkill/dark_hole/dark_hole.plist", "skill/SkillSprite/AOESkill/dark_hole/dark_hole.png");
    //Skill Sprite
    _skillSprite = Sprite::createWithSpriteFrameName("dark_hole (1).png");
    _skillSprite->setAnchorPoint(Vec2(0.5, 0.5));
    _skillSprite->retain();

    //Skill Animate
    _skillAnimate = Animate::create(Engine::createAnimation2("dark_hole", 27, 0.05));
    _skillAnimate->retain();

    //SkillButton
    _skillButton = SkillButton::create();
    _skillButton->setSkillButtonBorder(_iconSprite);
    _skillButton->setPosition(Vec2(100, 0));
    this->addChild(_skillButton);
    _skillButton->setVisible(true);

    //SkillTree...
    
    // Đăng ký sự kiện onTouch cho SkillButton
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(DarkHole::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(DarkHole::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(DarkHole::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, _skillButton);
    schedule(CC_SCHEDULE_SELECTOR(DarkHole::update), 0.05f);

	return true;
}

bool DarkHole::onTouchBegan(Touch* touch, Event* event)
{

    Vec2 touchLocationInNode = _skillButton->convertToNodeSpace(touch->getLocation());

    if (_skillButton->skillButtonBtn->getBoundingBox().containsPoint(touchLocationInNode))
    {
        _skillButton->isPressed = true;
        this->_aoeSprite->setVisible(true);
        _skillButton->cancelButton->setVisible(true);

        return true;
    }
    return false;
}

void DarkHole::onTouchMoved(Touch* touch, Event* event)
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

        Vec2 lastTouchLocationInNode = _skillButton->convertToNodeSpace(touch->getLocation());
        if (_skillButton->cancelButton->getBoundingBox().containsPoint(lastTouchLocationInNode)) {
            _skillButton->cancelButton->setOpacity(200);
        }
        else _skillButton->cancelButton->setOpacity(50);

        float rate = _skillButton->getCurrentPos().distance(_skillButton->getCenterPos()) / 40;

        auto dir = _skillButton->getDirection();
        dir.normalize();

        Vec2 out = this->getPosition() + dir * rate * 100;
        this->_aoeSprite->setPosition(out);

    }
}

void DarkHole::onTouchEnded(Touch* touch, Event* event)
{
    _skillButton->prevPosBeforeRelease = _skillButton->skillButtonBtn->getPosition();
    _skillButton->skillButtonBtn->setPosition(_skillButton->centerPos);
    _skillButton->isPressed = false;

    Vec2 lastTouchLocationInNode = _skillButton->convertToNodeSpace(touch->getLocation());
    if (_skillButton->cancelButton->getBoundingBox().containsPoint(lastTouchLocationInNode)) {
        this->_aoeSprite->setVisible(false);
        _skillButton->cancelButton->setVisible(false);
        return;
    }

    Vec2 pos = this->convertToWorldSpace(this->_aoeSprite->getPosition());
    performSkill(pos);
    this->_aoeSprite->setVisible(false);
    _skillButton->cancelButton->setVisible(false);
}

void DarkHole::performSkill(Vec2 target) {

    Vec2 applyPosition = this->getParent()->getParent()->convertToNodeSpace(target);
    _skillSprite->setPosition(applyPosition);
    auto scene = this->getParent()->getScene();
    scene->addChild(_skillSprite);

    auto sqe = Sequence::create(_skillAnimate, RemoveSelf::create(), nullptr);
    _skillSprite->runAction(sqe);
}