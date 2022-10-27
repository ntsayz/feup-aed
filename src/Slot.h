//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_SLOT_H
#define FEUP_AED_SLOT_H
#include <string>

class Slot {
private:
    unsigned short dia;
    float startHour, endHour;
    std::string type;
    /// Constructor
    Slot();

};


#endif //FEUP_AED_SLOT_H
