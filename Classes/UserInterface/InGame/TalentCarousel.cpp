#include "TalentCarousel.h"
#include "Player/Player.h"
#include "Skills/SkillTree.h"
#include "Skills/SkillFactory.h"
#include "Audio/AudioEngine.h"
#include "SettingsManager/SettingsData.h"
#include "TutorialManager/TutorialManager.h"
#include "Game/Game.h"
#include "TalentProgressBar.h"

//int TalentCarousel::currentTree = 0;

TalentCarousel* TalentCarousel::create(Player* player) {
    auto node = new TalentCarousel();
    if (node && node->init(player)) {
        node->autorelease();
        return node;
    }
    CC_SAFE_DELETE(node);
    return nullptr;
}

bool TalentCarousel::init(Player* player) {
    if (!Node::init()) {
        return false;
    }
    _player = player;
    this->setVisible(false);
    auto visibleSize = Director::getInstance()->getVisibleSize();
    //CCLOG("%s asdasdsdsda sdsadsad", ->skillName.c_str());

     touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(TalentCarousel::onTouchBegan, this);
    touchListener->onTouchMoved = CC_CALLBACK_2(TalentCarousel::onTouchMoved, this);
    touchListener->onTouchEnded = CC_CALLBACK_2(TalentCarousel::onTouchEnded, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

    talentBorder = Sprite::create("res/background-img-4.png");
    //talentBorder->setOpacity(160);
    this->setContentSize(talentBorder->getContentSize());
    this->addChild(talentBorder);

    fireTreeTabButton = Sprite::create("res/button_tab.png");
    auto fireTreeLabel = Label::createWithTTF("Fire Skills", "fonts/Diablo Heavy.ttf", 13);
    fireTreeLabel->setName("label");
    fireTreeLabel->setScale(0.68);
    fireTreeLabel->setPosition(Vec2(fireTreeTabButton->getContentSize().width / 2, fireTreeTabButton->getContentSize().height / 2));
    fireTreeTabButton->setScale(0.50);
    fireTreeTabButton->addChild(fireTreeLabel);
    fireTreeTabButton->setPosition(Vec2(-fireTreeTabButton->getContentSize().width / 4, talentBorder->getContentSize().height / 2 - fireTreeTabButton->getContentSize().height * fireTreeTabButton->getScaleY() * 1.2));
    fireTreeTabButton->setOpacity(180);
    this->addChild(fireTreeTabButton);

    thunderTreeTabButton = Sprite::create("res/button_tab.png");
    auto thunderTreeLabel = Label::createWithTTF("Thunder Skills", "fonts/Diablo Heavy.ttf", 13);
    thunderTreeLabel->setName("label");
    thunderTreeLabel->setScale(0.68);
    thunderTreeLabel->setPosition(Vec2(thunderTreeTabButton->getContentSize().width / 2, thunderTreeTabButton->getContentSize().height / 2));
    thunderTreeTabButton->setScale(0.50);
    thunderTreeTabButton->addChild(thunderTreeLabel);
    thunderTreeTabButton->setPosition(Vec2(thunderTreeTabButton->getContentSize().width / 4, talentBorder->getContentSize().height / 2 - thunderTreeTabButton->getContentSize().height * thunderTreeTabButton->getScaleY() * 1.2));
    thunderTreeTabButton->setOpacity(180);
    this->addChild(thunderTreeTabButton);

    buttonClose = Sprite::create("res/c_header_close.png");
    buttonClose->setScale(0.6 * Director::getInstance()->getContentScaleFactor());
    buttonClose->setPosition(Vec2((talentBorder->getContentSize().width / 2 - buttonClose->getContentSize().width * buttonClose->getScale() * 1.5), (talentBorder->getContentSize().height / 2 - buttonClose->getContentSize().height * buttonClose->getScale() * 1.5)));
    this->addChild(buttonClose, 6);

    skillTreeAoe = SkillTree::createSkillTree(player, SkillFactory::createSkill("FireBall")->getSkillTalent());
    skillTreeAoe->treeName = "Fire";
    skillTreeBuff = SkillTree::createSkillTree(player, SkillFactory::createSkill("ThunderCrackle")->getSkillTalent());
    skillTreeBuff->treeName = "Thunder";
    listOfTrees.push_back(skillTreeAoe);
    listOfTrees.push_back(skillTreeBuff);
    skillTreeAoe->setParentNode(this);
    skillTreeBuff->setParentNode(this);

    progressBar = TalentProgressBar::create();
    progressBar->setScale(Director::getInstance()->getContentScaleFactor());
    progressBar->setPosition(Vec2(0, -talentBorder->getContentSize().height / 2 + progressBar->getContentSize().height * progressBar->getScaleY() + 6 * Director::getInstance()->getContentScaleFactor()));
    this->addChild(progressBar, 3);
    progressBar->updateProgress(player->getExpToConsume(), player->getAllExp());
    
    auto overlay = LayerColor::create(Color4B(0, 0, 0, 128)); // Màu đen, 128 là độ trong suốt
    overlay->setPosition(Vec2(-overlay->getContentSize().width / 2, -overlay->getContentSize().height / 2));
    this->addChild(overlay, 2);
    overlay->setVisible(false);
    for (int i = 0; i < listOfTrees.size(); i++)
    {
        listOfTrees[i]->setScale(0.15);
        listOfTrees[i]->setPosition(Vec2(-talentBorder->getContentSize().width / 2 + 39 * Director::getInstance()->getContentScaleFactor(), 22 * Director::getInstance()->getContentScaleFactor()));
        listOfTrees[i]->setProgressBar(progressBar);
        this->addChild(listOfTrees[i], 4);
        listOfTrees[i]->setVisible(false);
    }


    fireTreeTabButton->setTexture("res/button_tab.png");
    thunderTreeTabButton->setTexture("res/button_tab_push.png");
    listOfTrees[0]->setVisible(true);
    listOfTrees[1]->setVisible(false);
    currentTree = 0;
    dynamic_cast<Label*>(thunderTreeTabButton->getChildByName("label"))->setColor(Color3B::BLACK);
    dynamic_cast<Label*>(fireTreeTabButton->getChildByName("label"))->setColor(Color3B::WHITE);
    return true;
}

bool TalentCarousel::onTouchBegan(Touch* touch, Event* event) {
    if (isVisible()) {
        if (fireTreeTabButton->getBoundingBox().containsPoint(this->convertToNodeSpace(touch->getLocation()))) {
            skillTreeAoe->moneyLabel->setString(StringUtils::format("Skill Point: %d", _player->getSkillPoint()));
            skillTreeBuff->moneyLabel->setString(StringUtils::format("Skill Point: %d", _player->getSkillPoint()));
            UserDefault::getInstance()->setIntegerForKey("sound_effect", Audio::getInstance()->play2d("sound/sounds effect/click_button_sound.mp3", false, SettingsData::getInstance()->getSoundSlider() / 100.0f));
            listOfTrees[0]->setVisible(true);
            listOfTrees[1]->setVisible(false);
            lastChoosedFirstTab = true;
            currentTree = 0;
            fireTreeTabButton->setTexture("res/button_tab_push.png");
            dynamic_cast<Label*>(fireTreeTabButton->getChildByName("label"))->setColor(Color3B::BLACK);
            thunderTreeTabButton->setTexture("res/button_tab.png");
            dynamic_cast<Label*>(thunderTreeTabButton->getChildByName("label"))->setColor(Color3B::WHITE);
        } 
        if (thunderTreeTabButton->getBoundingBox().containsPoint(this->convertToNodeSpace(touch->getLocation()))) {
            skillTreeAoe->moneyLabel->setString(StringUtils::format("Skill Point: %d", _player->getSkillPoint()));
            skillTreeBuff->moneyLabel->setString(StringUtils::format("Skill Point: %d", _player->getSkillPoint()));
            UserDefault::getInstance()->setIntegerForKey("sound_effect", Audio::getInstance()->play2d("sound/sounds effect/click_button_sound.mp3", false, SettingsData::getInstance()->getSoundSlider() / 100.0f));
            listOfTrees[0]->setVisible(false);
            listOfTrees[1]->setVisible(true);
            currentTree = 1;
            lastChoosedFirstTab = false;
            thunderTreeTabButton->setTexture("res/button_tab_push.png");
            dynamic_cast<Label*>(thunderTreeTabButton->getChildByName("label"))->setColor(Color3B::BLACK);
            fireTreeTabButton->setTexture("res/button_tab.png");
            dynamic_cast<Label*>(fireTreeTabButton->getChildByName("label"))->setColor(Color3B::WHITE);
        }
        auto startPoint = this->convertToNodeSpace(touch->getLocation());
        if (buttonClose->getBoundingBox().containsPoint(startPoint))
        {
            UserDefault::getInstance()->setIntegerForKey("sound_effect", Audio::getInstance()->play2d("sound/sounds effect/click_button_sound.mp3", false, SettingsData::getInstance()->getSoundSlider() / 100.0f));

            resetUI();

            Scene* currentScene = Director::getInstance()->getRunningScene();
            Game* game = dynamic_cast<Game*>(currentScene->getChildByName("GameInstance"));
            game->resumeGame();

            this->setVisible(false);
            listOfTrees[currentTree]->setVisible(false);

            int currentTutorial = UserDefault::getInstance()->getIntegerForKey("current_tutorial", 0);
            if (currentTutorial >= 5 && currentTutorial < 8) {
                TutorialManager::getInstance()->showTutorial(4);
            }


            if (currentTutorial == 8) {
                TutorialManager::getInstance()->nextTutorial();
            }
            /*if (listOfTrees[currentTree]->skillDetail->getChildByName("Slot1")) {
                listOfTrees[currentTree]->_touchListenerSlot1->setEnabled(false);
                listOfTrees[currentTree]->_touchListenerSlot2->setEnabled(false);
                listOfTrees[currentTree]->_touchListenerSlot3->setEnabled(false);
                listOfTrees[currentTree]->_touchListenerSlot4->setEnabled(false);
            }*/
        }
        return true;
    }
    return false;
}

void TalentCarousel::resetUI() {
    currentTree == 1 ? listOfTrees[1]->setVisible(true) : listOfTrees[1]->setVisible(false);
    currentTree == 0 ? listOfTrees[0]->setVisible(true) : listOfTrees[0]->setVisible(false);
    currentTree == 1 == true ? thunderTreeTabButton->setTexture("res/button_tab_push.png") : thunderTreeTabButton->setTexture("res/button_tab.png");
    currentTree == 0 ? fireTreeTabButton->setTexture("res/button_tab_push.png") : fireTreeTabButton->setTexture("res/button_tab.png");
    currentTree == 1 == true ? dynamic_cast<Label*>(thunderTreeTabButton->getChildByName("label"))->setColor(Color3B::BLACK) : dynamic_cast<Label*>(thunderTreeTabButton->getChildByName("label"))->setColor(Color3B::WHITE);
    currentTree == 0 ? dynamic_cast<Label*>(fireTreeTabButton->getChildByName("label"))->setColor(Color3B::BLACK) : dynamic_cast<Label*>(fireTreeTabButton->getChildByName("label"))->setColor(Color3B::WHITE);
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
    resetUI();
   // listOfTrees[currentTree]->setVisible(true);
    progressBar->updateProgress(_player->getExpToConsume(), _player->getAllExp());
}

void TalentCarousel::hideComponents() {
    fireTreeTabButton->setVisible(false);
    thunderTreeTabButton->setVisible(false);
    buttonClose->setVisible(false);
    talentBorder->setVisible(false);
    progressBar->setVisible(false);
}

void TalentCarousel::showComponents() {
    fireTreeTabButton->setVisible(true);
    fireTreeTabButton->setTexture("res/button_tab_push.png");
    thunderTreeTabButton->setTexture("res/button_tab.png");
    dynamic_cast<Label*>(fireTreeTabButton->getChildByName("label"))->setColor(Color3B::BLACK);
    dynamic_cast<Label*>(thunderTreeTabButton->getChildByName("label"))->setColor(Color3B::WHITE);
    thunderTreeTabButton->setVisible(true);
    buttonClose->setVisible(true);
    talentBorder->setVisible(true);
    progressBar->setVisible(true);
}