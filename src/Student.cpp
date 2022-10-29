//
// Created by ntsayz on 10/20/22.
//

#include "Student.h"

#include <utility>

Student::Student() = default;

Student::Student(int code, std::string name){
    this->code = code;
    this->name = std::move(name);
}
Student::Student(int code, std::string name, const Uc& curricularUnit, const Class& aClass) {
    this->code = code;
    this->name = std::move(name);
    std::map<Uc,Class> map1;
    map1[curricularUnit] = aClass;
    this->classes1.push_back(map1);
}

std::map<Class,Uc> Student::getEnrolledClasses() const {
    return this->classes;
}

int Student::getCode() const {
    return this->code;
}

std::string Student::getName() const {
    return this->name;
}

void Student::showEnrolledClasses() const {
    std::cout << getName() <<  " is enrolled in\n ";
    /*for(auto const& [uc,aclass]: classes1){
        std::cout <<  uc.get_uc_Code() << ", "<< aclass.getClassCode();
        std::cout << "\n";
    }*/
    for(auto const& it : this->classes1){
        for(auto const& [uc,aclass]: it){
            std::cout <<  uc.get_uc_Code() << ", "<< aclass.getClassCode();
            std::cout << "\n";
        }
    }
}

void Student::addClassUC(Uc& curricularUnit,Class& aClass) {
    std::map<Uc,Class> map1;
    map1[curricularUnit] = aClass;
    this->classes1.push_back(map1);
}

int Student::getNumberEnrolledClasses() const {
    return this->classes.size();
}

/*
void Student::addClassUC(Uc curricularUnit,Class aClass) {
    this->classes.emplace(curricularUnit,aClass);
}*/




