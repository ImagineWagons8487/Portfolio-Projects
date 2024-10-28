//
// Created by jacki on 12/5/2023.
//

#include "HealthBar.h"

HealthBar::HealthBar()
: HealthBar(55)
{

}

HealthBar::HealthBar(float maxHP)
: maxHP(maxHP)
{
    currentHP = maxHP;
    text.setString(std::to_string(static_cast<int>(currentHP)) + "/" + std::to_string(static_cast<int>(this->maxHP)));
    setUpText();
    setUpBar();
    hFrontMaxWidth = hFront.getSize().x;
}

void HealthBar::setUpText()
{
    font.loadFromFile("OpenSans-Bold.ttf");
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Black);
    text.setPosition(hBack.getPosition().x, hBack.getPosition().y+30);
    text.setFont(font);
}

void HealthBar::setUpBar()
{
    hBack.setSize({280, 30});
    hFront.setSize({280, 30});
    hBack.setFillColor(sf::Color::Red);
    hFront.setFillColor(sf::Color::Yellow);
}

void HealthBar::setHealth(float maxHp)
{
    maxHP = maxHp;
    currentHP = maxHP;
}

void HealthBar::setTextPos(sf::Vector2f pos)
{
    text.setPosition(pos);
}

void HealthBar::setBarOrigin(sf::Vector2f ori)
{
    hBack.setOrigin(ori);
    hFront.setOrigin(ori);
}

void HealthBar::setBarPosition(sf::Vector2f pos)
{
    hBack.setPosition(pos);
    hFront.setPosition(pos);
}

sf::FloatRect HealthBar::getBarSize()
{
    return hBack.getGlobalBounds();
}

void HealthBar::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(hBack);
    window.draw(hFront);
    window.draw(text);
}

void HealthBar::hurt(int dmg)
{
    currentHP -= dmg;
    if(currentHP < 0)
        currentHP=0;
}

void HealthBar::update()
{
    float ratio = currentHP/maxHP;
    hFront.setSize({hFrontMaxWidth * ratio, hFront.getSize().y});
    text.setString(std::to_string(static_cast<int>(currentHP)) + "/" + std::to_string(static_cast<int>(maxHP)));
}

void HealthBar::setCurrentHealth(float hp)
{
    currentHP = std::floor(hp);
    if(currentHP < 0)
        currentHP=0;
}
