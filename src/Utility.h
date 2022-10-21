//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_UTILITY_H
#define FEUP_AED_UTILITY_H
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "Class.h"
#include "Student.h"


class Utility {
private:



public:
    Utility();
    /// Gets and sanitizes user's input
    static short getInput(short choice, short min, short max);
    /// Clear screen (Cross-Platform)
    static void clear_screen();
    static std::string getClassesPath();
    static std::string getClassesUcPath();
    static std::string getStudentClassesPath();
    /// Make sure that all files exist before starting program
    //static bool loadFiles(std::set<Student> students,std::vector<Class> horario);
    template <typename T>
    T loadFiles(T file);
};


#endif //FEUP_AED_UTILITY_H
