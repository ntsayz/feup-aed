//
// Created by ntsayz on 10/20/22.
//

#include "Slot.h"

#include <utility>



void Slot::loadClassesData() {

}

std::string Slot::getWeekday() {
    return this->weekdaystr;
}

Slot::Slot(std::string weekdaystr, float startHour, float duration, std::string type) {
    this->weekdaystr = std::move(weekdaystr);
    this->startHour = startHour;
    this->duration = duration;
    this->type = std::move(type);
    this->weekday = getNum();
    this->endHour = this->startHour + this->duration;
}

unsigned short Slot::getNum() {
    std::string lst[] = {"Monday","Tuesday","Wednesday","Thursday","Friday"};
    int i = 1;
    for(auto it : lst){
        if(it == this->weekdaystr) return i;
        i++;
    }
    return -1;
}





