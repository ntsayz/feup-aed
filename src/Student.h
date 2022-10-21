//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_STUDENT_H
#define FEUP_AED_STUDENT_H
#include "Request.h"
#include "Uc.h"
#include "Class.h"
#include "Utility.h"
#include "Slot.h"
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
    Student(std::string code, std::string name, const Uc& curricularUnit,const Class& aClass);

    void addClassUC(Uc curricularUnit,Class aClass);

    //change to int TODO
    std::string getCode() const;
    std::map<Uc,Class> getEnrolledClasses() const;
    std::string getName() const;
    bool operator<(Student student) const{
        return getCode() < student.getCode();
    }
    bool operator>(Student student) const{
        return getCode() > student.getCode();
    }

};


#endif //FEUP_AED_STUDENT_H
