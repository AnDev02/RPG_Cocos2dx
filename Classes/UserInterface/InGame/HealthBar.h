
#ifndef __HEALTH_BAR__
#define __HEALTH_BAR__

#include "cocos2d.h"
USING_NS_CC;


class HealthBar : public Node {
public:
    static HealthBar* create(const std::string& borderImage, const std::string& insideImage, float hp, float mp) {
        HealthBar* healthBar = new HealthBar();
        if (healthBar && healthBar->initWithImages(borderImage, insideImage, hp, mp)) {
            healthBar->autorelease();
            return healthBar;
        }
        CC_SAFE_DELETE(healthBar);
        return nullptr;
    }

    bool initWithImages(const std::string& borderImage, const std::string& insideImage, float hp, float mp) {
        if (!Node::init()) {
            return false;
        }
        currentHealth = hp;
        maxHealth = hp;
        currentMana = mp;
        maxMana = mp;
        
        auto bottomNavigation = Sprite::create("res/ab2_bonus_frame.png");
        this->addChild(bottomNavigation, 1);
        bottomInventory = Sprite::create("res/ab2_main_frame.png");
        bottomInventory->setPosition(Vec2(0, -bottomNavigation->getContentSize().height + (bottomNavigation->getContentSize().height / 8)));
        bottomInventory->setScale(1.3);
        this->addChild(bottomInventory, 1);

        updateHealthBar();
        return true;
    }

    void increaseHealth(float amount) {
        if (currentHealth <= currentHealth + amount)
            currentHealth = currentHealth + amount;
        else
            currentHealth = maxHealth;
        //maxHealthLabel->setString(std::to_string(static_cast<int>(m_currentHealth)) + " / " + std::to_string(static_cast<int>(m_maxHealth)));
        updateHealthBar();
    }

    void decreaseHealth(float amount) {
        if (currentHealth - amount >= 0)
            currentHealth = currentHealth - amount;
        else
            currentHealth = 0;
        //maxHealthLabel->setString(std::to_string(static_cast<int>(m_currentHealth)) + " / " + std::to_string(static_cast<int>(m_maxHealth)));
        updateHealthBar();
    }

    void increaseMana(float amount) {
        if (currentMana <= currentMana + amount)
            currentMana = currentMana + amount;
        else
            currentMana = maxMana;
        //maxHealthLabel->setString(std::to_string(static_cast<int>(m_currentHealth)) + " / " + std::to_string(static_cast<int>(m_maxHealth)));
        updateHealthBar();
    }

    void decreaseMana(float amount) {
        if (currentMana - amount >= 0)
            currentMana = currentMana - amount;
        else
            currentMana = 0;
        //maxHealthLabel->setString(std::to_string(static_cast<int>(m_currentHealth)) + " / " + std::to_string(static_cast<int>(m_maxHealth)));
        updateHealthBar();
    }
    void increaseMaxHealth(float amount) {
        /*m_maxHealth += amount;
        m_currentHealth += amount; 
        maxHealthLabel->setString(std::to_string(static_cast<int>(m_currentHealth)) + " / " + std::to_string(static_cast<int>(m_maxHealth)));
        updateHealthBar();*/
    }
    float getHeight() const { return progressBarBorder->getContentSize().height + bottomInventory->getContentSize().height; };
private:
    Sprite* progressBarBorder;
    Sprite* healthBar;
    Sprite* energyBar;
    Sprite* bottomInventory;
    float healthProgress;
    float energyProgress;
    Label* maxHealthLabel;
    float currentHealth;
    float maxHealth;
    float currentMana;
    float maxMana;

    void updateHealthBar() {
        if (this->getChildByTag(101)) {
            this->removeChildByTag(101);
        }
        if (this->getChildByTag(102)) {
            this->removeChildByTag(102);
        }
        if (this->getChildByTag(103)) {
            this->removeChildByTag(103);
        }
        healthProgress = currentHealth / maxHealth;
        energyProgress = currentMana / maxMana;

        progressBarBorder = Sprite::create("res/ab2_bonus_frame_globe_borders.png");
        progressBarBorder->setPosition(Vec2(0, 0));
        progressBarBorder->setTag(101);
        this->addChild(progressBarBorder, 10);

        healthBar = Sprite::create("res/ab2_bonus_frame_globe_fill_red.png");
        healthBar->setPosition(Vec2(-33, 0));
        healthBar->setTag(102);
        this->addChild(healthBar, 5);

        energyBar = Sprite::create("res/ab2_bonus_frame_globe_fill_blue.png");
        energyBar->setPosition(Vec2(healthBar->getContentSize().width - 33, 0));
        energyBar->setTag(103);
        this->addChild(energyBar, 5);


        auto healthBarSize = healthBar->getContentSize();
        auto energyBarSize = energyBar->getContentSize();
        auto healthBarHeight = healthBar->getContentSize().height;
        auto energyBarHeight = energyBar->getContentSize().height;
        float healthOffsetY = (healthBarHeight - (healthBarHeight * healthProgress)) / 2;
        float energyOffsetY = (energyBarHeight - (energyBarHeight * energyProgress)) / 2;
        healthBar->setPosition(healthBar->getPositionX(), healthBar->getPositionY() - healthOffsetY);
        energyBar->setPosition(energyBar->getPositionX(), energyBar->getPositionY() - energyOffsetY);
        healthBar->setTextureRect(Rect(0, healthBarSize.height * (1 - healthProgress), healthBarSize.width, healthBarSize.height * healthProgress));
        energyBar->setTextureRect(Rect(0, energyBarSize.height * (1 - energyProgress), energyBarSize.width, energyBarSize.height * energyProgress));
    }
};

#endif // __HEALTH_BAR__