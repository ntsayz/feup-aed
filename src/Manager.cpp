//
// Created by ntsayz on 10/8/22.
//

#include <fstream>
#include "Manager.h"

Manager::Manager() {
    session = true;
    loadDataStructures();
}

void Manager::startApplication(){

    while(session) {
        Utility::clear_screen();
        short choice = Menu::Main();
        switch (choice) {
            case 9:
                session = false;
                break;
            case 1:
                Listings();
                session = true;
                break;
            case 2:
                break;
            case 3:
                break;
            default:
                std::cerr << "That doesn't seem like a valid option..\n";
                break;
        }
    }

}

void Manager::Listings() {
    while(session){
        Utility::clear_screen();
        short choice = Menu::Listings();
        switch (choice){
            case 1:
                studentsListings();
                break;
            case 9:
                session = false;
                break;
            default:
                break;
        }

    }

}

void Manager::studentsListings() {
    while(true){
        Utility::clear_screen();
        std::cout << "LISTINGS > *STUDENTS* \n";
        std::cout << std::setw(28) << "STUDENTS" << std::setw(31) << "\n";
        std::cout << std::setfill(' ') <<std::setw(36) << "group them by:" << std::setw(23) << "\n";
        std::cout << std::setfill(' ')<<  std::setw(36) << "1. Classes\n"
                  << std::setw(33) << "2. Year\n" <<
                  std::setw(33) << "3. UCs\n"
                  << std::setw(33) << "4. Schedules\n"
        << std::setw(33) << "5.Go back to Listings\n";

        short choice;
        std::cout << "-->" << std::flush;
        std::cin >> choice;
        choice = Utility::getInput(choice, (short)1, (short )4);

        switch (choice) {
            case 1:
                while(true){
                    Utility::clear_screen();
                    std::cout << "LISTINGS > STUDENTS > *CLASSES*\n";
                    std::cout << "From what year (1-3)?\n";
                    int year;
                    std::cout << "-->" << std::flush;
                    std::cin >> year;
                    year = Utility::getInput((short)year, (short)1, (short )3);
                    if(year >= 1 || year >= 3){
                        Utility::clear_screen();
                        std::cout << "LISTINGS > STUDENTS > *CLASSES*\n";
                        for(Class turma: classes){
                            if(turma.getClassCode()[0] == std::to_string(year)[0])
                            std::cout << turma.getClassCode() << "\n";
                        }
                        while(true){
                            //
                            std::cout << "LISTINGS > STUDENTS > *CLASSES*\n";
                            std::cout << "\nFrom what class (1-"<< classes.size()/3 +1<<")?\n";
                            int turma;
                            std::cout << "-->" << std::flush;
                            std::cin >> turma;
                            turma = Utility::getInput((short)turma, (short)1, (short )classes.size()/3+1);
                            Utility::clear_screen();
                        }
                    }

                }
                break;
            case 2:
                break;
        }
    }
}

void Manager::loadDataStructures() {

    std::ifstream filename(Utility::getClassesUcPath());
    // Make sure the file is open
    if(!filename.is_open()) throw std::runtime_error("Could not open file");\
    std::string line, colname;
    std::string val;

    // Read the column names
    if(filename.good())
    {
        // Extract the first line in the file
        std::getline(filename, line);

        // Create a stringstream from line
        std::stringstream ss(line);

        // Extract each column name
        while(std::getline(ss, colname, ',')){

        }
        while(std::getline(filename, line))
        {
            Class aClass = (line.substr(9,15) );
            classes.insert(aClass);
            Uc uc = (line.substr(0,7));
            curricularUnits.insert(uc);
        }
        filename.close();



        std::ifstream filename(Utility::getStudentClassesPath());
        // Make sure the file is open
        if(!filename.is_open()) throw std::runtime_error("Could not open file");\

        // Read the column names
        if(filename.good()) {
            // Extract the first line in the file
            std::getline(filename, line);

            // Create a stringstream from line
            std::stringstream ss(line);

            // Extract each column name
            while (std::getline(ss, colname, ',')) {

            }
            while (std::getline(filename, line)) {
                //std::cout << line.substr(0,8) << "\n";
                //Student student = (line.substr(0,8),line.substr());
                std::stringstream ss(line);
                while(ss >> val){
                    std::cout << val << "\n";
                    if(ss.peek() == ',') ss.ignore();
                }
            }
            filename.close();

        }



        std::fstream fin;

        // Open an existing file
        fin.open(Utility::getStudentClassesPath(), std::ios::in);

        std::string word , tmp;
        int code;

        while(fin >> tmp){
            getline(fin,line);
            std::stringstream s(line);
            //std::cout << line << "\n";
            int c = 0;
            while(getline(s,word,',')){
                //if(c == 2) std::cout << (std::string) word << "\n";
                c++;
            }

        }


    }



}


