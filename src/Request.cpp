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
    student_code = Utility::numberInput(student_code);
    std::cout << "Student's name" << "\n";
    std::cin >> name;
    std::cout << "Enter Uc's code (L.EIC001) " << "\n";
    std::cin >> uc_code;
    uc_code = Utility::stringInput(uc_code);
    std::cout << "Enter the class code (1LEIC01): " << "\n";
    std::cin >> class_code;
    class_code = Utility::stringInput(class_code);
    Uc uc(uc_code,class_code);
    Student s(student_code,name);
    Class c(class_code);


    auto it = students_uc_classes.find(s);
    if(it!=students_uc_classes.end()){
        auto i = it->second.find(uc);
        if(i != it->second.end()){
            auto x = std::find(i->second.begin(), i->second.end(),c);
            students_uc_classes.erase(s);
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
    unsigned int student_code,difference,c1,c2;
    std::string class_code,name,uc_code,turma;
    std::map<Uc,std::vector<Class>> map_classes;

    std::cout << "Enter Student's code: " << "\n";
    std::cin >> student_code;
    student_code = Utility::numberInput(student_code);
    std::cout << "Student's name" << "\n";
    std::cin >> name;
    std::cout << "Enter Uc's code (L.EIC001) " << "\n";
    std::cin >> uc_code;
    uc_code = Utility::stringInput(uc_code);
    std::cout << "Enter the class code (1LEIC01): " << "\n";
    std::cin >> class_code;
    class_code = Utility::stringInput(class_code);

    Uc uc(uc_code,class_code);
    Student s(student_code,name);
    Class c(class_code);
    /// used to find the studen'ts current class
    Uc classe_do_estudante(uc_code);
    Uc old(uc_code,turma);
    Class class_student(turma);


    auto itr = students_uc_classes.find(s);

    c1 =  c.getClassSize();

    if(itr!=students_uc_classes.end()){
        auto it = itr->second.find(classe_do_estudante);
        auto i = it->second.begin();
        if(it!=itr->second.end()){
            turma = i->getClassCode();
            c2 = i->getClassSize();
        }
    }

    difference = c2-c1;

    if(itr!=students_uc_classes.end()){
        auto it = itr->second.find(uc);
        auto i = it->second.begin();
        if(i->getClassSize() > 12){
            std::cout << "No vacancies in class. " << "\n";
            r.push_back(2);
        }
        else{
            if(difference >= 4){
                std::cout << "Unable to change class." << "\n";
            }
            else
                Class::addStudent(uc,s);
        }
    }


}

void Request::change(std::map<Student, std::map<Uc, std::vector<Class>>> students_uc_classes) {
    unsigned int student_code,difference,c1,c2;
    std::string class_code,name,uc_code,turma;


    std::cout << "Enter Student's code: " << "\n";
    std::cin >> student_code;
    student_code = Utility::numberInput(student_code);
    std::cout << "Student's name" << "\n";
    std::cin >> name;
    std::cout << "Enter Uc's code (L.EIC001) " << "\n";
    std::cin >> uc_code;
    uc_code = Utility::stringInput(uc_code);
    std::cout << "Enter the class code (1LEIC01): " << "\n";
    std::cin >> class_code;

    Student s(student_code,name);
    Uc uc(uc_code,class_code);
    Uc classe_do_estudante(uc_code);
    Uc old(uc_code,turma);
    Class c(class_code);
    Class class_student(turma);

    c1 =  c.getClassSize();

    auto itr = students_uc_classes.find(s);

    if(itr!=students_uc_classes.end()){
        auto it = itr->second.find(classe_do_estudante);
        auto i = it->second.begin();
        if(it!=itr->second.end()){
            turma = i->getClassCode();
            c2 = i->getClassSize();
        }
    }

    difference = c2-c1;

    if(itr!=students_uc_classes.end()){
        auto it = itr->second.find(uc);
        auto i = it->second.begin();
        if(i->getClassSize() > 12){
            std::cout << "No vacancies in class. " << "\n";
            r.push_back(2);
        }
        else{
            if(difference >= 4){
                std::cout << "Unable to change class." << "\n";
            }
            else
                Class::addStudent(uc,s);
        }
    }

    if(itr !=students_uc_classes.end()){
        auto it = itr->second.find(old);
        if(it!=itr->second.end()){
            auto i = std::find(it->second.begin(), it->second.end(),class_student);
            it->second.erase(i);
        }
    }

    if(itr != students_uc_classes.end()){
        auto it = itr->second.find(old);
        if(it!=itr->second.end()){
            auto i = std::find(it->second.begin(), it->second.end(),class_student);
            if(!(i!=it->second.end()))
                cout << "Change done successfully ";
        }
    }
}

void Request::changeMultiple(std::map<Student, std::map<Uc, std::vector<Class>>> students_uc_classes) {
    unsigned int student_code,n,c1,c2,difference;
    std::string class_code,name,uc_code,turma;
    std:vector<Uc> classes;
    std::vector<Class> turmas;

    std::cout << "Enter Student's code" << "\n";
    std::cin >> student_code;
    student_code = Utility::numberInput(student_code);
    std::cout << "Student's name" << "\n";
    std::cin >> name;
    std::cout << "Enter the number of classes you wish to change:" << "\n";
    std::cin >> n;
    n = Utility::numberInput(n);

    Student s(student_code,name);
    Uc classe_do_estudante(uc_code);

    for(unsigned int i = 0 ;i <=n ;i++){
        std::cout << "Enter the uc code: " << "\n";
        std::cin >> uc_code;
        uc_code = Utility::stringInput(uc_code);
        std::cout << "Enter the class code: " << "\n";
        std::cin >> class_code;
        class_code = Utility::stringInput(class_code);
        Uc uc(uc_code,class_code);
        Uc old(uc_code,turma);
        Class c(class_code);
        Class class_student(turma);
        c1 =  c.getClassSize();

        auto itr = students_uc_classes.find(s);

        if(itr!=students_uc_classes.end()){
            auto it = itr->second.find(classe_do_estudante);
            auto i = it->second.begin();
            if(it!=itr->second.end()){
                turma = i->getClassCode();
                c2 = i->getClassSize();
            }
        }

        difference = c2-c1;

        if(itr!=students_uc_classes.end()){
            auto it = itr->second.find(uc);
            auto i = it->second.begin();
            if(i->getClassSize() > 12){
                std::cout << "No vacancies in class. " << "\n";
                r.push_back(2);
            }
            else{
                if(difference >= 4){
                    std::cout << "Unable to change class." << "\n";
                }
                else
                    Class::addStudent(uc,s);
            }
        }

        if(itr !=students_uc_classes.end()){
            auto it = itr->second.find(old);
            if(it!=itr->second.end()){
                auto i = std::find(it->second.begin(), it->second.end(),class_student);
                it->second.erase(i);
            }
        }

        if(itr != students_uc_classes.end()){
            auto it = itr->second.find(old);
            if(it!=itr->second.end()){
                auto i = std::find(it->second.begin(), it->second.end(),class_student);
                if(!(i!=it->second.end()))
                    cout << "Change done successfully ";
            }
        }
    }

}

std::deque<int> Request::getUnsuccessufull() {
    return this->r;
}