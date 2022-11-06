//
// Created by ntsayz on 10/20/22.
//


#include "Class.h"
#include "Student.h"

Class::Class() {}
Class::Class(std::string classCode) {
    this->class_Code = classCode.substr(0,7);
    this->uid = this->getClassYear()*100;
    this->uid += this->getClassNr();
}

std::string Class::getClassCode() const {
    return this->class_Code;
}
int Class::get_uid() const {
    return this->uid;
}


void Class::addStudent(Uc& uc,const Student& student){
    if(UC_students.find(uc) == UC_students.end()){
        std::vector<Student> l;
        l.push_back(student);
        this->UC_students[uc] = l;
    }else{
        this->UC_students[uc].push_back(student);
    }
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
        //std::cout << key.get_uc_Code() << " - ";
        for(Student student : val){
            std::cout << student.getName() << ", ";
        }
        std::cout << "\n";
    }
    std::cout << this->UC_students.size() << " students";
}

int Class::getClassSize() const {
    return this->UC_students.size();
}

int Class::getClassYear() const {
    int i;
    std::stringstream ss;
    ss << getClassCode().substr(0,1);
    ss >> i;
    return i;
}

