//
// Created by jacki on 11/16/2023.
//
#ifndef DIGITALANALOGCLOCK_MOUSEEVENTS_CPP
#define DIGITALANALOGCLOCK_MOUSEEVENTS_CPP
#include "MouseEvents.h"

namespace MouseEvents
{
    template<typename T>
    bool isHovered(const T &obj, sf::RenderWindow& window)
    {
        sf::Vector2f mpos = (sf::Vector2f) sf::Mouse::getPosition(window); ///(sf::Vector2f) is the original way of casting
        return obj.getGlobalBounds().contains(mpos);
    }
    template<typename T>
    bool isClicked(const T& obj, sf::RenderWindow& window)
    {
        return isHovered(obj, window) &&
        sf::Mouse::isButtonPressed(sf::Mouse::Left);
    }
} // MouseEvents

#endif
