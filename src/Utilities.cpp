//
// Created by ntsayz on 10/20/22.
//


#include "Utilities.h"

Utilities::Utilities() = default;

short Utilities::getInput(short choice, short min, short max)  {

    while(true){
        if(choice == 9) return choice;
        if (std::cin.fail()) {
            std::cerr << "Sorry, I cannot read that. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }else if (choice < min || choice > max) {
            return -1;
        }

        return choice;
    }
}

void Utilities::clear_screen() {
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}
bool Utilities::checkFiles() const {
    //files = [ "schedule/classes.csv" ,"schedule/classes_per_uc.csv", "schedule/students_classes.csv"];
    return false;
}


