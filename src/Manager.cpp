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
                for(Student stud: students){
                    stud.showEnrolledClasses();
                    std::cout << "\n";
                }
                std::cout << "\n";
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
    while(fgets(content, 1024, file))
    {
        c++;

        char *v = strtok(content, ",");
        int c1 = 0;
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
            //aClass.addStudent(student);
            classes.insert(aClass);
            students.insert(student);
            curricularUnits.insert(uc);
        }
        vec.clear();
    }

    fclose(file);

}
void Manager::load() {
    for(Student stud: students){
        for(Class aClass1: classes){
            std::map<Uc,Class> someMap = stud.getEnrolledClasses();
            for (auto it = someMap.begin(); it != someMap.end(); ++it)
                if (it->second == aClass1)
                    aClass1.addStudent(stud);
                    //std::cout << stud.getName();
                    //std::cout << aClass1.getClassNr() << " has now " << aClass1.getClassSize() << " students" << "\n";

        }
    }
}







