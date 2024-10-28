//
// Created by jacki on 12/5/2023.
//

#ifndef FIGHTSIM_PLAYERROUGHT_H
#define FIGHTSIM_PLAYERROUGHT_H
#include "fButton.h"
#include "Character.h"
#include "Guy.h"
#include <vector>
#include "Position.h"
#include "HealthBar.h"

class PlayerRought : public sf::Drawable
{
private:
    std::vector<fButton> buttons;
    int classChoice;
    Guy g;
    HealthBar hpBar;
public:
    void run(Character& c);
    void fillButtons(Character& c);
    void placeButtons();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //FIGHTSIM_PLAYERROUGHT_H
