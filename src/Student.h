//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_STUDENT_H
#define FEUP_AED_STUDENT_H

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
#include "Request.h"


class Student {
private:
    int code;
    std::string curr_uc;
    std::string name;
    //std::queue<Request> requests;
    std::map<Class,Uc> classes;
    std::map< Uc, Class> classes12;
    std::map<Uc,std::map<Uc,std::vector<Class>>> classes1;
    std::set<Slot> schedule;
public:
    Student();
    ///Enroll student to the faculty
    Student(int code, std::string name);
    /// Enroll students w/ class information
    Student(int code, std::string name, Uc& curricularUnit, Class& aClass);
    /// Adds a class to the student's list of classes
    void addClassUC(Uc& uc,Class& aClass);
    /// Gets student's code
    const int getCode() const;
    /// Displays what classes the student is enrolled to
    void showEnrolledClasses() const;
    /// Gets <UC,Class> map
    std::map<Class,Uc> getEnrolledClasses() const;
    /// Get number of enrolled classes
    int getNumberEnrolledClasses() const;
    /// Gets student's name
    std::string getName() const;
    /// Sets this student's uc as the current (for sorting)
    void setUC(std::string s);
    /// Gets students current uc
    std::string getUC();
    bool operator<(Student student) const{
        return this->getCode() < student.getCode();
    }
    bool operator>(Student student) const{
        return getCode() > student.getCode();
    }
    bool operator==(Student student) const{
        return getCode() == student.getCode();
    }

};
#endif //FEUP_AED_STUDENT_H
