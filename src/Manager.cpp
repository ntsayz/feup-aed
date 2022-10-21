//
// Created by ntsayz on 10/8/22.
//


#include "Manager.h"

Manager::Manager() {
    session = true;
    loadClasses_UCs();
    loadStudents();
}

void Manager::startApplication(){

    while(session) {
        Utility::clear_screen();
        short choice = Menu::Main();
        switch (choice) {
            case 1:
                Listings();
                break;
            case 2:
                break;
            case 3:
                break;
            case 9:
                session = false;
                break;
            default:
                std::cerr << "That doesn't seem like a valid option..\n";
                break;
        }
    }

}

void Manager::Listings() {
    bool state = true;
    while(state){
        Utility::clear_screen();
        short choice = Menu::Listings();
        switch (choice){
            case 1:
                studentsListings();
                break;
            case 9:
                state = false;
                break;
            default:
                break;
        }

    }

}

void Manager::studentsListings() {
    bool state = true;
    while(state){
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

        switch (choice) {
            case 1:{
                bool st = true;
                while(st){
                    Utility::clear_screen();
                    std::cout << "LISTINGS > STUDENTS > *CLASSES*\n";
                    std::cout << "From what year (1-3)?" << std::setfill(' ') << std::setw(30) << "0 to Exit\n";;
                    int year;
                    std::cout << "-->" << std::flush;
                    std::cin >> year;
                    year = Utility::getInput((short)year, (short)0, (short )3);
                    if(year >= 1 || year >= 3){
                        Utility::clear_screen();
                        std::cout << "LISTINGS > STUDENTS > *CLASSES*\n";
                        for(Class turma: classes){
                            if(turma.getClassCode()[0] == std::to_string(year)[0])
                            std::cout << turma.getClassCode() << "\n";
                        }
                        while(st){
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
                            if(turma == 0) st = false;
                            //Utility::clear_screen();
                        }
                    }else if(year == 0) st = false;
                }
                break;
            }
            case 2:
                break;

            case 5:
                state = false;
                break;
        }
    }
}

void Manager::loadStudents()
{

    std::cout << this->classes.size();
    std::vector<std::string> vec;
    const char *fname = Utility::getStudentClassesPath();
    FILE *file = fopen(fname, "r");
    if(!file)
    {
        std::cerr << ("Could not open the file\n");
    }
    char content[1024];
    int c = 0 ;
    while(fgets(content, 1024, file))
    {
        c++;

        char *v = strtok(content, ",");
        int c1 = 0;
        while(v)
        {
            c1++;
            std::string s = v;
            if(c>1 && s.size() >1){
                vec.push_back((std::string)s);
            }
            v = strtok(NULL, ",");
        }

        if(c>1){
            Uc uc(vec[2]);
            Class aClass(vec[3]);
            Student student(vec[0],vec[1],uc,aClass);
            aClass.addStudent(student);
            classes.insert(aClass);
            students.insert(student);
            curricularUnits.insert(uc);
            //for(Class turma: classes){
                //if(turma == aClass) std::cout << "class\n";
            //}

        }
        vec.clear();
    }

    fclose(file);

}

//loads classes and UCs
void Manager::loadClasses_UCs() {

    std::ifstream filename(Utility::getClassesUcPath());
    // Make sure the file is open
    if(!filename.is_open()) throw std::runtime_error("Could not open file");\
    std::string line, colname;
    std::string val,val1,val2,val3;

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

            Uc uc = (line.substr(0,7));

        }
        filename.close();

/*
 *
 *
 * for(Class aClass1: classes){
        std::cout << aClass1.getClassCode() << "\n";
    }
        std::ifstream filename(Utility::getStudentClassesPath());
        // Make sure the file is open
        if(!filename.is_open()) throw std::runtime_error("Could not open file");


        // Read the column names
        if(filename.good()) {
            // Extract the first line in the file
            std::getline(filename, line);

            // Create a stringstream from line
            std::stringstream ss(line);

            // Extract each column name
            while (std::getline(ss, colname, ',')) {

            }
            int c = 0;
            while (std::getline(filename, line,',')) {
                //std::cout << line.substr(0,8) << "\n";
                //Student student = (line.substr(0,8),line.substr());
                std::stringstream ss(line);
                while(ss >> val){
                    std::cout << val << " ";
                    //Student();
                    c++;
                }
                std::cout << "\n";
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
        */
    }
}






