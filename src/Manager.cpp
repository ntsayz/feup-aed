//
// Created by ntsayz on 10/8/22.
//

#include "Manager.h"

Manager::Manager() {
    session = true;
}

void Manager::startApplication(){

    while(session) {
        Utilities::clear_screen();
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
    std::cout << "|                      "; std::cout << " 0. Exit   ";   std::cout << "                      |\n"
        << "-----------------------------------------------------------\n\n";

    short choice;
    std::cout << "-->" << std::flush;
    std::cin >> choice;
    choice = utils.getInput(choice, (short)0,(short )3);
    return choice;
}




