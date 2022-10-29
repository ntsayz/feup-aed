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
    std::multimap<Uc,Class> ucclasses;
    std::map<int,std::list<std::map<Uc,Class>>> students_uc_classes;
    std::set<Uc> curricularUnits;
    bool globalSession;
    /// Listings
    void Listings();
    /// Student listings
    void studentsListings();
    /// Classes Listings
    void classesListings();
    /// UC's listings
    void UCListings();
    /// Schedules listings
    void schedulesListings();
    /// Loads students,classes & curricular units data structures from file data
    void loadFilesInfo();
    /// Loads each object from each class with its particular data (eg:. Inserting students in a particular class)
    void load();
public:
    /// Constructor
    Manager();
    /// Starts the Application
    void startApplication();


    void testing();
};


#endif //FEUP_AED_MANAGER_H
