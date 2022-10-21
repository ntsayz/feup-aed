//
// Created by ntsayz on 10/20/22.
//

#include "Class.h"

Class::Class(std::string classCode) {
    this->class_Code = classCode;
}

std::string Class::getClassCode() const {
    return this->class_Code;
}
