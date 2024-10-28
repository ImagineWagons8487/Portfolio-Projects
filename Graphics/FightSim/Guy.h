//
// Created by jacki on 11/30/2023.
//

#ifndef FIGHTSIM_GUY_H
#define FIGHTSIM_GUY_H
#include "Character.h"
#include <cmath>
enum actions
{
    BASICATTACK, GUARD, BRACE, STAB,

    LASTACTION
};
class Guy : public Character, public sf::Drawable
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f pos;
    bool braced;
public:
    Guy();
    Guy(const sf::Vector2f& pos);
    virtual int attack();
    virtual void guard();
    int stab();
    void brace();
    virtual void hurt(int dmg, bool pierce);
    void setGuardStacks(int amt);
    void setSpriteTexture();
    void setPos(sf::Vector2f p);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates state) const;
    virtual int getActionCount();
    bool checkBraced();
    void disableBraced();
};


#endif //FIGHTSIM_GUY_H
