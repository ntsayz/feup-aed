//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_STUDENT_H
#define FEUP_AED_STUDENT_H
#include "Request.h"
#include "Uc.h"
#include "Class.h"
#include "Utility.h"
#include <string>
#include <queue>
#include <iostream>
#include <vector>
#include <list>
#include <map>


class Student {
private:
    //change to int TODO
    std::string code;
    std::string name;
    std::queue<Request> requests;
    std::map<Uc,Class> classes;
    std::set<Slot> schedule;

public:
    Student();
    ///Enroll student
    Student(std::string code, std::string name);

    void addClass(Class aClass);
    //change to int TODO
    std::string getCode() const;
    std::map<Uc,Class> getEnrolledClasses() const;
    bool operator<(Student student) const{
        return getCode() < student.getCode();
    }

};


#endif //FEUP_AED_STUDENT_H
