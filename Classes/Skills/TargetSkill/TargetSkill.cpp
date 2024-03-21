#include "TargetSkill.h"

bool TargetSkill::init() {
	return true;
}

// Kích hoạt kỹ năng FireBall
void TargetSkill::activate() {
    // Hiển thị hình ảnh màu đỏ (AOE) và cập nhật vị trí của nó
    _aoeSprite->setVisible(true);
    // Bắt đầu lắng nghe sự kiện di chuyển chuột
    auto listener = EventListenerMouse::create();
    listener->onMouseMove = CC_CALLBACK_1(TargetSkill::onMouseMove, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);
}

// Thực hiện xử lý khi di chuyển chuột
void TargetSkill::onMouseMove(Event* event) {
    EventMouse* e = (EventMouse*)event;
    cursorPos = Vec2(e->getCursorX(), e->getCursorY());
    // Cập nhật vị trí của AOE theo vị trí chuột
    Vec2 cursorWorldPos = this->getParent()->convertToNodeSpace(cursorPos);

    // Cập nhật vị trí của AOE theo vị trí chuột trong world space

    _aoeSprite->setPosition(cursorWorldPos);
}

// Tắt kỹ năng FireBall
void TargetSkill::deactivate() {
    // Ẩn hình ảnh màu đỏ (AOE)
    _aoeSprite->setVisible(false);

    performSkill(cursorPos);
    // Loại bỏ lắng nghe sự kiện di chuyển chuột
    _eventDispatcher->removeEventListenersForTarget(this);
}

void TargetSkill::performSkill(Vec2 target) {
    /*Vec2 tar = */
    CCLOG("Perform FireBall to: %f, %f", target.x, target.y);
    auto sprite = Sprite::create("HelloWorld.png");
    Vec2 applyPosition = this->getParent()->getParent()->convertToNodeSpace(target);
    sprite->setPosition(applyPosition);
    sprite->setScale(0.1);
    auto scene = this->getParent()->getScene();
    scene->addChild(sprite);
}