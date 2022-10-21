//
// Created by ntsayz on 10/20/22.
//

#include "Student.h"

#include <utility>

Student::Student() = default;

Student::Student(std::string code, std::string name){
    this->code = std::move(code);
    this->name = std::move(name);
}
Student::Student(std::string code, std::string name, const Uc& curricularUnit, const Class& aClass) {
    this->code = std::move(code);
    this->name = std::move(name);
    //this->classes.emplace(curricularUnit,aClass);
}

std::map<Uc,Class> Student::getEnrolledClasses() const {
    return this->classes;
}

std::string Student::getCode() const {
    return this->code;
}

std::string Student::getName() const {
    return this->name;
}

/*
void Student::addClassUC(Uc curricularUnit,Class aClass) {
    this->classes.emplace(curricularUnit,aClass);
}*/




