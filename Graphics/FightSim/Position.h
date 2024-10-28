//
// Created by jacki on 11/14/2023.
//

#ifndef DIGITALANALOGCLOCK_POSITION_H
#define DIGITALANALOGCLOCK_POSITION_H

#include <SFML/Graphics.hpp>
#include <cmath>

class Position
{
public:
    template<typename T, typename S>
    static void left(const S& constObj, T& obj, float spacing = 0); //will position obj to the left of constObj
    template<typename T, typename S>
    static void right(const S& constObj, T& obj, float spacing = 0);
    template<typename T, typename S>
    static void top(const S& constObj, T& obj, float spacing = 0);
    template<typename T, typename S>
    static void bottom(const S& constObj, T& obj, float spacing = 0);
    template<typename T, typename S>
    static void center(const S& constObj, T& obj);
    template<typename T>
    static void centerText(const T &obj, sf::Text &text);
};

#include "Position.cpp"
#endif //DIGITALANALOGCLOCK_POSITION_H
