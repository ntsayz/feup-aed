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
#include "Request.h"
#include "Menu.h"
#include "Uc.h"
#include "BST.h"


class Manager {
private:

    std::vector<std::string> files;
    std::set<Student> students;
    //std::vector<std::reference_wrapper<Student>> students1 ;
    std::set<Class> classes;
    ///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    /// (Student(key): (UC(key), vector<Class>(value))(value) )
    std::map<Student,std::map<Uc,std::vector<Class>>> students_uc_classes;
    ///!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    std::map<Uc,std::map<Class,std::vector<Slot>>> schedules;
    std::map<Class,std::vector<Uc>> classes_uc;
    std::map<Uc,std::vector<Class>> uc_classes;
    std::set<Uc> curricularUnits;
    std::queue<int> requests;
    bool globalSession;

    /// Listings
    void Listings();
    /// Request
    void Requests();
    /// Student listings
    void studentsListings();
    /// Classes Listings
    void classesListings();
    /// UC's listings
    void UCListings();
    /// Schedules listings
    void schedulesListings();
    /// Loads students,classes & curricular units data structures from file data
    void loadDatafromFiles();
    /// Loads each object from each class with its particular data (eg:. Inserting students in a particular class)
    void load();
public:
    /// Constructor
    Manager();
    /// Starts the Application
    void startApplication();

    void thisFunctionIsForTestingPurposes();

    void getYearClass(int &year, int &classnum);
};


#endif //FEUP_AED_MANAGER_H
