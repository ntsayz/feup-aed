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

    if(it!=students_uc_classes.end()){
        auto i = it->second.find(uc);
        if(i != it->second.end()){
            auto x = std::find(i->second.begin(), i->second.end(),c);
            if(!(x!=i->second.end()))
                cout << "Student removed successfully "<< "\n";
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

    auto itr = students_uc_classes.find(s);
    if(itr!=students_uc_classes.end()){
        auto it = itr->second.find(uc);
        auto i = it->second.begin();
        if(i->getClassSize() > 12){
            std::cout << "Nao ha vagas na turma " << "\n";
        }
        else
            Class::addStudent(uc,s);
    }
}

void Request::change(std::map<Student, std::map<Uc, std::vector<Class>>> students_uc_classes) {
    int student_code;
    std::string class_code,name,uc_code,turma;

    std::cout << "Enter Student's code: " << "\n";
    std::cin >> student_code;
    std::cout << "Student's name" << "\n";
    std::cin >> name;
    std::cout << "Enter Uc's code: " << "\n";
    std::cin >> uc_code;
    std::cout << "Enter the code of the class you wish to change to: " << "\n";
    std::cin >> class_code;
    Student s(student_code,name);
    Uc uc(uc_code,class_code);
    Uc classe_do_estudante(uc_code);
    Class c(class_code);

    auto itr = students_uc_classes.find(s);
    if(itr!=students_uc_classes.end()){
        auto it = itr->second.find(uc);
        auto i = it->second.begin();
        if(i->getClassSize() > 12){
            std::cout << "Nao ha vagas na turma " << "\n";
        }
        else
            Class::addStudent(uc,s);
    }

    if(itr!=students_uc_classes.end()){
        auto it = itr->second.find(classe_do_estudante);
        auto i = it->second.begin();
        turma = i->getClassCode();
    }

    Class class_student(turma);
    Uc old(uc_code,turma);

    if(itr !=students_uc_classes.end()){
        auto it = itr->second.find(old);
        if(it!=itr->second.end()){
            auto i = std::find(it->second.begin(), it->second.end(),class_student);
            it->second.erase(i);
        }
    }

    if(itr !=students_uc_classes.end()){
        auto it = itr->second.find(old);
        if(it!=itr->second.end()){
            auto i = std::find(it->second.begin(), it->second.end(),class_student);
            if(!(i!=it->second.end()))
                cout << "Change done successfully ";
        }
    }
}

void Request::changeMultiple(std::map<Student, std::map<Uc, std::vector<Class>>> students_uc_classes) {

}