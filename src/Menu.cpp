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
    std::cout << "|" << std::setfill(' ')<< std::setw(30); std::cout << " 9.Close" << std::setw(29) << "|\n";
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
    std::cout << std::setfill(' ') << std::setw(47) << " Choose one of the following options:\n\n";
    std::cout << std::setfill(' ')<<  std::setw(36) << "1.By Students\n"
              << std::setw(33) << "2.By Classes\n" <<
              std::setw(33) << "3.By UCs\n"
              << std::setw(33) << "4.By Schedules\n";
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n"; // --
    std::cout << "|" << std::setfill(' ')<< std::setw(30); std::cout << " 9.Back" << std::setw(29) << "|\n";
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n";

    short choice;
    std::cout << "-->" << std::flush;
    std::cin >> choice;
    choice = Utility::getInput(choice, (short)1, (short )4);
    return choice;

}