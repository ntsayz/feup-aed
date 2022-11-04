//
// Created by ntsayz on 10/21/22.
//

#ifndef FEUP_AED_MENU_H
#define FEUP_AED_MENU_H
#include <string>
#include <limits>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <set>
#include <vector>
#include "Utility.h"
#include "Student.h"
#include "Class.h"
#include "Uc.h"
#include "Slot.h"
#include "Menu.h"
#include "BST.h"
#include "Manager.h"

class Menu {
private:
public:
    /// Main menu
    static short Main();
    /// Listings menu, to show all available data
    static short Listings();
    /// Listings subsection -Students (listings/students)
    static short  studentsListings();
    /// Students subsection -Classes (listings/students/classes)
    static bool studentsListings_Class(const std::map<Student,std::map<Uc,std::vector<Class>>>& students_uc_classes, bool session);
    /// Listings subsection -Classes (listings/classes)
    static void classesListings();
    /// Listings subsection - UC's (listings/ucs)
    void UCListings();
    /// Listings subsection -Schedules (listings/schedules)
    static void schedulesListings(std::map<Uc,std::map<Class,std::vector<Slot>>> schedules,std::set<Class> classes,std::map<Class,std::vector<Uc>> classes_uc,std::map<Student,std::map<Uc,std::vector<Class>>> students_uc_classes, int choice);

    static void studentsListings_Year(const map<Student, std::map<Uc, std::vector<Class>>> &students);

    static void studentsListings_UC(map<Student, map<Uc, std::vector<Class>>>& students, std::map<Uc,std::vector<Class>>& uc_classes);
};


#endif //FEUP_AED_MENU_H
