//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_CLASS_H
#define FEUP_AED_CLASS_H
#include <string>
#include <list>
#include <set>
#include <utility>
#include <sstream>
#include "Slot.h"
//#include "Student.h"
struct Student;
class Class {
private:
    std::string class_Code;
    std::list<Slot> schedule;
    std::set<Student> students;
public:
    explicit Class(std::string classCode);
    /// Gets class code (String)
    [[nodiscard]] std::string getClassCode() const;
    /// Gets Number of class (to compare)
    [[nodiscard]] int getClassNr() const;
    /// Adds student to the class's list
    void addStudent(const Student& student);
    /// Gets number of students in a class
    [[nodiscard]] int getClassSize() const;
    /// Gives a list of all students in a class
    void showStudents()const;

    bool operator<(const Class& aClass) const{
        return getClassNr() < aClass.getClassNr();
    }
    bool operator==(const Class& aClass) const{
        return getClassNr() == aClass.getClassNr();
    }
};


#endif //FEUP_AED_CLASS_H
