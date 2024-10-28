//
// Created by jacki on 11/16/2023.
//

#ifndef DIGITALANALOGCLOCK_STATEENUM_H
#define DIGITALANALOGCLOCK_STATEENUM_H
enum StateEnum
{///don't put opposite values, like Hidden and Shown, only put HIDDEN
    HIDDEN, FOCUSED, HOVERED, CLICKED, CLICKABLE, SELECTED,

    ///do not add state below this line
    LAST_STATE ///will never be used, but will keep track of the amount of states in the enum
};
#endif //DIGITALANALOGCLOCK_STATEENUM_H
