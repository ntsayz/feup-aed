//
// Created by ntsayz on 10/21/22.
//

#include "Menu.h"
using namespace std;

short Menu::Main() {
    Utility::header("LEIC'S MANAGEMENT SYSTEM");
    Utility::body({"Choose one of the following options:", "1. Listings", "2. Requests", "3. TODO"});
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
    << std::setw(33) << "- Year\n"
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
    std::cout << std::setfill(' ') <<std::setw(41) << "show the students in a:" << std::setw(18) << "\n";
    std::cout << std::setfill(' ')<<  std::setw(33) << "1. Class\n"
              << std::setw(32) << "2. Year\n" <<
              std::setw(43) << "3. Curricular Unit\n";
    Utility::footer();
    short choice;
    std::cout << "-->" << std::flush;
    std::cin >> choice;
    choice = Utility::getInput(choice, (short)0, (short )3);
    return choice;
}



bool Menu::studentsListings_Class(std::set<Student> students,std::set<Class> classes, bool session) {
    Utility::clear_screen();
    Utility::path("listings/students/classes");
    std::cout << std::setfill(' ') << std::setw(37) << "From what year?\n\n";
    std::cout <<  std::setw(35) << "1. 1st Year\n"
              << std::setw(35) << "2. 2nd Year\n"
              << std::setw(35) << "3. 3rd Year\n";
    Utility::footer();
    int year;
    std::cout << "-->" << std::flush;
    std::cin >> year;
    if(year == 0){session = false;}
    year = Utility::getInput(year, (short)0, (short )3);


    if(year >= 1 && year <= 3){
        while(session){
            Utility::clear_screen();
            std::cout <<  std::setw(30) << "From what class?\n" << std::setfill(' ') << std::setw(60) << "0 to Exit\n";
            int classNumber, i =1;
            for(Class turma: classes){
                if(turma.getClassYear() == year){
                    std::cout << i << ". "<<turma.getClassCode() << "\n";
                    i++;
                }
            }
            Utility::footer();
            i= 0;
            std::cout << "-->" << std::flush;
            std::cin >> classNumber;
            classNumber = Utility::getInput((short)classNumber, (short)0, (short )classes.size() / 3 + 1);
            if(classNumber > 0 && classNumber <= 16){
                for(Class aClass: classes){
                    if(aClass.getClassYear() == year && aClass.getClassNr() == classNumber){
                    aClass.showStudents();
                    std::cout << "\n\n--------\n\n";}
                }
                std::cin >> i;
                session = false;
            }
            if(classNumber == 0) session = false;
            Utility::clear_screen();
        }
    }
    return session;
}


void Menu::classesListings() {
    //TODO: ORDENACOES PARCIAIS
    bool localSession = true;
    while(localSession){
        Utility::clear_screen();
        Utility::header("CLASSES");
        std::cout <<"|" << std::setfill(' ')<<  std::setw(13) << "1st Year" << std::setw(7) << "|" << std::setw(13)<< "2nd Year"
                  << setw(7) << "|" << setw(12) << "3rd Year" << setw(7) <<"|\n";
        std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n";

        localSession =false;
    }

}

void Menu::UCListings() {

}

void Menu::schedulesListings() {

}
