//
// Created by ntsayz on 10/8/22.
//

#ifndef FEUP_AED_MANAGER_H
#define FEUP_AED_MANAGER_H
#include <string>
#include <limits>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
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
    void loadClasses_UCs();
    void loadStudents();

public:
    Manager();
    /// Main startApplication
    void startApplication();

};


#endif //FEUP_AED_MANAGER_H
