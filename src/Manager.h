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
#include "Utilities.h"

class Manager {
private:
    /*
    std::string classes_PATH = "schedule/classes.csv";
    std::string classes_uc_PATH = "schedule/classes_per_uc.csv";
    std::string students_classes_PATH = "schedule/students_classes.csv";
*/
    std::vector<std::string> files;
    bool session;
    private: Utilities utils;
public:
    Manager();
    /// Gets options and calls the rest of the program
    void startApplication();
    /// Main menu
    int mainMenu();






};


#endif //FEUP_AED_MANAGER_H
