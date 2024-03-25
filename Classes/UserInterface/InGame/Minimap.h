#ifndef __MINIMAP__
#define __MINIMAP__

#include "cocos2d.h"

USING_NS_CC;
class PlayerCharacter;
class MinimapLayer : public Layer
{
public:
    static MinimapLayer* create(std::string mapName, PlayerCharacter* player);
    bool initWithTiledMap(std::string mapName, PlayerCharacter* player);
    void update(float dt);
    const float MINIMAP_SCALE_FACTOR = 0.05f;
    const int PLAYER_DOT_TAG = 1001;
    Size getMapSize() const { return mapSize; };
private:
    PlayerCharacter* _player;
    TMXTiledMap* tiledMap;
    DrawNode* playerDot;
    Vec2 getPlayerPosition();
    Vec2 convertToMiniMapPosition(Vec2 tiledMapPosition);
    void drawMiniMapBorder();
    Size mapSize;


};

#endif // __MINIMAP__