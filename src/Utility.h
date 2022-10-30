//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_UTILITY_H
#define FEUP_AED_UTILITY_H
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <set>
#include <fstream>
#include "Class.h"
#include "Student.h"
#include <iomanip>



class Utility {
private:
    //auto static start,stop;

public:
    Utility();
    /// Gets and sanitizes user's input (int)
    static short getInput(short choice, short min, short max);
    /// Clear screen (Cross-Platform)
    static void clear_screen();
    /// Gets .csv file "classes"
    static const char* getClassesPath();
    /// Gets .csv file "classes_per_uc"
    static const char* getClassesUcPath();
    /// Gets .csv file "students_classes"
    static const char* getStudentClassesPath();
    /// Makes sure that all files exist before starting program
    //static bool loadFiles(std::set<Student> students,std::vector<Class> horario);
    /// Auxiliary, to print
    static void footer();
    template <typename T>
    T loadFiles(T file);

    static void header(const std::string& header);

    static void body(std::vector<std::string> l);

    static void path(std::string path);
};


#endif //FEUP_AED_UTILITY_H
