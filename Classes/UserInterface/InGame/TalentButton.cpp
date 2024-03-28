#include "TalentButton.h"
#include "TalentCarousel.h"

TalentButton* TalentButton::create(TalentCarousel* talentCarousel) {
    auto node = new TalentButton();
    if (node && node->init(talentCarousel)) {
        node->autorelease();
        return node;
    }
    CC_SAFE_DELETE(node);
    return nullptr;
}

bool TalentButton::init(TalentCarousel* talentCarousel) {
    if (!Node::init()) {
        return false;
    }
    talent = talentCarousel;
    btnSprite = Sprite::create("res/book_icon.png");
    btnSprite->setPosition(this->getPosition());
    btnSprite->setScale(3);
    //this->setContentSize(Size(btnSprite->getContentSize().width * 3, btnSprite->getContentSize().height * 3));
    this->addChild(btnSprite);

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(TalentButton::onTouchBegan, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, btnSprite);


    return true;
}

bool TalentButton::onTouchBegan(Touch* touch, Event* event) {
    if (btnSprite->getBoundingBox().containsPoint(this->convertToNodeSpace(touch->getLocation()))) {
        if (talent->isVisible())
            talent->setVisible(false);
        else
            talent->showTalentCarousel();
        return true;
    }
    return false;
}
