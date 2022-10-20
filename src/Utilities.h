//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_UTILITIES_H
#define FEUP_AED_UTILITIES_H
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "Class.h"
#include "Student.h"


class Utilities {
private:
    std::string classes_PATH = "schedule/classes.csv";
    std::string classes_uc_PATH = "schedule/classes_per_uc.csv";
    std::string students_classes_PATH = "schedule/students_classes.csv";

public:
    Utilities();
    /// Gets and sanitizes user's input
    static short getInput(short choice, short min, short max);
    /// Clear screen (Cross-Platform)
    static void clear_screen() ;
    /// Make sure that all files exist before starting program
    //static bool loadFiles(std::set<Student> students,std::vector<Class> horario);
    template <typename T>
    T loadFiles(T file);
};


#endif //FEUP_AED_UTILITIES_H
