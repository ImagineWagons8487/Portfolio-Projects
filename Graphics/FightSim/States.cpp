//
// Created by jacki on 11/16/2023.
//

#include "States.h"

States::States()
{
    for(int i=0; i<LAST_STATE; i++)
    {
        states[static_cast<StateEnum>(i)] = false;
        ///needs to be static cast since i is just an integer when the map is an enum, even though enums are just ints
    }
}

void States::disableState(StateEnum state)
{
    states[state] = false;
}

void States::enableState(StateEnum state)
{
    states[state] = true;
}

void States::toggleState(StateEnum state)
{
    states[state] = !states[state];
}

bool States::getState(StateEnum state) const
{
    return states.at(state);
    ///bracket operator doesn't work because of const
    ///the parameter is marked const because when using this function, you never want to change it
    ///just always make getters constant
}

