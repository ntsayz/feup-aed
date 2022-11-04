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
    /// Gets and sanitizes user's input given a range (Number)
    static short getInput(short choice, short min, short max);
    /// Clear screen (Cross-Platform)
    static void clear_screen();
    /// Gets .csv file path "classes"
    static const char* getClassesPath();
    /// Gets .csv file pth "classes_per_uc"
    static const char* getClassesUcPath();
    /// Gets .csv file path "students_classes"
    static const char* getStudentClassesPath();
    /// Makes sure that all files exist before starting program
    //static bool loadFiles(std::set<Student> students,std::vector<Class> horario);
    /// Auxiliary function, to print the menu's footer
    static void footer();
    /// Auxiliary function, to print the menu's header
    static void header(const std::string& title);
    /// Auxiliary function, to print the menu's body
    static void body(const std::string& description, std::vector<std::string> options);
    /// Auxiliary function, to print the current path of the user's location
    static void path(std::string path);
    /// Auxiliary function to print schedule
    static void schedule(std::string descriptor, std::map<Uc,std::vector<Slot>> slots);

    static void scheduleHeader(std::string descriptor);

    static void scheduleFooter();

    static void print_uc_students_table(std::multimap<std::string, std::string> m);
};


#endif //FEUP_AED_UTILITY_H
