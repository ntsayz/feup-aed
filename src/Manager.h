//
// Created by ntsayz on 10/8/22.
//

#ifndef FEUP_AED_MANAGER_H
#define FEUP_AED_MANAGER_H
#include <string>

class Manager {
private:

public:
    Manager();
    /// Get user's menu choice
    int getChoice(short choice, short min, short max);
    /// Make sure that all files are loadable before starting program
    bool loadFiles(std::string fname);
    /// Main menu
    int mainMenu();
};


#endif //FEUP_AED_MANAGER_H
