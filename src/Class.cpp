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


void Class::addStudent(Student student){
    this->students.insert(student);
}

int Class::getClassNr() const {
    if(getClassCode()[5] == 0){
        return (int)getClassCode()[6];
    }
}

void Class::showStudents() const {
    std::cout << getClassCode();
    for(Student elem: this->students){
        std::cout << elem.getName() << "\n";
    }
    std::cout << this->students.size() << " students";
}

