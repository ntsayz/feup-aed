//
// Created by ntsayz on 10/20/22.
//

#include "Student.h"

Student::Student() {

}

Student::Student(std::string code, std::string name){
    this->code = code;
    this->name = name;
}

std::map<Uc,Class> Student::getEnrolledClasses() const {
    return this->classes;
}

std::string Student::getCode() const {
    return this->code;
}

void Student::addClass(Class aClass) {

}


