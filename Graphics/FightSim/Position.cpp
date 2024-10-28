//
// Created by jacki on 11/14/2023.
//
#ifndef DIGITALANALOGCLOCK_POSITION_CPP
#define DIGITALANALOGCLOCK_POSITION_CPP

#include "Position.h"
template<typename T, typename S>
void Position::left(const S& constObj, T& obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    sf::FloatRect ob = obj.getGlobalBounds();
    float x = cb.left - spacing - ob.width;
    float y = cb.top;
    obj.setPosition({x,y});
}

template<typename T, typename S>
void Position::right(const S &constObj, T &obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    sf::FloatRect ob = obj.getGlobalBounds();
    float x = cb.left + spacing + ob.width;
    float y = cb.top;
    obj.setPosition({x,y});
}

template<typename T, typename S>
void Position::top(const S &constObj, T &obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    sf::FloatRect ob = obj.getGlobalBounds();
    float x = cb.left;
    float y = cb.top - spacing - ob.height;
    obj.setPosition({x,y});
}

template<typename T, typename S>
void Position::bottom(const S &constObj, T &obj, float spacing)
{
    sf::FloatRect cb = constObj.getGlobalBounds();
    sf::FloatRect ob = obj.getGlobalBounds();
    float x = cb.left;
    float y = cb.top + spacing + ob.height;
    obj.setPosition({x,y});
}

template<typename T, typename S>
void Position::center(const S &constObj, T &obj)
{
    sf::Vector2f cbCenter = {constObj.left + constObj.width/2, constObj.top + constObj.height/2};
    sf::Vector2f obCenter = {obj.left + obj.width/2, obj.top + obj.height/2};
    obj.setOrigin({obCenter});
    obj.setPosition({cbCenter});
}

template<typename T>
void Position::centerText(const T &obj, sf::Text &text)
{
    sf::FloatRect textRect = text.getGlobalBounds();
    sf::FloatRect tRect = obj.getGlobalBounds();
    sf::Vector2f center = {textRect.width/2.0f, textRect.height/2.f};
    sf::Vector2f localBounds = {center.x + text.getLocalBounds().left, center.y + text.getLocalBounds().top};
    sf::Vector2f rounded = {std::round(localBounds.x), std::round(localBounds.y)};
    text.setOrigin(rounded);
    text.setPosition({tRect.left + tRect.width/2, tRect.top + tRect.height/2});

}

#endif //DIGITALANALOGCLOCK_POSITION_CPP