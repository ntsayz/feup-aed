//
// Created by ntsayz on 10/20/22.
//



#include "Utility.h"

Utility::Utility() = default;

short Utility::getInput(short choice, short min, short max)  {

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

void Utility::clear_screen() {
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system("clear");
#endif
}

template<typename T>
T Utility::loadFiles(T file) {

    return nullptr;
}

const char* Utility::getClassesPath() {
    return "../src/schedule/classes.csv";
}

const char* Utility::getClassesUcPath() {
    return "../src/schedule/classes_per_uc.csv";
}

const char* Utility::getStudentClassesPath() {
    return "../src/schedule/students_classes.csv";
}
void Utility::header(const std::string& header){
    int n = (int)(header.size() + 59)/2;
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n"; // ---
    std::cout << "|" << std::setfill(' ') << std::setw(n); // | txt
    std::cout << header;
    std::cout << std::setfill(' ') <<std::setw(59 -n)<<"|\n"  //  --> |
              << "|"<< std::setfill('-') <<std::setw(59) <<"|\n";
}

void Utility::footer() {
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n"; // --
    std::cout << "|" << std::setfill(' ')<< std::setw(33) << "0.Back  " << std::setw(26) << "|\n";
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n";
}

void Utility::body(std::vector<std::string> l){
    int n = (int)(l[0].size() + 59)/2;
    std::cout << "|" << std::setfill(' ') << std::setw(n) << l[0];
    std::cout << std::setfill(' ') <<std::setw(59- n)<<"|\n";
    std::cout << "|" << std::setfill(' ') <<std::setw(59) << "|\n";
    for(int i =1; i < l.size(); i++){
        int k = (int)(l[i].size()+59)/2;
        std::cout << "|" << std::setfill(' ') <<  std::setw(k) << l[i] << std::setw(59 - k) << "|\n";
    }

}
void Utility::path(std::string path){
    int n = (int)(59 - path.size());
    //std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n"; // ---
    std::cout << "|" << path;
    std::cout << std::setfill(' ') <<std::setw(n)<<"|\n"  //  --> |
              << "|"<< std::setfill('-') <<std::setw(59) <<"|\n";
}




