//
// Created by ntsayz on 10/21/22.
//

#include "Menu.h"
#include <bits/stdc++.h>
using namespace std;

short Menu::Main() {
    Utility::header("LEIC'S MANAGEMENT SYSTEM");
    Utility::body("Choose one of the following options:",{ "1. Listings", "2. Requests", "3. TODO"});
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n"; // --
    std::cout << "|" << std::setfill(' ')<< std::setw(32); std::cout << "9.Close" << std::setw(27) << "|\n";
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n";

    short choice;
    std::cout << "-->" << std::flush;
    std::cin >> choice;
    choice = Utility::getInput(choice, (short)1, (short )3);
    return choice;
}

short Menu::Listings() {
    Utility::header("LISTINGS");
    std::cout << std::setfill(' ') << std::setw(49) << "Choose one of the following options:\n\n";
    std::cout <<  std::setw(36) << "1. Students\n"
    <<  std::setw(36) << "- Classes\n"
    <<  std::setw(33) << "- Year\n"
     <<  std::setw(31) << "- UC\n"
                << std::setw(35) << "2. Classes\n"
    << std::setw(33) << "- Year\n"
                << std::setw(31) << "3. UCs\n"
              << std::setw(37) << "4. Schedules\n"
    << std::setw(36) << "- Classes\n"
    << std::setw(31) << "- UC\n";
    Utility::footer();

    short choice;
    std::cout << "-->" << std::flush;
    std::cin >> choice;
    choice = Utility::getInput(choice, (short)0, (short )4);
    return choice;

}

//only to show
short Menu::studentsListings() {
    Utility::clear_screen();
    Utility::header("STUDENTS");
    std::cout << std::setfill(' ') <<std::setw(41) << "Show the students in:" << std::setw(18) << "\n";
    std::cout << std::setfill(' ')<<  std::setw(33) << "1. Classes\n"
              << std::setw(32) << "2. Years\n" <<
              std::setw(43) << "3. Curricular Units\n";
    Utility::footer();
    short choice;
    std::cout << "-->" << std::flush;
    std::cin >> choice;
    choice = Utility::getInput(choice, (short)0, (short )3);
    return choice;
}

void Menu::studentsListings_Year(const std::map<Student, std::map<Uc, std::vector<Class>>> &students) {
    bool localSession = true;
    while(localSession){
        Utility::clear_screen();
        Utility::path("listings/students/year");
        Utility::header("Students");
        Utility::body("Show students in:",{"1. 1st Year","2. 2nd Year", "3. 3rd Year" , "4. All years"});
        Utility::footer();

        int i;
        std::cin >> i;
        i = Utility::getInput(i,0,2);
        switch(i){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                localSession = false;
                continue;
            default:
                continue;
        }

    }
}
void Menu::studentsListings_UC(map<Student, map<Uc, std::vector<Class>>>& students) {
    bool localSession = true;
    while(localSession){
        Utility::clear_screen();
        Utility::path("listings/students/UC");
        Utility::header("Curricular Units");
        Utility::body("Show students in a:",{""});
        Utility::footer();

        int i;
        std::cin >> i;
        i = Utility::getInput(i,0,2);
        switch(i){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 0:
                localSession = false;
                continue;
            default:
                continue;
        }
    }
}


