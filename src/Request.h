//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_REQUEST_H
#define FEUP_AED_REQUEST_H
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <vector>
#include "Utility.h"
#include "Student.h"
#include "Class.h"
#include "Request.h"
#include "Menu.h"
#include "Uc.h"

class Request {
public:
    static void removeStudent(std::map<Student,std::map<Uc,std::vector<Class>>> students_uc_classes);
    static void add(std::map<Uc,std::map<Class,std::vector<Slot>>> schedules,std::map<Student,std::map<Uc,std::vector<Class>>> students_uc_classes);
    static void change(std::map<Student,std::map<Uc,std::vector<Class>>> students_uc_classes);
    static void changeMultiple(std::map<Student,std::map<Uc,std::vector<Class>>> students_uc_classes);
};


#endif //FEUP_AED_REQUEST_H
