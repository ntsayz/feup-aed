//
// Created by ntsayz on 10/21/22.
//

#include "Menu.h"

short Menu::Main() {
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n"; // ---
    std::cout << "|" << std::setfill(' ') << std::setw(50); // | txt
    std::cout << "LEIC'S SCHEDULE MANAGEMENT SYSTEM";
    std::cout << std::setfill(' ') <<std::setw(9)<<"|\n"  //  --> |
              << "|"<< std::setfill('-') <<std::setw(59) <<"|\n"; // ---
    std::cout << std::setfill(' ') << std::setw(47) << " Choose one of the following options:\n\n";
    std::cout << std::setfill(' ')<<  std::setw(36) << "1. Listings\n"
              << std::setw(33) << "2. ---\n" <<
              std::setw(33) << "3. ---\n";
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
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n"; // ---
    std::cout << "|" << std::setfill(' ') << std::setw(35); // | txt
    std::cout << "LISTINGS";
    std::cout << std::setfill(' ') <<std::setw(24)<<"|\n"  //  --> |
              << "|"<< std::setfill('-') <<std::setw(59) <<"|\n"; // ---
    std::cout << std::setfill(' ') << std::setw(49) << " Choose one of the following options:\n\n";
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
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n"; // --
    std::cout << "|" << std::setfill(' ')<< std::setw(30); std::cout << " 9.Back" << std::setw(29) << "|\n";
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n";

    short choice;
    std::cout << "-->" << std::flush;
    std::cin >> choice;
    choice = Utility::getInput(choice, (short)1, (short )4);
    return choice;

}

short Menu::studentsListings() {
    Utility::clear_screen();
    std::cout << "LISTINGS > *STUDENTS* \n";
    std::cout << std::setfill('-')<<  std::setw(28) << "STUDENTS" << std::setw(31) << "\n";
    std::cout << std::setfill(' ') <<std::setw(36) << "group them by:" << std::setw(23) << "\n";
    std::cout << std::setfill(' ')<<  std::setw(36) << "1. Classes\n"
              << std::setw(33) << "2. Year\n" <<
              std::setw(33) << "3. UCs\n"
              << std::setw(33) << "4. Schedules\n"
              << std::setw(33) << "5.Go Back\n";
    short choice;
    std::cout << "-->" << std::flush;
    std::cin >> choice;
    choice = Utility::getInput(choice, (short)1, (short )5);
    return choice;
}



bool Menu::studentsListings_Class(std::set<Student> students,std::set<Class> classes, bool session) {
    Utility::clear_screen();
    std::cout << "LISTINGS > STUDENTS > *CLASSES*\n";
    std::cout << "From what year (1-3)?" << std::setfill(' ') << std::setw(30) << "0 to Exit\n";;
    int year;
    std::cout << "-->" << std::flush;
    std::cin >> year;
    year = Utility::getInput((short)year, (short)0, (short )3);
    if(year >= 1 && year <= 3){
        Utility::clear_screen();
        std::cout << "LISTINGS > STUDENTS > *CLASSES*\n";
        for(Class turma: classes){
            if(turma.getClassCode().substr(0,0) == std::to_string(year).substr(0,0))
                std::cout << turma.getClassCode() << "\n";
        }
        while(session){
            //
            std::cout << "LISTINGS > STUDENTS > *CLASSES*\n\n";
            std::cout << "\nFrom what class  (1-"<< classes.size()/3 + 1  << ")?" << std::setfill(' ') << std::setw(30) << "0 to Exit\n";
            int turma;
            std::cout << "-->" << std::flush;
            std::cin >> turma;
            turma = Utility::getInput((short)turma, (short)0, (short )classes.size()/3+1);
            if(turma > 0 && turma < 16){
                for(Class aClass: classes){
                    aClass.showStudents();
                    std::cout << "\n\n--------\n\n";
                }
            }
            if(turma == 0) session = false;
            Utility::clear_screen();
        }
    }else if(year == 0) session = false;
    return session;
}

void Menu::classesListings() {

}

void Menu::UCListings() {

}

void Menu::schedulesListings() {

}
