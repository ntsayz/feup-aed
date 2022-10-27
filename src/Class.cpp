//
// Created by ntsayz on 10/20/22.
//


#include "Class.h"
#include "Student.h"


Class::Class(std::string classCode) {
    this->class_Code = classCode;
}

std::string Class::getClassCode() const {
    return this->class_Code;
}


void Class::addStudent(const Student& student){
    this->students.insert(student);
    //std::cout << student.getName() << " is in " << this->getClassNr() << "\n";
}

int Class::getClassNr() const {
    int i;
    std::stringstream ss;
    ss << getClassCode().substr(5,6);
    ss >> i;
    return i;
}

void Class::showStudents() const {
    std::cout << getClassCode();
    for(const Student& elem: this->students){
        std::cout << elem.getName() << "\n";
    }
    std::cout << this->students.size() << " students";
}

int Class::getClassSize() const {
    return this->students.size();
}

