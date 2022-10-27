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
#include "Menu.h"

class Menu {
private:
public:
    /// Main menu
    static short Main();
    /// Listins menu, to show all available data
    static short Listings();
    /// Listings subsection -Students
    static short  studentsListings();
    /// Students subsection -Classes
    static bool studentsListings_Class(std::set<Student> students,std::set<Class> classes,bool session);
};


#endif //FEUP_AED_MENU_H
