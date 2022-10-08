//
// Created by ntsayz on 10/8/22.
//

#include "Manager.h"

Manager::Manager() {
    session = true;
}

void Manager::startApplication(){

    while(session) {
        clear_screen();
        int choice = mainMenu();
        switch (choice) {
            case 0:
                session = false;
                break;
            case 1:
                std::cout << "1";
                break;
            case 2:
                std::cout << "2";
                break;
            case 3:
                std::cout << "3";
                break;
        }
    }

}


int Manager::mainMenu() {
    std::cout << "-----------------------------------------------------------\n"
         << "|             ";; std::cout << "LEIC'S SCHEDULE MANAGEMENT SYSTEM "; std::cout << "         | \n"
         << "-----------------------------------------------------------\n"
         << "|                       ";std::cout << "::WELCOME::";  std::cout << "                       |\n";
     std::cout << "-----------------------------------------------------------\n";
     std::cout << "   Choose one of the following options:\n\n";
     std::cout << std::setw(36) << "1. Register\n"
            << std::setw(33) << "2. Login\n" <<
            std::setw(33) << "3. Guest\n";
     std::cout << "-----------------------------------------------------------\n";
    std::cout << "|                      "; std::cout << " 0. Close ";   std::cout << "                      |\n"
        << "-----------------------------------------------------------\n\n";

    short choice;
    std::cout << "-->" << std::flush;
    std::cin >> choice;
    choice = getInput(choice, 0,3);
    return choice;
}



int Manager::getInput(short choice, short min, short max)  {

    while(true){

        if (std::cin.fail()) {
            std::cerr << "Sorry, I cannot read that. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice < min || choice > max) {
            std::cerr << "Sorry, the number is out of range." << std::endl;
            return -1;
        }

        std::cout << "You have entered " << choice << ". Thank you!" << std::endl;
        return choice;
    }
}

void Manager::clear_screen() const {
    #ifdef WINDOWS
        std::system("cls");
    #else
        // Assume POSIX
        std::system("clear");
    //std::cout<< u8"\033[2J\033[1;1H" ;
    #endif
}

bool Manager::checkFiles() const {
    //files = [ "schedule/classes.csv" ,"schedule/classes_per_uc.csv", "schedule/students_classes.csv"];
    if(session)return true;
    return false;
}



