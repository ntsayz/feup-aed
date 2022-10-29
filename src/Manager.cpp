//
// Created by ntsayz on 10/8/22.
//


#include "Manager.h"

Manager::Manager() {
    globalSession = true;
    loadFilesInfo();
    load();
}

void Manager::startApplication(){
    while(globalSession) {
        Utility::clear_screen();
        short choice = Menu::Main();
        switch (choice) {
            case 1:
                Listings();
                break;
            case 2:
                testing();
                break;
            case 3:
                break;
            case 9:
                globalSession = false;
                break;
            default:
                std::cerr << "That doesn't seem like a valid option..\n";
                break;
        }
    }

}

void Manager::Listings() {
    bool localSession = true;
    while(localSession){
        Utility::clear_screen();
        short choice = Menu::Listings();
        switch (choice){
            case 1:
                studentsListings();
                break;
            case 9:
                localSession = false;
                break;
            default:
                break;
        }

    }

}

void Manager::studentsListings() {
    bool localSession = true;
    while(localSession){
        short choice = Menu::studentsListings();
        switch (choice) {
            case 1:{
                bool st = true;
                while(st){
                    st = Menu::studentsListings_Class(students,classes,st);
                }
                break;
            }
            case 2:
                break;

            case 5:
                localSession = false;
                break;
            default:
                break;
        }
    }
}
//TODO: MENUS HERE
void Manager::classesListings() {

}

void Manager::UCListings() {

}

void Manager::schedulesListings() {

}

void Manager::loadFilesInfo()
{
    std::vector<std::string> vec;
    const char *fname = Utility::getStudentClassesPath();
    FILE *file = fopen(fname, "r");
    if(!file)
    {
        std::cerr << ("Could not open the file\n");
    }
    char content[1024];
    int c = 0 ;
    int c1 = 0;
    while(fgets(content, 1024, file))
    {
        c++;
        Student prevStud;
        char *v = strtok(content, ",");

        while(v)
        {
            c1++;
            std::string s = v;
            if(c>1 && s.size() >1){
                vec.push_back((std::string)s);
            }
            v = strtok(NULL, ",");
        }

        if(c>1){
            int code;
            Uc uc(vec[2]);
            Class aClass(vec[3]);
            std::stringstream sss;
            sss << vec[0];
            sss >> code;
            Student student(code,vec[1],uc,aClass);

            //aClass.addStudent(uc,student);
            classes.insert(aClass);
            students.insert(student);
            //student.addClassUC(uc,aClass);
            curricularUnits.insert(uc);

            if(students_uc_classes.find(student) == students_uc_classes.end()){
                std::map<Uc,std::list<Class>> ucClassMap;
                std::list<Class> classList;
                classList.push_back(aClass);
                ucClassMap[uc] = classList;
                students_uc_classes[student] = ucClassMap ;
            }else{
                students_uc_classes[student][uc].push_back(aClass);
            }

        }
        vec.clear();
    }
    fclose(file);

    vec.clear();

    const char *fname1 = Utility::getClassesUcPath();
    FILE *file1 = fopen(fname1, "r");
    c = 0;
    if(!file1)
    {
        std::cerr << ("Could not open the file\n");
    }
    char content1[1024];
    while(fgets(content1, 1024, file1))
    {
        c++;
        char *v = strtok(content1, ",");
        while(v)
        {
            std::string s = v;
            if(c>1 && s.size() >1){
                vec.push_back((std::string)s);
            }
            v = strtok(NULL, ",");
        }

        if(c>1){
            Uc uc(vec[0]);
            Class aClass(vec[1]);
            classes.insert(aClass);
            curricularUnits.insert(uc);
        }
        vec.clear();
    }
    fclose(file1);

}
// TODO: make these two classes more readable and fix them , a lot of repetition
void Manager::load() {
    std::vector<std::string> vec;
    const char *fname = Utility::getStudentClassesPath();
    FILE *file = fopen(fname, "r");
    if(!file)
    {
        std::cerr << ("Could not open the file\n");
    }
    int prevStud, prevCode = 0;
    char content[1024];
    int c = 0 ;
    int c1 =0 ,c2 = 0;
    int code;
    while(fgets(content, 1024, file))
    {
        c++;

        char *v = strtok(content, ",");
        while(v)
        {

            std::string s = v;
            if(c>1 && s.size() >1){
                vec.push_back((std::string)s);
            }
            v = strtok(NULL, ",");
        }

        if(c>1){
            Uc uc(vec[2]);
            Class aClass(vec[3]);
            std::stringstream sss;
            sss << vec[0];
            sss >> code;


        }
        vec.clear();
    }
    fclose(file);

}

void Manager::testing(){
    /*int i;
    std::cout << "\nClasses\n";
    for(Class aClass : classes){
        //std::cout << aClass.getClassSize() << "\n";
        //aClass.showStudents();
        //std::cout << "\n";
    }
    std::cout << "\nUC\n\n";
    for(Uc uc: curricularUnits){
        //std::cout << uc.get_uc_Code()<< "\n";
    }
    std::cout << "\nStudents\n\n";
    for(Student student: students){
        //student.showEnrolledClasses();
        //std::cout << "\n";
    }*/
    //for (auto it = ucclasses.begin();it != ucclasses.end();++it) std::cout << "  [" << (*it).first.getCode() << ", " << (*it).second.getClassCode() << "]";

   /* for (auto & students_uc_classe : students_uc_classes) {
        std::cout << "(" << students_uc_classe.first << ") --> [";
        for(auto & itt : students_uc_classe.second){
            std::cout << "["<< itt.first.getCode() << ", " << itt.second.getClassCode() << "],";
        }
        std::cout << "\n";
        // (*it).second << "]";
    }*/

    for(auto it: students_uc_classes){
        std::cout  << "("<< it.first.getName() << ") ==> [";
        for(auto [uc,classList]: it.second){
            for(auto aClass : classList){
                std::cout <<  "["<< uc.get_uc_Code() << ", " << aClass.getClassCode() << "],";
            }
        }
        std::cout << "]\n";
    }
    ;
}




