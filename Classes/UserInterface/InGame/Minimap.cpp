#include "Minimap.h"
#include "PlayerCharacters/PlayerCharacter.h"

MinimapLayer* MinimapLayer::create(std::string mapName, PlayerCharacter* player) {
    auto layer = new MinimapLayer();
    if (layer && layer->initWithTiledMap(mapName, player)) {
        layer->autorelease();
        return layer;
    }
    CC_SAFE_DELETE(layer);
    return nullptr;
}

bool MinimapLayer::initWithTiledMap(std::string mapName, PlayerCharacter* player) {
    if (!Layer::init()) {
        return false;
    }
    playerDot = DrawNode::create();
    playerDot->drawDot(Vec2::ZERO, 20, Color4F::RED);
    this->addChild(playerDot, 1000);
    this->tiledMap = new TMXTiledMap();
    this->tiledMap->initWithTMXFile(mapName);
    this->addChild(this->tiledMap);
    this->drawMiniMapBorder();
    this->scheduleUpdate();
    this->_player = player;

    return true;
}

Vec2 MinimapLayer::getPlayerPosition() {
    if(_player)
        return this->_player->getPosition();
    return Vec2::ZERO;
}
Vec2 MinimapLayer::convertToMiniMapPosition(Vec2 tiledMapPosition) {
    return Vec2(tiledMapPosition.x, tiledMapPosition.y);
}
void MinimapLayer::drawMiniMapBorder() {
    auto drawNode = DrawNode::create();
    drawNode->drawRect(Vec2::ZERO, Vec2(tiledMap->getMapSize().width * tiledMap->getTileSize().width, tiledMap->getMapSize().height * tiledMap->getTileSize().height), Color4F::BLACK);
    this->addChild(drawNode, 999);
}

void MinimapLayer::update(float dt) {
    playerDot->setPosition(convertToMiniMapPosition(getPlayerPosition()));
}