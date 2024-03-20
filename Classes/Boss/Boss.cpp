#include "Boss.h"
#include "Game/Game.h"

bool Boss::init() {
	return true;
}

void Boss::detectPlayerCharacter() {

    // Vị trí của boss
    Vec2 bossPosition = this->getPosition();

    // Lấy scene chính từ Director
    Scene* currentScene = Director::getInstance()->getRunningScene();
    if (currentScene) {
        Game* helloWorld = dynamic_cast<Game*>(currentScene->getChildByName("GameInstance"));
        if (helloWorld) {
            auto children = helloWorld->getChildren();
            for (const auto& child : children) {
                // Kiểm tra xem đối tượng con có phải là PlayerCharacter không
                auto playerCharacter = dynamic_cast<PlayerCharacter*>(child);
                if (playerCharacter) {

                    // Tính khoảng cách giữa boss và playerCharacter
                    Vec2 playerPosition = playerCharacter->getPosition();
                    float distance = bossPosition.distance(playerPosition);

                    // Nếu playerCharacter nằm trong phạm vi phát hiện của boss
                    if (distance <= detectionRadius) {
                        // Đặt mục tiêu cho boss
                        setTarget(playerCharacter);
                        // Ngừng việc kiểm tra các playerCharacter khác nếu chỉ cần đặt một mục tiêu
                        return;
                    }
                }
            }
        }
    }
    setTarget(nullptr);

}

float Boss::calculateAngle(const Vec2& vectorA, const Vec2& vectorB) {
    // Tính góc giữa hai vector sử dụng atan2
    float angle = vectorA.getAngle(vectorB);

    // Chuyển góc từ radian sang độ
    auto degree = CC_RADIANS_TO_DEGREES(angle);


    return degree;
}

void Boss::runToTarget() {

    if (target) {
        // Vector hướng từ vị trí hiện tại tới vị trí mục tiêu
        Vec2 direction = (target->getPosition() - this->getPosition()).getNormalized();

        // Tính toán vận tốc dựa trên thời gian di chuyển mong muốn
        Vec2 velocity = direction * this->MS;

        // Thiết lập vận tốc cho Node
        this->getPhysicsBody()->setVelocity(velocity);

        float angleResult = calculateAngle(direction, Vec2(1, 0));

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

        CCLOG("boss in dir: %d", this->direction);
    }
}

void Boss::walkToTarget() {

}

void Boss::stopRunAndWalk() {
    //If Boss has Target, Boss will chase till reach Attack Range: isTargetInAttackRange=true;
    if (target) {
        if (this->getPosition().distance(target->getPosition()) <= attackRange) {
            this->getPhysicsBody()->setVelocity(Vec2::ZERO);
            isTargetInAttackRange = true;
        }
        else {
            isTargetInAttackRange = false;
        }
    }
    // No Target, Boss will Stand Idle
    else {
        this->getPhysicsBody()->setVelocity(Vec2::ZERO);
        isTargetInAttackRange = false;
    }
}

void Boss::update(float dt) {
    Boss::detectPlayerCharacter();
    Boss:runToTarget();
    //If distance closed, stop Boss
    Boss::stopRunAndWalk();
}

