//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_CLASS_H
#define FEUP_AED_CLASS_H
#include <string>
#include <list>
#include "Slot.h"

class Class {
private:
    std::string class_Code;
    std::list<Slot> schedule;
public:
    Class(std::string classCode);


    std::string getClassCode() const;

    bool operator<(const Class& aClass) const{
        return getClassCode() < aClass.getClassCode();
    }
};


#endif //FEUP_AED_CLASS_H
