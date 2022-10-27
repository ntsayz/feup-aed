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
    int code;
    std::string name;
    std::queue<Request> requests;
    std::map<Uc,Class> classes;
    std::set<Slot> schedule;
public:
    Student();
    ///Enroll student to the faculty
    Student(int code, std::string name);
    /// Enroll students w/ class information
    Student(int code, std::string name, const Uc& curricularUnit,const Class& aClass);
    /// Adds a class to the student's list of classes
    void addClassUC(Uc curricularUnit,Class aClass);
    /// Gets student's code
    int getCode() const;
    /// Displays what classes the student is enrolled to
    void showEnrolledClasses() const;
    /// Gets <UC,Class> map
    std::map<Uc,Class> getEnrolledClasses() const;
    /// Gets student's name
    std::string getName() const;
    bool operator<(Student student) const{
        return getCode() < student.getCode();
    }
    bool operator>(Student student) const{
        return getCode() > student.getCode();
    }
    bool operator==(Student student) const{
        return getCode() == student.getCode();
    }

};
#endif //FEUP_AED_STUDENT_H
