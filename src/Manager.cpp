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
                thisFunctionIsForTestingPurposes();
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
    for(const auto& aClass: classes){
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
            for( const auto& aclass : v){
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
        Utility::body("Choose a schedule from a particular:",{"1. Student","2. Class","3. Curricular Unit"});
        Utility::footer();
        int choice;
        std::cin >> choice;
        choice = Utility::getInput(choice,0,3);
        if(choice==0){localSession = false; continue;}
        Menu::schedulesListings(schedules,classes,classes_uc,choice);
    }
}

void Manager::getYearClass(int& year, int& classnum){
    bool localsession = true;
    while(localsession){
        Utility::clear_screen();
        std::cout << std::setfill(' ') << std::setw(37) << "From what year?\n\n";
        std::cout <<  std::setw(35) << "1. 1st Year\n"
                  << std::setw(35) << "2. 2nd Year\n"
                  << std::setw(35) << "3. 3rd Year\n";
        Utility::footer();
        std::cout << "-->" << std::flush;
        std::cin >> year;
        if(year == 0){std::cerr << "Try again";
            continue;}
        year = Utility::getInput(year, (short)0, (short )3);

        if(year >= 1 && year <= 3){
            while(localsession){
                Utility::clear_screen();
                std::cout <<  std::setw(30) << "From what class?\n" << std::setfill(' ') << std::setw(60) << "0 to Exit\n";
                int i =1;
                for(Class turma: classes){
                    if(turma.getClassYear() == year){
                        std::cout << i << ". "<<turma.getClassCode() << "\n";
                        i++;
                    }
                }
                i--;
                Utility::footer();
                //i= 0;
                std::cout << "-->" << std::flush;
                std::cin >> classnum;
                if(classnum == 0){std::cerr << "Try again";
                    continue;}
                classnum = Utility::getInput((short)classnum, (short)0, i);

                if(classnum >=1 && classnum <= i && year != 0) localsession = false;
                Utility::clear_screen();
            }
        }
    }
}

void Manager::loadDatafromFiles()
{
    //file: students_classes.csv
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
            v = strtok(nullptr, ",");
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

    //file: classes_per_uc.csv (The other file didn't have all the information needed)
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
            v = strtok(nullptr, ",");
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
    vec.clear();

    // file : classes.csv - loads schedules datastructure
    const char *fname2 = Utility::getClassesPath();
    FILE *file2 = fopen(fname2, "r");
    //Line counter
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
            if(c>1){
                vec.push_back((std::string)s);

            }
            v = strtok(nullptr, ",");
        }

        if(c>1) {
            float starthour = 0 , duration = 0;
            //std::cout  << vec[2] << "," << vec[3] << "," << vec[4] << "," << vec[5] << "\n";
            std::stringstream sss;
            sss << vec[4];
            sss >> duration;

            std::stringstream ss;
            ss << vec[3];
            ss >> starthour;

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

    for(auto& [aclass,v] : classes_uc){
        std::set<Uc> s( v.begin(), v.end() );
        v.assign( s.begin(), s.end() );
    }
}


void Manager::thisFunctionIsForTestingPurposes(){
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
    /* UC CLASSES
    /for(auto& [uc,v] : uc_classes){
        std::cout  << "("<< uc.get_uc_Code() << ") ==> [";
        for( const auto& aclass : v){
            std::cout <<  "[" << aclass.getClassCode() << "],";
        }
        std::cout << "\n";
    }*/
    for(auto& [aclass,v] : classes_uc){
        std::cout  << "("<< aclass.getClassCode() << ") ==> [";
        for( const auto& uc : v){
            std::cout <<  "[" << uc.get_uc_Code() << "],";
        }
        std::cout << "\n";
    }
    //std::cout << "]\n";


    // schedules
    for(auto [uc, classMap] : schedules){
        std::cout << std::setfill(' ') << std::setw(20)  << "<== ("<< uc.get_uc_Code() << ") ==>\n\n[";
        for(auto [aclass,vec]: classMap){
            for(auto slot: vec){
                std::cout << "(" << aclass.getClassCode() << ") - [" << slot.getWeekday() << "," << slot.getStartHour()  << "-" << slot.getEndHour() <<  "," << slot.getSlotType() << "],";
            }
            std::cout << "\n";
        }
        std::cout << "]\n";
    }

    int i;
    std::cin >> i;
}




