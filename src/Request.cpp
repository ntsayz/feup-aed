//
// Created by ntsayz on 10/20/22.
//

#include "Request.h"


void Request::removeStudent(std::map<Student,std::map<Uc,std::vector<Class>>> students_uc_classes) {
    int student_code;
    std::string class_code,name,uc_code;
    std::map<Uc,std::vector<Class>> map_classes;
    std::cout << "Enter Student's code: " << "\n";
    std::cin >> student_code;
    std::cout << "Student's name" << "\n";
    std::cin >> name;
    std::cout << "Enter Uc's code: " << "\n";
    std::cin >> uc_code;
    std::cout << "Enter the class code: " << "\n";
    std::cin >> class_code;
    Uc uc(uc_code,class_code);
    Student s(student_code,name);
    Class c(class_code);

    auto it = students_uc_classes.find(s);
    if(it!=students_uc_classes.end()){
        auto i = it->second.find(uc);
        if(i != it->second.end()){
            auto x = std::find(i->second.begin(), i->second.end(),c);
            i->second.erase(x);
        }
    }


}

void Request::add(std::map<Uc,std::map<Class,std::vector<Slot>>> schedules,std::map<Student,std::map<Uc,std::vector<Class>>> students_uc_classes) {
    int student_code;
    std::string class_code,name,uc_code;

    std::cout << "Enter Student's code: " << "\n";
    std::cin >> student_code;
    std::cout << "Student's name" << "\n";
    std::cin >> name;
    std::cout << "Enter Uc's code: " << "\n";
    std::cin >> uc_code;
    std::cout << "Enter the class code: " << "\n";
    std::cin >> class_code;
    Uc uc(uc_code,class_code);
    Student s(student_code,name);
    Class c(class_code);
    Class::addStudent(uc,s);


    auto i = schedules.find(uc);

}