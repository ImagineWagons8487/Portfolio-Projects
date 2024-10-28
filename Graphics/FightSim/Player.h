//
// Created by jacki on 12/5/2023.
//

#ifndef FIGHTSIM_PLAYER_H
#define FIGHTSIM_PLAYER_H
#include "fButton.h"
#include "Guy.h"
#include <vector>
#include "Position.h"
#include "HealthBar.h"
class Player : public sf::Drawable
{
private:
    std::vector<fButton> buttons;
    fButton readyButton;
//    int classChoice;
    int actionChoice;
    sf::Texture texture;
    Guy g;
    std::vector<Character> chars;
    HealthBar hpBar;
    bool ready;
    void buttonFunctions(int index);
public:
    Player();
    Player(Character& c);
    Player(sf::Vector2f pos, bool reverse);
    Player(Character& c, sf::Vector2f pos, bool reverse);
    void run(Character& c, sf::Vector2f pos, bool reverse);
    void loadChar();
    void initButtons(Character& c, sf::Vector2f pos);
    void placeButtons(sf::Vector2f pos, bool reverse);
    void textureButtons();
    void placeChar(bool reverse);
    void functionButtons();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
    Guy& getCharacter();
    HealthBar& getHPBar();
    void placeHPBar(bool reverse);
    bool checkReady();
    void unReady();
    int getActionChoice();
    void reduceHealth(float dmg, bool pierce);
    void charBrace();
    void disableBraced();
    int attack();
    void guard();
    void zeroGuardStacks();
    int stab();
};


#endif //FIGHTSIM_PLAYER_H
