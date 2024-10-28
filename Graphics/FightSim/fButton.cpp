//
// Created by jacki on 12/4/2023.
//

#include "fButton.h"

fButton::fButton()
: fButton({40, 40})
{

}

fButton::fButton(sf::Vector2f size)
: defaultColor(sf::Color::White), clickColor(sf::Color(120, 120, 120)), lockedColor(sf::Color(185, 185, 185))
{
    rect.setOutlineColor(sf::Color::Black);
    rect.setSize(size);
    rect.setFillColor(defaultColor);
    enableState(CLICKABLE);
    disableState(SELECTED);
}

void fButton::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(rect);
}

void fButton::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    if(MouseEvents::isClicked(rect, window))
    {
        enableState(CLICKED);
    }
    else
        disableState(CLICKED);

    if(MouseEvents::isHovered(rect, window))
    {
        enableState(HOVERED);
    }
    else
        disableState(HOVERED);
}

void fButton::update()
{
    rect.setTexture(&texture);
    if(getState(CLICKED))
        rect.setFillColor(clickColor);
    else if(!getState(CLICKABLE) || getState(SELECTED))
        rect.setFillColor(lockedColor);
    else
        rect.setFillColor(defaultColor);
    if(getState(HOVERED))
    {}
//    if(getState(SELECTED))
//        rect.setFillColor(lockedColor);
//    else
//        rect.setFillColor(defaultColor);
}

void fButton::setSize(sf::Vector2f size)
{
    rect.setSize(size);
}

void fButton::setTexture(sf::Texture& texture)
{
    this->texture = texture;
}

void fButton::setPosition(sf::Vector2f pos)
{
    rect.setPosition(pos);
}

sf::FloatRect fButton::getGlobalBounds() const
{
    return rect.getGlobalBounds();
}

void fButton::setFillColor(sf::Color color)
{
    rect.setFillColor(color);
}
