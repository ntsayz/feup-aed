//
// Created by ntsayz on 10/8/22.
//


#include <functional>
#include "Manager.h"

Manager::Manager() {
    globalSession = true;
    loadDatafromFiles();
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
            case 2:
                classesListings();
                break;
            case 3:
                UCListings();
                break;
            case 4:
                schedulesListings();
                break;
            case 0:
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
                bool s = true;
                while(s){
                    s = Menu::studentsListings_Class(students, classes, s);
                }
                break;
            }
            case 2:

                break;
            case 0:
                localSession = false;
                break;
            default:
                break;
        }
    }
}
//TODO: MENUS HERE
void Manager::classesListings() {
    Menu::classesListings();
    std::vector<std::string> l1;
    std::vector<std::string> l2;
    std::vector<std::string> l3;
    for(auto aClass: classes){
        if(aClass.getClassYear() ==1){
            l1.push_back(aClass.getClassCode());
        }else if(aClass.getClassYear() ==2){
            l2.push_back(aClass.getClassCode());
        }else if(aClass.getClassYear() ==3){
            l3.push_back(aClass.getClassCode());
        }
    }
    for(int i = 0; i <  l3.size(); i++){
        std::cout << "|"<<std::setfill(' ')<<  std::setw(13) << l1[i] << std::setw(7) << "|"
                  << std::setw(13)<< l2[i];
        std::cout << std::setw(7) << "|" << std::setw(12) << l3[i] << std::setw(7) <<"|\n";
    }
    Utility::footer();
    int i;
    std::cin  >> i;
    l1.clear();
    l2.clear();
    l3.clear();
}

void Manager::UCListings() {
    bool localSession = true;
    std::vector<std::string> l1;
    std::vector<std::string> l2;
    std::vector<std::string> l3;
    while(localSession){
        Utility::header("Curricular Units");
        std::cout << "|" << std::setfill('-') <<std::setw(177) << "|\n";

        // all classes in each curricular unit
        for(auto& [uc,v] : uc_classes){
            std::cout  << "|"<< uc.get_uc_Code() << "| ==> ";
            for( auto aclass : v){
                std::cout <<  " | " << aclass.getClassCode() << "";
            }
            std::cout << " |\n";
            std::cout << "|" << std::setfill('-') <<std::setw(177) << "|\n";
        }

        Utility::footer();
        int i;
        std::cin >> i;
        if(i == 0)localSession = false;
        l1.clear();
        l2.clear();
        l3.clear();
    }

}

void Manager::schedulesListings() {
        bool localSession = true;
        while(localSession){
            Utility::clear_screen();
            Utility::header("SCHEDULES");
            Utility::body("",{""});
            Utility::footer();
            int i;
            std::cin >> i;
            if(i ==0) localSession = false;
        }
}

