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
        i = Utility::getInput(i,0,4);
        if(i >=1 && i <= 4){
            set<Student> student_set;
            for(auto [student,v]: students){
                for(auto [uc,vec]: v){
                    for(auto aclass: vec){
                        if(aclass.getClassYear() == i){
                            student_set.insert(student);
                        }else if( i == 4){
                            student_set.insert(student);
                        }
                    }
                }
            }
            Utility::clear_screen();

            std::string s = "Year " + to_string(i) ;
            if(i== 4){
                s = "All course";
            }

            Utility::header(s);
            Utility::print_students(student_set);
            Utility::body("Order them in:",{"1. Alphabetical order"});
            Utility::footer();
            std::cin >> i;
            if(i == 0){localSession = false;
                continue;};
            if(i ==1){
                std::set<std::string> studset;
                std::multimap<std::string,std::string> m;
                for(auto students : student_set){
                    m.insert(std::pair{students.getName(), to_string(students.getCode())});
                }
                Utility::clear_screen();
                Utility::header(s);
                for(auto [students,code]: m){
                    std::cout << "|" << setfill(' ') << setw(25) << students << " (" << code << ")" << setw(22) << "|\n";
                }
                Utility::footer();
                std::cin >> i;
                if(i == 0){continue;};

            }
        }
        if(i == 0) localSession = false;

    }
}
void Menu::studentsListings_UC(map<Student, map<Uc, std::vector<Class>>>& students, std::map<Uc,std::vector<Class>>& uc_classes) {
    bool localSession = true;
    while(localSession){
        Utility::clear_screen();
        std::map<Uc,std::set<Student>> mm;

        Utility::path("listings/students/UC");
        Utility::header("Curricular Units");
        Utility::body("Show students in a:",{"1. UC - Filter by Year",
                                             "2. UC - Order by year","3. UC - Order by Nr of UCs "});
        Utility::footer();
        int i;
        std::cin >> i;
        i = Utility::getInput((short)i,0,3);
        switch(i){
            case 1:
                Utility::clear_screen();
                Utility::header("UCs");
                Utility::body("Filter by year:",{"1. 1st","2. 2nd","3. 3rd"});
                Utility::footer();
                std::cin >> i;
                i = Utility::getInput((short)i,0,3);
                if(i >=1 && i <=3){
                    for(auto [student,v]: students){
                        for(auto [uc,vec]: v){
                            for(const auto& aclass: vec){
                                if(aclass.getClassYear() == i){
                                    mm[uc].insert(student);
                                }
                            }
                        }
                    }
                    std::string s = "UCs filtered by Year " + to_string(i);
                    Utility::header(s);
                    int nrStudents = 0;
                    for(auto [uc,studset]: mm){
                        std::cout << "\n|" << setfill('=') << setw(33) << uc.get_uc_Code() << setw(26) << "|\n";
                        std::cout << "|" << setfill(' ') << setw(38) << "No of Students: " << studset.size() << setw(20) << "|\n\n";
                        for(const auto& student : studset){
                            std::cout << "|" << setfill(' ') << setw(25) << student.getName() << " (" << student.getCode() << ")" << setw(22) << "|\n";
                        }

                    }

                    Utility::footer();
                    std::cin >> i;
                    mm.clear();
                    if(i == 0){continue;};
                }if(i == 0) continue;
                break;
            case 2:{
                std::set<int> years;
                for(auto [student,v]: students){
                    for(auto [uc,vec]: v){
                                mm[uc].insert(student);
                    }
                }
                Utility::header("UCs order by Year");
                for(auto [uc,studset]: mm){
                    std::cout << "\n|" << setfill('=') << setw(33) << uc.get_uc_Code() << setw(26) << "|\n";
                    std::cout << "|" << setfill(' ') << setw(38) << "No of Students: " << studset.size() << setw(20) << "|\n\n";
                    for(const auto& student : studset){
                        std::cout << "|" << setfill(' ') << setw(25) << student.getName() << " (" << student.getCode() << ")" << setw(22) << "|\n";
                    }

                }
                Utility::footer();
                std::cin >> i;
                mm.clear();
                if(i == 0){continue;};}
                break;
            case 3:{
                std::map<Student,int> sizeofUCs;
                for(auto [student,v]: students){
                    for(auto vr: v){
                        sizeofUCs[student] +=1;
                    }
                }
                Utility::header("Students (Number of UCs) -Ordered");
                std::multimap<int,Student> sizeofUcs1;
                for(auto [k,v] : sizeofUCs){
                    sizeofUcs1.insert(std::pair{v,k});
                }
                for(auto [nr, stud]: sizeofUcs1){
                    std::cout << "|" << setfill(' ') << setw(25) << stud.getName() << " (" << stud.getCode() << ") - " << nr << setw(18) << "|\n";
                }
                std::string k = std::to_string(sizeofUCs.size());
                Utility::body(k,{""});
                Utility::footer();
                std::cin >> i;
                mm.clear();
                if(i == 0){continue;};
            }
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

void Menu::schedulesListings(std::map<Uc,std::map<Class,std::vector<Slot>>> schedules,std::set<Class> classes,std::map<Class,std::vector<Uc>> classes_uc,std::map<Student,std::map<Uc,std::vector<Class>>> students_uc_classes, int choice) {
    bool localSession = true;
    while(localSession){
        switch(choice){
            case 1:
                // Students
                Utility::clear_screen();
                Utility::header("STUDENTS SCHEDULES");
                Utility::body("",{"1. Student's code","2. Students name (Not finished)"});
                Utility::footer();
                int j;
                std::cin >> j;

                if(j == 1){
                    bool local = true;
                    while(local){
                        Utility::clear_screen();
                        Utility::header("STUDENTS SCHEDULES");
                        Utility::body("Enter the student's code",{"200000000 - 299999999"," working 2example:.202041722"});
                        Utility::footer();
                        std::cin >> j;
                        if(j >= 200000000 &&  j <= 299999999){
                            bool found = false;
                            map<Uc,vector<Slot>> ucslots;
                            std::string studentsid = "";
                            for( auto [stud, ucmap]: students_uc_classes){
                                if(stud.getCode() == j){
                                    found = true;
                                    studentsid += "(" + std::to_string(stud.getCode()) +") " + stud.getName() + "'s";
                                    for(auto [uc,classList] : ucmap){
                                        for(auto aclass:classList){
                                            for(auto slot: schedules[uc][aclass]){
                                                ucslots[uc].push_back(slot);
                                            }
                                        }
                                    }
                                }
                            }

                            studentsid += " SCHEDULE";
                            Utility::clear_screen();
                            Utility::schedule(studentsid,ucslots);
                            int i;
                            std::cin >> i;
                            if(i == 0) local = false;
                            ucslots.clear();
                            if(!found){
                                std::cerr << "Sorry, I haven't found that student code, try again";
                                Utility::footer();
                                std::cin >> j;
                                continue;
                            }
                        }else if(j ==0){local = false;}
                        else{
                            std::cerr << "Sorry that number isn't valid";
                            Utility::footer();
                            std::cin >> j;
                            continue;
                        }
                    }

                }
                if(j == 0){localSession = false;}
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
                        int i;
                        std::cin >> i;
                        if(i == 0){local = false;localSession = false;
                            continue;}
                    }else{
                        //Utility::header("looks like something went wrong..");
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

short Menu::Requests() {
    return 0;
}



