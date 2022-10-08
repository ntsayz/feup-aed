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

class Manager {
private:
    /*
    std::string classes_PATH = "schedule/classes.csv";
    std::string classes_uc_PATH = "schedule/classes_per_uc.csv";
    std::string students_classes_PATH = "schedule/students_classes.csv";
*/
    std::vector<std::string> files;
    bool session;





public:
    Manager();
    /// Gets options and calls the rest of the program
    void startApplication();
    /// Main menu
    int mainMenu();
    /// Gets and sanitizes user's input
    int getInput(short choice, short min, short max);
    /// Make sure that all files exist before starting program
    bool checkFiles() const;
    /// Clear screen (Cross-Platform)
    void clear_screen() const;




};


#endif //FEUP_AED_MANAGER_H
