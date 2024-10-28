#include <iostream>
#include <SFML/Graphics.hpp>
#include "Guy.h"
#include "fButton.h"
#include "Position.h"
#include <vector>
#include <string>
#include "Game.h"

int main()
{
    sf::RenderWindow window({735, 415}, "Fight Simulator");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    Player p1, p2({686, 350}, true);
    Game g;
    g.loadPlayer(p1); g.loadPlayer(p2);
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(sf::Event::Closed == event.type)
                window.close();
            g.eventHandler(window, event);
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
            {

                while(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P));
            }
        }
        g.update();
        window.clear(sf::Color::White);
        window.draw(g);
        window.display();
    }
    return 0;
}

