//
// Created by jacki on 12/5/2023.
//

#ifndef FIGHTSIM_HEALTHBAR_H
#define FIGHTSIM_HEALTHBAR_H
#include "SFML/Graphics.hpp"
#include <string>
#include <cmath>
#include <iostream>
class HealthBar : public sf::Drawable
{
private:
    sf::RectangleShape hBack, hFront;
    float hFrontMaxWidth, currentHP, maxHP;
    sf::Text text;
    sf::Font font;
public:
    HealthBar();
    HealthBar(float maxHP);
    void setUpText();
    void setUpBar();
    void setHealth(float maxHp);
    void setTextPos(sf::Vector2f pos);
    void setBarOrigin(sf::Vector2f ori);
    void setBarPosition(sf::Vector2f pos);
    sf::FloatRect getBarSize();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    void hurt(int dmg);
    void update();
    void setCurrentHealth(float hp);
};


#endif //FIGHTSIM_HEALTHBAR_H
