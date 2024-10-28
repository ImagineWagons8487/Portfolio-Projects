//
// Created by jacki on 12/4/2023.
//

#ifndef FIGHTSIM_FBUTTON_H
#define FIGHTSIM_FBUTTON_H
#include "SFML/Graphics.hpp"
#include "MouseEvents.h"
#include "States.h"

class fButton : public sf::Drawable, public States
{
private:
    sf::Color defaultColor, clickColor, lockedColor;
    sf::Texture texture;
    sf::RectangleShape rect;
public:
    fButton();
    fButton(sf::Vector2f size);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void setSize(sf::Vector2f size);
    void setTexture(sf::Texture& texture);
    void setPosition(sf::Vector2f pos);
    sf::FloatRect getGlobalBounds() const;
    void setFillColor(sf::Color color);
};


#endif //FIGHTSIM_FBUTTON_H
