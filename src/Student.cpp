//
// Created by ntsayz on 10/20/22.
//

#include "Student.h"

#include <utility>

Student::Student() = default;

Student::Student(int code, std::string name){
    this->code = std::move(code);
    this->name = std::move(name);
}
Student::Student(int code, std::string name, const Uc& curricularUnit, const Class& aClass) {
    this->code = code;
    this->name = std::move(name);
    this->classes.insert(std::pair(curricularUnit,aClass));
}

std::map<Uc,Class> Student::getEnrolledClasses() const {
    return this->classes;
}

int Student::getCode() const {
    return this->code;
}

std::string Student::getName() const {
    return this->name;
}

void Student::showEnrolledClasses() const {
    std::cout << getName() <<  " is enrolled in - ";
    for(auto it = classes.begin(); it != classes.end(); it++){
        std::cout << it->second.getClassNr() << ",";
    }
}

void Student::addClassUC(Uc curricularUnit, Class aClass) {

}

/*
void Student::addClassUC(Uc curricularUnit,Class aClass) {
    this->classes.emplace(curricularUnit,aClass);
}*/




