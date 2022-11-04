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
Student::Student(int code, std::string name, Uc& curricularUnit, Class& aClass) {
    this->code = code;
    this->name = std::move(name);
    this->classes12[curricularUnit] = aClass;
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
    std::cout << getName() <<  " is enrolled in\n " << classes1.size() << " classes\n";
    for(auto it: classes1){
        std::cout  << "("<< it.first.get_uc_Code() << ") ==> [";
        for(auto [uc,classList]: it.second){
            for(auto aClass : classList){
                std::cout <<  "["<< uc.get_uc_Code() << ", " << aClass.getClassCode() << "],";
            }
        }
        std::cout << "]\n";
    }
}

void Student::addClassUC(Uc& uc,Class& aClass){
    if(classes1.find(uc) == classes1.end()){
        std::map<Uc, std::vector<Class>> ucClassMap;
        std::vector<Class> classList;
        classList.push_back(aClass);
        ucClassMap[uc] = classList;
        this->classes1[uc] = ucClassMap ;
        //std::cout << "added " << getName() << " to " << aClass.getClassCode() << " in " << uc.get_uc_Code() <<"\n";
    }else{
        this->classes1[uc][uc].push_back(aClass);
        //std::cout << "added " << getName() << " to " << aClass.getClassCode() << " in " << uc.get_uc_Code() <<"\n";
    }
}

int Student::getNumberEnrolledClasses() const {
    return this->classes.size();
}

void Student::setUC(std::string s) {
    this->curr_uc = std::move(s);
}

std::string Student::getUC() {
    return this->curr_uc;
}

/*
void Student::addClassUC(Uc curricularUnit,Class aClass) {
    this->classes.emplace(curricularUnit,aClass);
}*/




