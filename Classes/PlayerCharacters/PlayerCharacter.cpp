#include "PlayerCharacter.h"

bool PlayerCharacter::init() {
    if (!Node::init()) return false;

        //     Director::getInstance()->getRunningScene()->addChild(_joystick, 5000);
             //this->getScene()->addChild(_joystick, 4000);
    return true;
}

void PlayerCharacter::onMouseDown(Event* event)
{
    //EventMouse* e = dynamic_cast<EventMouse*>(event);
    //if (e)
    //{
    //    // Lấy tọa độ chuột khi click
    //    Vec2 mousePos = Vec2(e->getCursorX(), e->getCursorY());

    //    // Xử lý logic của bạn dựa trên vị trí chuột
    //    // Ví dụ: in ra tọa độ chuột
    //    log("Mouse Clicked at (%.2f, %.2f)", mousePos.x, mousePos.y);


    //    movePlayerToPosition(mousePos);
    //}
}

void PlayerCharacter::onKeyPressed(EventKeyboard::KeyCode keyCode, Event* event) {
    switch (keyCode) {
    case EventKeyboard::KeyCode::KEY_Q:
        this->skills[0]->activate();
        break;
    case EventKeyboard::KeyCode::KEY_W:
        this->skills[1]->activate();
        break;
    case EventKeyboard::KeyCode::KEY_E:
        this->skills[2]->activate();
        break;
    case EventKeyboard::KeyCode::KEY_R:
        this->skills[3]->activate();
        break;
    }
}

void PlayerCharacter::onKeyReleased(EventKeyboard::KeyCode keyCode, Event* event) {
    switch (keyCode) {
    case EventKeyboard::KeyCode::KEY_Q:
        this->skills[0]->deactivate();
        break;
    case EventKeyboard::KeyCode::KEY_W:
        this->skills[1]->deactivate();
        break;
    case EventKeyboard::KeyCode::KEY_E:
        this->skills[2]->deactivate();
        break;
    case EventKeyboard::KeyCode::KEY_R:
        this->skills[3]->deactivate();
        break;
    }
}

float PlayerCharacter::calculateAngle(const Vec2& vectorA, const Vec2& vectorB) {
    // Tính góc giữa hai vector sử dụng atan2
    float angle = vectorA.getAngle(vectorB);

    // Chuyển góc từ radian sang độ
    auto degree = CC_RADIANS_TO_DEGREES(angle);


    return degree;
}

void PlayerCharacter::handleMove(float deltaTime) {
   /* mouseClickPos = targetPosition;
    Vec2 currentPosition = this->getPosition();*/
    if (_joystick) {
        Vec2 direction = _joystick->getDirection();
            this->getPhysicsBody()->setVelocity(direction * (this->MS / 10));

            float angleResult = calculateAngle(direction, Vec2(1, 0));

            CCLOG("Degree: %f", angleResult);

            if (angleResult >= -22.5 && angleResult < 0) { this->direction = 1; } //E
            if (angleResult >= -45 && angleResult < -22.5) { this->direction = 2; } //NEE
            if (angleResult >= -67.5 && angleResult < -45) { this->direction = 3; } //NE
            if (angleResult >= -90 && angleResult < -67.5) { this->direction = 4; } //NNE
            if (angleResult >= -112.5 && angleResult < -90) { this->direction = 5; } //N
            if (angleResult >= -135 && angleResult < -112.5) { this->direction = 6; } //NNW
            if (angleResult >= -157.5 && angleResult < -135) { this->direction = 7; } //NW
            if (angleResult >= -180 && angleResult < -157.5) { this->direction = 8; } //NWW

            if (angleResult >= 157.5 && angleResult < 180) { this->direction = 9; } //W
            if (angleResult >= 135 && angleResult < 157.5) { this->direction = 10; } //SWW
            if (angleResult >= 112.5 && angleResult < 135) { this->direction = 11; } //SW
            if (angleResult >= 90 && angleResult < 112.5) { this->direction = 12; } //SSW
            if (angleResult >= 67.5 && angleResult < 90) { this->direction = 13; } //S
            if (angleResult >= 45 && angleResult < 67.5) { this->direction = 14; } //SSE
            if (angleResult >= 22.5 && angleResult < 45) { this->direction = 15; } //SE
            if (angleResult >= 0 && angleResult < 22.5) { this->direction = 16; } //SEE
            CCLOG("Dir: %d", this->direction);
    }
}

void PlayerCharacter::update(float dt) {
  

    if (!_joystick) {
        _joystick = Joystick::create();
        if (_joystick && this->getScene())
            this->getScene()->addChild(_joystick, 5000);
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    _joystick->setPosition(this->getPosition() - Vec2(visibleSize.width / 4, visibleSize.height / 4));
    handleMove(dt);
    //Vec2 currentPosition = this->getPosition();
  //float distance = currentPosition.distance(mouseClickPos);

  //if (distance < 5.0f) {  // Chọn một ngưỡng nhỏ đủ để xác định đã đến đích
  //    this->getPhysicsBody()->setVelocity(Vec2::ZERO);
  //}
}