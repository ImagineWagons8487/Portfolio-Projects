//
// Created by jacki on 12/5/2023.
//

#include "PlayerRought.h"

void PlayerRought::run(Character &c)
{
    fillButtons(c);
    placeButtons();
}

void PlayerRought::fillButtons(Character &c)
{
    for(int i=0; i<c.getActionCount(); i++)
    {
        buttons.push_back(fButton());
    }
}

void PlayerRought::placeButtons()
{
    buttons[0].setPosition({686, 250});
    int i = 1;
    while(i < buttons.size())
    {
        if(i%6 == 0 && i<buttons.size())
        {
            Position::bottom(buttons[i-7], buttons[i++], 5);
        }
        for(int j=0; j<5 ;j++)
        {
            if(i < buttons.size())
            {
                Position::left(buttons[i-1], buttons[i], 5);
                i++;
            }
        }
    }
}

void PlayerRought::draw(sf::RenderTarget &window, sf::RenderStates state) const
{
    for(int i=0; i<buttons.size(); i++)
    {
        window.draw(buttons[i]);
    }

}

void PlayerRought::eventHandler(sf::RenderWindow &window, sf::Event event)
{
    for(int i=0; i<buttons.size(); i++)
    {
        buttons[i].eventHandler(window, event);
    }
}

void PlayerRought::update()
{
    for(int i=0; i<buttons.size(); i++)
    {
        buttons[i].update();
    }
}
