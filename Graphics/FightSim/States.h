//
// Created by jacki on 11/16/2023.
//

#ifndef DIGITALANALOGCLOCK_STATES_H
#define DIGITALANALOGCLOCK_STATES_H
#include <map>
#include "StateEnum.h"
#include <iostream>
///this can be used in future assignments
class States
{
private:
    ///map<key, value>
    std::map<StateEnum, bool> states;
public:
    States();
    void disableState(StateEnum state);
    void enableState(StateEnum state);
    void toggleState(StateEnum state);
    bool getState(StateEnum state) const;///const at the end promises to not change anything
};


#endif //DIGITALANALOGCLOCK_STATES_H
