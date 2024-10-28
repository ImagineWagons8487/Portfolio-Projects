//
// Created by jacki on 11/30/2023.
//

#ifndef FIGHTSIM_CHARACTER_H
#define FIGHTSIM_CHARACTER_H
#include "ClassesEnum.h"
#include "SFML/Graphics.hpp"
class Character
{
public:
    int currentHealth, maxHealth, atkVal, grdVal, actionCount, guardStacks;
    virtual int attack()=0;
    virtual void guard()=0;
    virtual int getActionCount()=0;
    virtual void hurt(int dmg, bool pierce)=0;
};


#endif //FIGHTSIM_CHARACTER_H
