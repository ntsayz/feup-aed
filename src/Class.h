//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_CLASS_H
#define FEUP_AED_CLASS_H
#include <string>
#include <list>
#include <set>
#include <map>
#include <utility>
#include <sstream>
#include "Slot.h"
#include "Uc.h"
//#include "Student.h"
struct Student;
class Class {
private:

    int uid ;
    std::string class_Code;
    std::list<Slot> schedule;
    std::map<Uc,std::vector<Student>> UC_students;
    std::set<Student> students;
public:
    Class();
    explicit Class(std::string classCode);
    /// Gets class code (String)
    [[nodiscard]] std::string getClassCode() const;
    /// Gets Number of class (to compare)
    [[nodiscard]] int getClassNr() const;
    /// Adds student to the class's list
    void addStudent(Uc& uc, const Student& student);
    /// Gets number of students in a class
    [[nodiscard]] int getClassSize() const;
    /// Gives a list of all students in a class
    void showStudents()const;
    ///
    int getClassYear() const;
    /// Class comparator
    bool operator<(const Class& aClass) const{
        return get_uid() < aClass.get_uid();
    }
    /// Class comparator
    bool operator==(const Class& aClass) const{
        return get_uid() == aClass.get_uid();
    }

    int get_uid() const;
};


#endif //FEUP_AED_CLASS_H
