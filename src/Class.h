//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_CLASS_H
#define FEUP_AED_CLASS_H
#include <string>
#include <list>
#include <set>
#include <utility>
#include "Slot.h"
//#include "Student.h"
struct Student;
class Class {
private:
    std::string class_Code;
    std::list<Slot> schedule;
    std::set<Student> students;
public:
    Class(std::string classCode);


    std::string getClassCode() const;
    int getClassNr() const;
    void addStudent(Student student);

    void showStudents()const;

    bool operator<(const Class& aClass) const{
        return getClassCode() < aClass.getClassCode();
    }
    bool operator==(const Class& aClass) const{
        return getClassCode() == aClass.getClassCode();
    }
};


#endif //FEUP_AED_CLASS_H
