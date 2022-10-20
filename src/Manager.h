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
#include "Utilities.h"
#include "Student.h"
#include "Class.h"


class Manager {
private:
    std::vector<std::string> files;
    std::set<Student> students;
    std::vector<Class> classes;


    bool session;
private: Utilities utils;

    /// Main menu
    static short mainMenu();
public:
    Manager();
    /// Gets options and calls the rest of the program
    void startApplication();


};


#endif //FEUP_AED_MANAGER_H
