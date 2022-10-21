//
// Created by ntsayz on 10/8/22.
//

#ifndef FEUP_AED_MANAGER_H
#define FEUP_AED_MANAGER_H
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
#include "Uc.h"


class Manager {
private:
    std::vector<std::string> files;
    std::set<Student> students;
    std::set<Class> classes;
    std::set<Uc> curricularUnits;
    bool session;

    void Listings();
    void studentsListings();
    void loadDataStructures();

public:
    Manager();
    /// Main startApplication
    void startApplication();

};


#endif //FEUP_AED_MANAGER_H
