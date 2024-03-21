#include "../MapDecoration/MapDecoration.h"

MapDecoration* MapDecoration::instance = nullptr;


MapDecoration* MapDecoration::getInstance(TMXTiledMap* _tileMap) {
	if (!instance) {
		instance = new MapDecoration(_tileMap);
	}
	return instance;
}
MapDecoration::MapDecoration(TMXTiledMap* _tileMap) : _tileMap(_tileMap) {}

bool MapDecoration::loadDecoration(std::string objectLayerName)
{
	TMXObjectGroup* ObjectLayerGroup = _tileMap->getObjectGroup(objectLayerName);
	if (ObjectLayerGroup) {
		ValueVector& objects = ObjectLayerGroup->getObjects();
		for (const auto& object : objects) {
			ValueMap objectProperties = object.asValueMap();
			float x = objectProperties["x"].asFloat();
			float y = objectProperties["y"].asFloat();
			if (objectLayerName == "flames") {
				// tạo ra flames
				CCLOG("Object layer flames");
				loadFlamesVFXToCache();
				CCLOG("Flames X: %f Flames Y: %f", x, y);
				auto sprite = Sprite::createWithSpriteFrameName("flames_0.png");
				sprite->runAction(RepeatForever::create(flamesAnimate));
				sprite->setPosition(Vec2(x, y));
				listMapDecoration.pushBack(sprite);
				_tileMap->addChild(sprite, 12);
			}
			else if(objectLayerName == "torch") {
				CCLOG("OBJECT LAYER TORCH");
				loadTorchFlameToCache();
				auto sprite = Sprite::createWithSpriteFrameName("flame_glow_0.png");
				sprite->runAction(RepeatForever::create(torchFlamesAnimate));
				sprite->setPosition(Vec2(x, y));
				listMapDecoration.pushBack(sprite);
				_tileMap->addChild(sprite, 12);

			}
			else if (objectLayerName == "subservients working") {
				CCLOG("Object layer subservients working");
				loadSubservientWorkingToCache();
				CCLOG("Sub Woring X: %f Sub Working Y: %f", x, y);
				std::string name = objectProperties["name"].asString();
				auto sprite = Sprite::create();
				if (name.find("subservient_special_working_E") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_E_));
				}
				if (name.find("subservient_special_working_N") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_N_));
				}
				if (name.find("subservient_special_working_NE") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_NE_));
				}
				if (name.find("subservient_special_working_NEE") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_NEE_));
				}
				if (name.find("subservient_special_working_NNE") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_NNE_));
				}
				if (name.find("subservient_special_working_NW") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_NW_));
				}
				if (name.find("subservient_special_working_NWW") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_NWW_));
				}
				if (name.find("subservient_special_working_S") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_S_));
				}
				if (name.find("subservient_special_working_SE") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_SE_));
				}
				if (name.find("subservient_special_working_SEE") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_SEE_));
				}
				if (name.find("subservient_special_working_SSE") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_SSE_));
				}
				if (name.find("subservient_special_working_SSW") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_SSW_));
				}
				if (name.find("subservient_special_working_SW") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_SW_));
				}
				if (name.find("subservient_special_working_SWW") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_SWW_));
				}
				if (name.find("subservient_special_working_W") != std::string::npos) {
					sprite->runAction(RepeatForever::create(subservientsWorking_W_));
				}
				sprite->setPosition(Vec2(x, y));
				listMapDecoration.pushBack(sprite);
				_tileMap->addChild(sprite, 12);
			}
			else if (objectLayerName == "Obelisk") {
				CCLOG("Object layer Obelisk");
				auto obelisk = Obelisk::createObelisk();
				obelisk->setPosition(Vec2(x, y));
				listObelisk.pushBack(obelisk);
					_tileMap->addChild(obelisk, 13);

			}
		}
		return true;
	}
	return false;
}
void MapDecoration::loadFlamesVFXToCache()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/vfx/flames/flames.plist","map/vfx/flames/flames.png");
	flamesAnimate = Animate::create(Engine::getInstance()->createAnimation1("flames_",7,0.2));
	flamesAnimate->retain();
}

void MapDecoration::loadSubservientWorkingToCache()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_E.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_E.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_N.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_N.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_NE.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_NE.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_NEE.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_NEE.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_NNE.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_NNE.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_NNW.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_NNW.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_NW.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_NW.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_NWW.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_NWW.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_S.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_S.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_SE.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_SE.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_SEE.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_SEE.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_SSE.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_SSE.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_SSW.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_SSW.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_SW.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_SW.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_SWW.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_SWW.png");
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/none-playable character/subservient/subservient_special_working/subservient_special_working_W.plist", "map/none-playable character/subservient/subservient_special_working/subservient_special_working_W.png");

	subservientsWorking_E_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_E_0.0_",7,0.15));
		subservientsWorking_N_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_N_90.0_", 7, 0.15));
	subservientsWorking_NE_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_NE_45.0_", 7, 0.15));
	subservientsWorking_NEE_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_NEE_22.5_", 7, 0.15));
	 subservientsWorking_NNE_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_NNE_67.5_", 7, 0.155));
	 subservientsWorking_NNW_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_NNW_112.5_", 7, 0.15));
	 subservientsWorking_NW_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_NW_135.0_", 7, 0.15));
	 subservientsWorking_NWW_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_NWW_157.5_", 7, 0.15));
	 subservientsWorking_S_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_S_270.0_", 7, 0.15));
	 subservientsWorking_SE_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_SE_315.0_", 7, 0.15));
	 subservientsWorking_SEE_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_SEE_337.5_", 7, 0.15));
	 subservientsWorking_SSE_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_SSE_292.5_", 7, 0.15));
	 subservientsWorking_SSW_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_SSW_247.5_", 7, 0.15));
	 subservientsWorking_SW_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_SW_225.0_", 7, 0.15));
	 subservientsWorking_SWW_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_SWW_202.5_", 7, 0.15));
	 subservientsWorking_W_ = Animate::create(Engine::getInstance()->createAnimation1("subservient_special_working_W_180.0_", 7, 0.15));

	 subservientsWorking_E_->retain();
	 subservientsWorking_N_->retain();
		 subservientsWorking_NE_->retain();
		 subservientsWorking_NEE_->retain();
		 subservientsWorking_NNE_->retain();
		 subservientsWorking_NNW_->retain();
		 subservientsWorking_NW_->retain();
		 subservientsWorking_NWW_->retain();
		 subservientsWorking_S_->retain();
		 subservientsWorking_SE_->retain();
		 subservientsWorking_SEE_->retain();
		 subservientsWorking_SSE_->retain();
		 subservientsWorking_SSW_->retain();
		 subservientsWorking_SW_->retain();
		 subservientsWorking_SWW_->retain();
		 subservientsWorking_W_->retain();
}
void MapDecoration::loadTorchFlameToCache()
{
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("map/vfx/flame/torchFlame.plist","map/vfx/flame/torchFlame.png");
	torchFlamesAnimate = Animate::create(Engine::getInstance()->createAnimation1("flame_glow_", 7, 0.2));
	torchFlamesAnimate->retain();
}
MapDecoration::~MapDecoration() {

}
