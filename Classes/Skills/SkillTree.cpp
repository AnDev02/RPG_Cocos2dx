//#include "SkillTree.h"
//#include "PlayerCharacters/PlayerCharacter.h"
//SkillTree* SkillTree::createSkillTree(PlayerCharacter* player) {
//    SkillTree* skill = new (std::nothrow) SkillTree();
//    if (skill && skill->init(player)) {
//        skill->autorelease();
//        return skill;
//    }
//    else {
//        delete skill;
//        skill = nullptr;
//        return nullptr;
//    }
//}
//
//bool SkillTree::init(PlayerCharacter* player) {
//	if (!Node::init()) {
//		return false;
//	}
//	skillRoot = SkillFactory::createSkill("skill 1");
//	skillRoot->retain();
//    drawTree(skillRoot, Vec2(0, 0), 150, 150, nullptr);
//    moneyLabel = Label::createWithTTF("Skill Point: " + std::to_string(player->getSkillPoint()), "fonts/arial.ttf", 22);
//    moneyLabel->setPositionX(200); // thay ??i 
//    this->addChild(moneyLabel);
//    auto listener = cocos2d::EventListenerTouchOneByOne::create();
//    listener->setSwallowTouches(true);
//    listener->onTouchBegan = [this, player](cocos2d::Touch* touch, cocos2d::Event* event) {
//            auto touchPoint = this->convertToNodeSpace(touch->getLocation());
//            if (!skillRects.empty()) {
//                for (auto parentNode : skillRects) {
//                    auto parentPosition = parentNode->getPosition();
//                    auto nodeSize = parentNode->getContentSize();
//                    auto parentBoundingBox = cocos2d::Rect(parentPosition.x - nodeSize.width / 2, parentPosition.y - nodeSize.height / 2, nodeSize.width, nodeSize.height);
//                    if (parentBoundingBox.containsPoint(touchPoint)) {
//                        auto skillNode = static_cast<BaseSkill*>(parentNode->getChildByName("skill sprite"));
//                        if (player->getSkillPoint() >= skillNode->getUnlockScore() && skillNode->parent != nullptr && !skillNode->parent->isLock()) {
//                            player->decreaseSkillPoint(skillNode->getUnlockScore());
//                            player->addSkill(skillNode->getSkillName());
//                            skillNode->unlock();
//                            moneyLabel->setString("Skill Point: " + std::to_string(player->getSkillPoint()));
//                            return true;
//                        }
//                    }
//                }
//            }
//            return false;
//        };
//
//    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
//
//
//	return true;
//}
//void SkillTree::drawTree(BaseSkill* node, Vec2 position, float xSpacing, float ySpacing, BaseSkill* parent) {
//    Node* parentNode = Node::create();
//    node->setName("skill sprite");
//    if (parent) node->parent = parent;
//    parentNode->addChild(node, 5);
//    parentNode->setPosition(position);
//    if (node->getUnlockScore() != 0) {
//        auto scoreToUnlock = Label::createWithTTF(std::to_string(node->getUnlockScore()), "fonts/arial.ttf", 19);
//        scoreToUnlock->setPosition(node->getSkillSprite()->getContentSize().width * 0.1 / 2, node->getSkillSprite()->getContentSize().height * 0.1 / 2);
//        parentNode->addChild(scoreToUnlock, 20);
//    }
//    this->addChild(parentNode, 2);
//    parentNode->setContentSize(node->getSkillSprite()->getContentSize() * 0.1);
//    skillRects.push_back(parentNode);
//
//    Vec2 childPosition = position - Vec2(0, ySpacing);
//
//    for (auto child : node->children) {
//        auto drawNode = DrawNode::create();
//        drawNode->drawLine(position, childPosition, Color4F::WHITE);
//        this->addChild(drawNode, 1);
//
//        drawTree(child, childPosition, xSpacing, ySpacing, node);
//
//        childPosition.x += xSpacing;
//    }
//}
//
//SkillTree::~SkillTree() {
//	skillRoot->release();
//}