void Manager::loadDatafromFiles()
{
    //Gets data from students_classes.csv
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
            classes.insert(aClass);
            curricularUnits.insert(uc);
            students.insert(student);

            if(students_uc_classes.find(student) == students_uc_classes.end()){
                std::map<Uc, std::vector<Class>> ucClassMap;
                std::vector<Class> classList;
                classList.push_back(aClass);
                ucClassMap[uc] = classList;
                students_uc_classes[student] = ucClassMap ;
                std::vector<Uc> l;
                l.push_back(uc);
                classes_uc[aClass] = l;
            }else{
                students_uc_classes[student][uc].push_back(aClass);
                classes_uc[aClass].push_back(uc);
            }
            if(uc_classes.find(uc) == uc_classes.end()){
                std::vector<Class> classList;
                classList.push_back(aClass);
                uc_classes[uc] = classList;
            }else{
                uc_classes[uc].push_back(aClass);
            }

        }
        vec.clear();
    }
    fclose(file);

    vec.clear();
    //Gets data from classes_per_uc.csv (The other file didn't have all the info needed)
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

        if(c>1) {
            Uc uc(vec[0]);
            Class aClass(vec[1]);
            classes.insert(aClass);
            curricularUnits.insert(uc);
            if(uc_classes.find(uc) == uc_classes.end()){
                std::vector<Class> classList;
                classList.push_back(aClass);
                uc_classes[uc] = classList;
            }else{
                uc_classes[uc].push_back(aClass);
            }
        }
        vec.clear();
    }
    fclose(file1);
    //normalization


    const char *fname2 = Utility::getClassesPath();
    FILE *file2 = fopen(fname2, "r");
    c = 0;
    if(!file1)
    {
        std::cerr << ("Could not open the file\n");
    }
    char content2[1024];
    while(fgets(content2, 1024, file2))
    {
        c++;
        char *v = strtok(content2, ",");
        while(v)
        {
            std::string s = v;
            if(c>1 && s.size() >1){
                vec.push_back((std::string)s);
            }
            v = strtok(NULL, ",");
        }

        if(c>1) {
            float starthour = 0 , duration = 0;
            int starthourint, durationint;
            std::cout  << vec[2] << "," << vec[3] << "," << vec[4] << "," << vec[5] << "\n";
            if(vec[4].size() == 1){

                std::stringstream sss;
                sss << vec[4];
                sss >> durationint;
                duration = (float) durationint;
            }else if(vec[4].size() > 1 ){
                std::stringstream sss;
                sss << vec[4];
                sss >> duration;
                //duration = duration;
            }
            if(vec[3].size() == 1){
                std::stringstream ss;
                ss << vec[3];
                ss >> starthourint;
                starthour = (float) starthourint;
            }else if(vec[3].size() > 1){
                std::stringstream ss;
                ss << vec[3];
                ss >> starthour;
            }

            Slot slot(vec[2],starthour,duration,vec[5]);
            Uc uc(vec[1]);
            Class aClass(vec[0]);

            if(schedules.find(uc) == schedules.end()){
                std::map<Class, std::vector<Slot>> classSlotMap;
                std::vector<Slot> SlotList;
                SlotList.push_back(slot);
                classSlotMap[aClass] = SlotList;
                schedules[uc] = classSlotMap ;
            }else{
                schedules[uc][aClass].push_back(slot);
            }

        }
        vec.clear();
    }
    fclose(file1);

    for(auto& [uc,v] : uc_classes){
        std::set<Class> s( v.begin(), v.end() );
        v.assign( s.begin(), s.end() );
    }
    /*
    for(auto& [uc, classMap] : schedules){
        for(auto [aclass,vec1]: classMap){
            std::set<Slot> s( vec1.begin(), vec1.end() );
            vec1.assign( s.begin(), s.end() );

        }

    }*/

}


void Manager::testing(){
    for(auto stud: students){
        for(auto& [k,v] : students_uc_classes[stud] ) {
            for(auto& el: v){
                stud.addClassUC(const_cast<Uc &>(k), el);
                stud.showEnrolledClasses();
            }
        }
    }
    for(auto& i : students){
        i.showEnrolledClasses();
    }
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

    /*std::cout << "here";
    for(auto it: students_uc_classes){
        std::cout  << "("<< it.first.getCode() << ") ==> [";
        for(auto [uc,classList]: it.second){
            for(auto aClass : classList){
                std::cout <<  "["<< uc.get_uc_Code() << ", " << aClass.getClassCode() << "],";
            }
        }
        std::cout << "]\n";
    }*/
    // UC CLASSES
    for(auto& [uc,v] : uc_classes){
        std::cout  << "("<< uc.get_uc_Code() << ") ==> [";
        for( auto aclass : v){
            std::cout <<  "[" << aclass.getClassCode() << "],";
        }
        std::cout << "\n";
    }
    //std::cout << "]\n";


    // schedules
    for(auto [uc, classMap] : schedules){
        std::cout << std::setfill(' ') << std::setw(20)  << "<== ("<< uc.get_uc_Code() << ") ==>\n\n[";
        for(auto [aclass,vec]: classMap){
            for(auto slot: vec){
                std::cout << "(" << aclass.getClassCode() << ") - [" << slot.getWeekday() << "," << slot.getDuration() << "," << slot.getSlotType() << "],";
            }
            std::cout << "\n";
        }
        std::cout << "]\n";
    }

    int i;
    std::cin >> i;
}




