//
// Created by ntsayz on 10/20/22.
//


#include "Class.h"
#include "Student.h"

Class::Class() {}
Class::Class(std::string classCode) {
    this->class_Code = classCode.substr(0,7);
}

std::string Class::getClassCode() const {
    return this->class_Code;
}


void Class::addStudent(const Uc& uc ,const Student& student){
    this->UC_students[uc].push_back(student);
}

int Class::getClassNr() const {
    int i;
    std::stringstream ss;
    ss << getClassCode().substr(5,6);
    ss >> i;
    return i;
}

void Class::showStudents() const {
    std::cout << getClassCode() << "";
    for(auto const& [key,val]: UC_students){
        std::cout << key.get_uc_Code() << " - ";
        for(Student student : val){
            std::cout << student.getName() << ", ";
        }
        std::cout << "\n";
    }
    //std::cout << this->students.size() << " students";
}

int Class::getClassSize() const {
    return this->UC_students.size();
}

