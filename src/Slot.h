//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_SLOT_H
#define FEUP_AED_SLOT_H
#include <string>

class Slot {
private:
    unsigned short weekday;
    float startHour, endHour;
    std::string type;
public:
    /// Constructor
    Slot();
    void load();
};



#endif //FEUP_AED_SLOT_H
