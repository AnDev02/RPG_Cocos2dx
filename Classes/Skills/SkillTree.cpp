#include "SkillTree.h"
#include "PlayerCharacters/PlayerCharacter.h"
#include "SkillFactory.h"
SkillTree* SkillTree::createSkillTree(PlayerCharacter* player, SkillBase::SkillTalent* skillRoot) {
    SkillTree* skill = new (std::nothrow) SkillTree();
    if (skill && skill->init(player, skillRoot)) {
        skill->autorelease();
        return skill;
    }
    else {
        delete skill;
        skill = nullptr;
        return nullptr;
    }
}

bool SkillTree::init(PlayerCharacter* player, SkillBase::SkillTalent* skillRoot) {
	if (!Node::init()) {
		return false;
	}
    visibleSize = Director::getInstance()->getVisibleSize();
    drawTree(skillRoot, Vec2(0, 0), 150, 150, nullptr);

    moneyLabel = Label::createWithTTF("Skill Point: " + std::to_string(player->getSkillPoint()), "fonts/arial.ttf", 22);
    moneyLabel->setRotation(90);
    moneyLabel->setPositionX(200); // thay ??i 
    this->addChild(moneyLabel);
    auto listener = cocos2d::EventListenerTouchOneByOne::create();
    listener->setSwallowTouches(true);
    listener->onTouchBegan = [this, player](cocos2d::Touch* touch, cocos2d::Event* event) {
            auto touchPoint = this->convertToNodeSpace(touch->getLocation());
            if (!skillRects.empty()) {
                for (auto parentNode : skillRects) {
                    auto parentPosition = std::get<1>(parentNode)->getPosition();
                    auto nodeSize = std::get<1>(parentNode)->getContentSize();
                    auto parentBoundingBox = cocos2d::Rect(parentPosition.x - nodeSize.width / 2, parentPosition.y - nodeSize.height / 2, nodeSize.width, nodeSize.height);
                    if (parentBoundingBox.containsPoint(touchPoint)) {
                        auto skillNode = SkillFactory::createSkill(std::get<0>(parentNode)->skillName);
                        if (player->getSkillPoint() >= std::get<0>(parentNode)->unlockPoint && std::get<0>(parentNode)->parent != nullptr && std::get<0>(parentNode)->isLock) {
                            player->decreaseSkillPoint(std::get<0>(parentNode)->unlockPoint);
                            player->addSkill(std::get<0>(parentNode)->skillName);
                            std::get<0>(parentNode)->isLock = false;
                            return true;
                        }
                    }
                }
            }
            return false;
        };

    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);


	return true;
}
void SkillTree::drawTree(SkillBase::SkillTalent* node, Vec2 position, float xSpacing, float ySpacing, SkillBase::SkillTalent* parent) {
    Node* parentNode = Node::create();
    auto skillSpr = Sprite::create(node->iconPath);
    skillSpr->setScale(0.0002f * visibleSize.width);
    this->setContentSize(Size(this->getContentSize().width, this->getContentSize().height));
    if (parent) node->parent = parent;
    parentNode->addChild(skillSpr, 5);
    parentNode->setPosition(position);
    if (node->unlockPoint != 0) {
        auto scoreToUnlock = Label::createWithTTF(std::to_string(node->unlockPoint), "fonts/arial.ttf", 19);
        scoreToUnlock->setPosition(skillSpr->getContentSize().width * 0.1 / 2, skillSpr->getContentSize().height * 0.1 / 2);
        parentNode->addChild(scoreToUnlock, 20);
    }
    this->addChild(parentNode, 2);
    parentNode->setContentSize(skillSpr->getContentSize() * 0.1);
    parentNode->setRotation(90);
    skillRects.push_back(std::make_tuple(node, parentNode));

    Vec2 childPosition = position - Vec2(0, ySpacing);
    if (static_cast<int>(node->children.size()) == 3) {
        childPosition = Vec2(-xSpacing, 0) + position - Vec2(0, ySpacing);
    }
    else if (static_cast<int>(node->children.size()) == 4) {
        childPosition = Vec2(-xSpacing * 2 + parentNode->getContentSize().width * (0.0002f * visibleSize.width), 0) + position - Vec2(0, ySpacing);
    }
    if (static_cast<int>(node->children.size()) > 0) {
        childrenQuan++;
    }
    else {
        treeHeight = skillSpr->getContentSize().height * 0.0002f * visibleSize.width + (childrenQuan * ySpacing) + (skillSpr->getContentSize().height * 0.0002f * visibleSize.width * childrenQuan);
    }
    for (auto child : node->children) {
        auto drawNode = DrawNode::create();
        drawNode->drawLine(position, childPosition, Color4F::WHITE);
        this->addChild(drawNode, 1);
        drawTree(child, childPosition, xSpacing, ySpacing, nullptr);
        childPosition.x += xSpacing;
    }
}

SkillTree::~SkillTree() {
}