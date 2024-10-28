//
// Created by jacki on 12/5/2023.
//

#ifndef FIGHTSIM_GAME_H
#define FIGHTSIM_GAME_H
#include "Player.h"

class Game : public sf::Drawable
{
private:
    std::vector<Player*> players;
    int turnNum;
    sf::Text turnCount;
    sf::Font font;
public:
    Game();
    void run();
    void loadPlayer(Player& p);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    void actionsHappen();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates state) const;
};


#endif //FIGHTSIM_GAME_H
