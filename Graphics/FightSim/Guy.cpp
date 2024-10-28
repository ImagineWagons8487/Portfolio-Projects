//
// Created by jacki on 11/30/2023.
//

#include "Guy.h"

Guy::Guy()
: Guy({100, 70})
{

}

Guy::Guy(const sf::Vector2f& pos)
{
    texture.loadFromFile("images/GuyResize.png");
    sprite.setTexture(texture);
    sprite.setPosition(pos);
    actionCount = LASTACTION;
    braced=false;
    guardStacks = 0;
    maxHealth = 50;
    currentHealth = maxHealth;
    atkVal = 5;
    grdVal = 10;
}

int Guy::attack()
{
    int dmg = atkVal;
    if(braced)
        dmg *= 2.5;
    braced=false;
    return dmg;
}
void Guy::guard()
{
    setGuardStacks(grdVal);
}

int Guy::stab()
{
    int dmg = atkVal/2;
    if(braced)
        dmg *= 2.5;
    braced=false;
    return dmg;
}

void Guy::brace()
{
    braced=true;
}

void Guy::hurt(int dmg, bool pierce)
{
    if(!pierce)
    {
        dmg -= guardStacks;
        guardStacks -= dmg;
        if(dmg < 0)
            dmg = 0;
    }
    currentHealth -= dmg;
}

void Guy::setGuardStacks(int amt)
{
    guardStacks = amt;
}

void Guy::setSpriteTexture()
{
    sprite.setTexture(texture);
}

void Guy::setPos(sf::Vector2f p)
{
    sprite.setPosition(p);
}

void Guy::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    window.draw(sprite);
}

int Guy::getActionCount()
{
    return actionCount;
}

bool Guy::checkBraced()
{
    return braced;
}

void Guy::disableBraced()
{
    braced = false;
}
