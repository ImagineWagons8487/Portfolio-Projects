//
// Created by jacki on 11/16/2023.
//

#ifndef DIGITALANALOGCLOCK_MOUSEEVENTS_H
#define DIGITALANALOGCLOCK_MOUSEEVENTS_H
#include <SFML/Graphics.hpp>
namespace MouseEvents
{
    template <typename T>
    bool isHovered(const T& obj, sf::RenderWindow& window);
    template <typename T>
    bool isClicked(const T& obj, sf::RenderWindow& window);
} // MouseEvents
#include "MouseEvents.cpp"
#endif //DIGITALANALOGCLOCK_MOUSEEVENTS_H
