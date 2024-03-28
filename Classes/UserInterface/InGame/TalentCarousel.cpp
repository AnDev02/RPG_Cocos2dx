#include "TalentCarousel.h"
#include "PlayerCharacters/PlayerCharacter.h"
#include "Skills/SkillTree.h"
#include "Skills/SkillFactory.h"
TalentCarousel* TalentCarousel::create(PlayerCharacter* player) {
    auto node = new TalentCarousel();
    if (node && node->init(player)) {
        node->autorelease();
        return node;
    }
    CC_SAFE_DELETE(node);
    return nullptr;
}

bool TalentCarousel::init(PlayerCharacter* player) {
    if (!Node::init()) {
        return false;
    }
    this->setVisible(false);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    //CCLOG("%s asdasdsdsda sdsadsad", ->skillName.c_str());

    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(TalentCarousel::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(TalentCarousel::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(TalentCarousel::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);


    talentBorder = Sprite::create("res/talent-carousel.png");
    talentBorder->setScale(talentBorder->getContentSize().width / visibleSize.width, talentBorder->getContentSize().height / visibleSize.height);
    talentBorder->setPosition(0, 0);
    talentBorder->setRotation(90);
    this->setContentSize(Size(talentBorder->getContentSize().width * talentBorder->getContentSize().width / visibleSize.width, talentBorder->getContentSize().height * talentBorder->getContentSize().height / visibleSize.height));
    this->addChild(talentBorder);

    prevButton = Sprite::create("res/MediumArrow-Left.png");
    prevButton->setPosition(talentBorder->getPositionX() - talentBorder->getContentSize().width / 2 + prevButton->getContentSize().width * 2, talentBorder->getPositionY());
    prevButton->setScale(talentBorder->getContentSize().width / 50 / prevButton->getContentSize().width, talentBorder->getContentSize().width / 50 / prevButton->getContentSize().height);
    this->addChild(prevButton, 2);

    nextButton = Sprite::create("res/MediumArrow-Right.png");
    nextButton->setPosition(talentBorder->getPositionX() + talentBorder->getContentSize().width / 2 - nextButton->getContentSize().width * 2, talentBorder->getPositionY());
    nextButton->setScale(talentBorder->getContentSize().width / 50 / nextButton->getContentSize().width, talentBorder->getContentSize().width / 50 / nextButton->getContentSize().height);
    this->addChild(nextButton, 2);

    buttonClose = Sprite::create("res/c_header_close.png");
    buttonClose->setScale(0.4);
    buttonClose->setPosition(Vec2(talentBorder->getPositionX() + talentBorder->getContentSize().width / 2 - nextButton->getContentSize().width * 2, (talentBorder->getContentSize().height * (talentBorder->getContentSize().height / visibleSize.height)) / 4 - buttonClose->getContentSize().height * 0.2));
    this->addChild(buttonClose, 6);

    SkillTree* skillTreeAoe = SkillTree::createSkillTree(player, SkillFactory::createSkill("DarkHole")->getSkillTalent());
    SkillTree* skillTreeBuff = SkillTree::createSkillTree(player, SkillFactory::createSkill("FireHurricane")->getSkillTalent());
    listOfTrees.push_back(skillTreeAoe);
    listOfTrees.push_back(skillTreeBuff);

    for (int i = 0; i < listOfTrees.size(); i++)
    {
        listOfTrees[i]->setRotation(270);
        listOfTrees[i]->setAnchorPoint(Vec2(0, 0));
        listOfTrees[i]->setScale(0.2);
        listOfTrees[i]->setPosition(Vec2(-(talentBorder->getContentSize().width / 4 - prevButton->getContentSize().width), 0));
        this->addChild(listOfTrees[i], 3);
        if(i != 0)
            listOfTrees[i]->setVisible(false);
    }
    
  
    return true;
}

bool TalentCarousel::onTouchBegan(Touch* touch, Event* event) {
    if (isVisible()) {

        if (prevButton->getBoundingBox().containsPoint(this->convertToNodeSpace(touch->getLocation()))) {
            if (currentTree <= 0) {
                currentTree = static_cast<int>(listOfTrees.size()) - 1;
                listOfTrees[0]->setVisible(false);
            }
            else {
                currentTree-=1;
                listOfTrees[currentTree + 1]->setVisible(false);
            }
            listOfTrees[currentTree]->setVisible(true);
        } 
        if (nextButton->getBoundingBox().containsPoint(this->convertToNodeSpace(touch->getLocation()))) {
            if (currentTree >= static_cast<int>(listOfTrees.size()) - 1) {
                currentTree = 0;
                listOfTrees[static_cast<int>(listOfTrees.size()) - 1]->setVisible(false);
            }
            else {
                currentTree+=1;
                listOfTrees[currentTree - 1]->setVisible(false);
            }
            for (auto i : listOfTrees)
            {
                i->setVisible(false);
            }
            listOfTrees[currentTree]->setVisible(true);
        }
        auto startPoint = this->convertToNodeSpace(touch->getLocation());
        if (buttonClose->getBoundingBox().containsPoint(startPoint))
        {
            this->setVisible(false);
        }
        return true;
    }
    return false;
}

bool TalentCarousel::onTouchMoved(Touch* touch, Event* event)
{
    return false;
}

bool TalentCarousel::onTouchEnded(Touch* touch, Event* event)
{
    return false;
}

void TalentCarousel::showTalentCarousel() {
    this->setVisible(true);
}