bool Menu::studentsListings_Class(const std::map<Student,std::map<Uc,std::vector<Class>>>& students_uc_classes, bool session) {
    Utility::clear_screen();
    //Utility::path("listings/students/classes");
    int year = 0, classnum = 0;
    Manager manager;
    manager.getYearClass(year,classnum);
    if(year!=0 && classnum != 0){

        std::map<Student,Uc> students_uc;
        vector<int> students_list;
        std::string aclassstr = "";
        for(auto [student,mapUCclass]: students_uc_classes){
            for(auto [uc,vec] : mapUCclass){
                for(const auto& aclass : vec){
                    if(aclass.getClassYear() == year && aclass.getClassNr() == classnum){
                        students_uc[student] = uc;
                        aclassstr += aclass.getClassCode();
                    }
                }
            }
        }
        bool localSession = true;
        while(localSession){
            Utility::clear_screen();
            Utility::header(aclassstr.substr(0,7));
            std::cout <<"|" << std::setfill(' ') << std::setw(22)<< "Curricular Unit" << setw(7) << "|" <<  std::setw(17) << "Name" << std::setw(13) << "|\n";
            for(auto [student,uc]: students_uc){
                std::cout << "|" << setfill(' ') << setw(19) << uc.get_uc_Code() << setw(11) << "|" << setw(20)<< student.getName()  << setw(9)<< "|\n" ;
            }
            std::cout << "|\n|Number of students in this class : " << students_uc.size() << setw(22) <<  "|\n";

            Utility::body("Order them by:",{"1.Curricular Unit", "2.Alphabetical Order (names)"});
            Utility::footer();
            int i;
            std::cin >> i;
            i = Utility::getInput(i,0,2);
            switch(i){
                case 1: {
                    std::multimap<std::string,std::string> m;
                    for(auto [k,v] : students_uc){
                        m.insert(std::pair{v.get_uc_Code(),k.getName()});
                    }
                    Utility::clear_screen();
                    Utility::header(aclassstr.substr(0,7));
                    Utility::print_uc_students_table(m);
                    Utility::footer();
                    std::cin >> i;
                    m.clear();
                    if(i == 0) continue;
                    break;
                }
                case 2:
                {
                    std::multimap<std::string,std::string> m;
                    for(auto [k,v] : students_uc){
                        m.insert(std::pair{k.getName(),v.get_uc_Code()});
                    }
                    Utility::clear_screen();
                    Utility::header(aclassstr.substr(0,7));
                    Utility::print_uc_students_table(m);
                    Utility::footer();
                    std::cin >> i;
                    m.clear();
                    if(i == 0) continue;
                    break;
                }
                case 0:
                    session = false;
                    localSession = false;
                    continue;
                default:
                    continue;
            }
        }

    }
    return session;
}


void Menu::classesListings() {
    bool localSession = true;
    while(localSession){
        Utility::clear_screen();
        Utility::header("CLASSES");
        std::cout <<"|" << std::setfill(' ')<<  std::setw(13) << "1st Year" << std::setw(7) << "|" << std::setw(13)<< "2nd Year"
                  << setw(7) << "|" << setw(12) << "3rd Year" << setw(7) <<"|\n";
        std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n";
        // blueprint para schedule
        localSession =false;
    }

}

void Menu::UCListings() {

}

void Menu::schedulesListings(std::map<Uc,std::map<Class,std::vector<Slot>>> schedules,std::set<Class> classes,std::map<Class,std::vector<Uc>> classes_uc, int choice) {
    bool localSession = true;
    while(localSession){
        switch(choice){
            case 1:
                // Students
                Utility::clear_screen();
                Utility::header("STUDENTS SCHEDULES");
                Utility::body("",{"1. Student's name ","2. Student's code"});
                Utility::footer();
                break;
            case 2:{
                // Class schedule
                bool local = true;
                while(local){
                    Utility::clear_screen();
                    Utility::header("CLASSES SCHEDULES");
                    Manager m;
                    int year = 0, classnum = 0;
                    m.getYearClass(year,classnum);
                    if(year!=0 && classnum != 0){
                        vector<Uc> ucs;
                        map<Uc,vector<Slot>> ucslots;
                        std::string s = "";
                        for(auto aclass: classes){
                            if(aclass.getClassYear() == year && aclass.getClassNr() == classnum){
                                ucs = classes_uc[aclass];
                                s+= aclass.getClassCode();
                                for(auto uc : ucs){
                                    for(auto slot: schedules[uc][aclass]){
                                        ucslots[uc].push_back(slot);
                                    }
                                }
                            }
                        }
                        s += " SCHEDULE";
                        // show class schedules
                        Utility::schedule(s,ucslots);
                    }else{
                        Utility::header("looks like something went wrong..");
                        Utility::footer();
                        int i;
                        std::cin >> i;
                        if(i == 0){local = false;localSession = false;}
                        continue;

                    }
                    break;
                }
            }
                break;
            default:
                localSession = false;
        }


    }
}



