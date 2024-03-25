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
    Size tileSize = tiledMap->getMapSize();
    int numColumns = tileSize.width;
    Size tileSize2 = tiledMap->getTileSize();
    int tileWidth = tileSize2.width;


    auto stencil = DrawNode::create();
    int radius = numColumns * tileWidth / 2; 
    int numPoints = 100;
    float angleStep = 2 * M_PI / numPoints;
    Vec2 circleCenter = Vec2(radius, radius); 
    stencil->drawSolidCircle(circleCenter, radius, angleStep, numPoints, Color4F::WHITE);

    auto clipNode = ClippingNode::create();
    clipNode->setStencil(stencil);
    clipNode->setInverted(false); 
    clipNode->setPosition(0, 0);
    clipNode->addChild(this->tiledMap);
    this->addChild(clipNode, 2);

    Sprite* minimapFrm = Sprite::create("res/minimap_frame.png");
    auto minimapFrmScaleWidth = tileSize.width * tileSize2.width / minimapFrm->getContentSize().width * 1.1;
    auto minimapFrmScaleHeight = tileSize.height * tileSize2.height / minimapFrm->getContentSize().height * 1.1;
    minimapFrm->setScale(minimapFrmScaleWidth, minimapFrmScaleHeight);
    minimapFrm->setPosition(tileSize.width * tileSize2.width / 2, tileSize.height * tileSize2.height / 2);
    this->addChild(minimapFrm, 1);
    mapSize = Size(minimapFrm->getContentSize().width * minimapFrmScaleWidth, minimapFrm->getContentSize().height * minimapFrmScaleHeight);
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