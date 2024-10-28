//
// Created by jacki on 12/5/2023.
//

#include "Player.h"

Player::Player()
: Player(g)
{

}

Player::Player(Character &c)
: Player(c, {10,350}, false)
{

}

Player::Player(sf::Vector2f pos, bool reverse)
: Player(g, pos, reverse)
{

}

Player::Player(Character &c, sf::Vector2f pos, bool reverse)
{
    run(c, pos, reverse);
}

void Player::run(Character& c, sf::Vector2f pos, bool reverse)
{
    ready=false;
    loadChar();
    initButtons(c, pos);
    placeButtons(pos, reverse);
    textureButtons();
    placeChar(reverse);
    placeHPBar(reverse);
}

void Player::initButtons(Character &c, sf::Vector2f pos)
{
    for(int i=0; i<c.getActionCount(); i++)
    {
        buttons.push_back(fButton());
    }
    readyButton = fButton({100, 40});
}

void Player::loadChar()
{

}

void Player::placeButtons(sf::Vector2f pos, bool reverse)
{
    //{10, 250}
    buttons[0].setPosition(pos);
    int i = 1;
    while(i < buttons.size())
    {
        if(i%6 == 0 && i<buttons.size())
        {
            Position::bottom(buttons[i-7], buttons[i++], 5);
        }
        for(int j=0; j<5 ;j++)
        {
            if(i < buttons.size() && reverse)
            {
                Position::left(buttons[i-1], buttons[i], 5);
                i++;
            }
            else if(i < buttons.size())
            {
                Position::right(buttons[i-1], buttons[i], 5);
                i++;
            }
        }
    }
    if(reverse)
        Position::left(buttons[buttons.size()-1], readyButton, 5);
    else
        Position::right(buttons[buttons.size()-1], readyButton, -55);
}

void Player::textureButtons()
{
    for(int i=0; i<buttons.size(); i++)
    {
        switch(i)
        {
            case BASICATTACK:
                texture.loadFromFile("images/BA.png");
                buttons[BASICATTACK].setTexture(texture);
                break;
            case GUARD:
                texture.loadFromFile("images/GU.png");
                buttons[GUARD].setTexture(texture);
                break;
            case BRACE:
                texture.loadFromFile("images/BR.png");
                buttons[BRACE].setTexture(texture);
                break;
            case STAB:
                texture.loadFromFile("images/ST.png");
                buttons[STAB].setTexture(texture);
                break;
        }
    }
    texture.loadFromFile("images/R.png");
    readyButton.setTexture(texture);
}

void Player::placeChar(bool reverse)
{
    if(reverse)
        g.setPos({530, 70});
}

void Player::buttonFunctions(int index)
{
    switch(index)
    {
        case BASICATTACK:
            g.attack();
            break;
        case GUARD:
            g.guard();
            break;
        case BRACE:
            g.brace();
            break;
        case STAB:
            g.stab();
            break;
    }
}

void Player::functionButtons()
{
    for(int i=0; i<LASTACTION; i++)
    {

    }
    if(buttons[BASICATTACK].getState(CLICKED))
        g.attack();
    if(buttons[GUARD].getState(CLICKED))
        g.guard();
    if(buttons[BRACE].getState(CLICKED))
        g.brace();
    if(buttons[STAB].getState(CLICKED))
        g.stab();
}

void Player::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    for(int i=0; i<buttons.size(); i++)
    {
        window.draw(buttons[i]);
    }
    window.draw(hpBar);
    window.draw(g);
    window.draw(readyButton);
}

void Player::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(int i=0; i<buttons.size(); i++)
    {
        buttons[i].eventHandler(window, event);
    }
    readyButton.eventHandler(window, event);
}

void Player::update()
{
    if(readyButton.getState(CLICKED))
        ready = true;
    for(int i=0; i<buttons.size(); i++)
    {
        buttons[i].update();
        if(buttons[i].getState(CLICKED) && !ready)
        {
            actionChoice = i;
            for(int j=0; j<buttons.size(); j++)
                buttons[j].disableState(SELECTED);
            buttons[actionChoice].enableState(SELECTED);
        }
    }
    if(ready)
    {
        for(int i=0; i<buttons.size(); i++)
        {
            buttons[i].disableState(CLICKABLE);
        }
    }
    else
        for(int i=0; i<buttons.size(); i++)
        {
            buttons[i].enableState(CLICKABLE);
        }
    hpBar.setCurrentHealth(static_cast<float>(getCharacter().currentHealth));
    hpBar.update();
    readyButton.update();
}

Guy& Player::getCharacter()
{
    return g;
}

HealthBar& Player::getHPBar()
{
    return hpBar;
}

void Player::placeHPBar(bool reverse)
{
    if(reverse)
    {
        hpBar.setBarOrigin({hpBar.getBarSize().width, 0});
        hpBar.setBarPosition({735, 0});
        hpBar.setTextPos({683,30});
    }
    hpBar.setHealth(static_cast<float>(g.maxHealth));
}

bool Player::checkReady()
{
    return ready;
}

void Player::unReady()
{
    ready = false;
}

int Player::getActionChoice()
{
    return actionChoice;
}

void Player::reduceHealth(float dmg, bool pierce)
{
    if(!pierce)
    {
        dmg -= g.guardStacks;
        if(dmg < 0)
            dmg = 0;
    }
    g.currentHealth -= dmg;
}

void Player::charBrace()
{
    g.brace();
}

void Player::disableBraced()
{
    g.disableBraced();
}

int Player::attack()
{
    int dmg = g.atkVal;
    if(g.checkBraced())
        dmg*=4;
    disableBraced();
    return dmg;
}

void Player::guard()
{
    g.setGuardStacks(g.grdVal);
}

void Player::zeroGuardStacks()
{
    g.setGuardStacks(0);
}

int Player::stab()
{
    int dmg = g.atkVal/2;
    if(g.checkBraced())
        dmg*=4;
    disableBraced();
    return dmg;
}
