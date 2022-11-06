//
// Created by ntsayz on 10/20/22.
//



#include "Utility.h"

using namespace std;
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


const char* Utility::getClassesPath() {
    return "../src/schedule/classes.csv";
}

const char* Utility::getClassesUcPath() {
    return "../src/schedule/classes_per_uc.csv";
}

const char* Utility::getStudentClassesPath() {
    return "../src/schedule/students_classes.csv";
}
void Utility::header(const std::string& title){
    int n = (int)(title.size() + 59) / 2;
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n"; // ---
    std::cout << "|" << std::setfill(' ') << std::setw(n); // | txt
    std::cout << title;
    std::cout << std::setfill(' ') <<std::setw(59 -n)<<"|\n"  //  --> |
              << "|"<< std::setfill('-') <<std::setw(59) <<"|\n";
}

void Utility::footer() {
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n"; // --
    std::cout << "|" << std::setfill(' ')<< std::setw(33) << "0.Back  " << std::setw(26) << "|\n";
    std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n";
    //std::cout << "-->";
}

void Utility::body(const std::string& description, std::vector<std::string> options){
    int n = (int)(description.size() + 59) / 2;
    std::cout << "|" << std::setfill(' ') << std::setw(n) << description;
    std::cout << std::setfill(' ') <<std::setw(59- n)<<"|\n";
    std::cout << "|" << std::setfill(' ') <<std::setw(59) << "|\n";
    for(int i =0; i < options.size(); i++){
        int k = (int)(options[i].size() + 59) / 2;
        std::cout << "|" << std::setfill(' ') << std::setw(k) << options[i] << std::setw(59 - k) << "|\n";
    }

}
void Utility::path(std::string path){
    int n = (int)(59 - path.size());
    //std::cout << "|" << std::setfill('-') <<std::setw(59) << "|\n"; // ---
    std::cout << "|" << path;
    std::cout << std::setfill(' ') <<std::setw(n)<<"|\n"  //  --> |
              << "|"<< std::setfill('-') <<std::setw(59) <<"|\n";
}

void bubbleSort(vector<Slot>& arr, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j].getStartHour() > arr[j + 1].getStartHour())
                swap(arr[j], arr[j + 1]);
}
void Utility::scheduleHeader(std::string title){
    int n = (int)(title.size() + 120) / 2;
    std::cout << "|" << std::setfill('-') <<std::setw(120) << "|\n"; // ---
    std::cout << "|" << std::setfill(' ') << std::setw(n); // | txt
    std::cout << title;
    std::cout << std::setfill(' ') <<std::setw(120 -n)<<"|\n"  //  --> |
              << "|"<< std::setfill('-') <<std::setw(120) <<"|\n";
}
void Utility::scheduleFooter() {
    std::cout << "|" << std::setfill('-') <<std::setw(120) << "|\n"; // --
    std::cout << "|" << std::setfill(' ')<< std::setw(64) << "0.Back  " << std::setw(56) << "|\n";
    std::cout << "|" << std::setfill('-') <<std::setw(120) << "|\n";
    std::cout << "-->";
}
template<typename T>
vector<Slot> mergeSort(vector<Slot>::iterator begin, vector<Slot>::iterator end) {
    auto n = end - begin;
    if (n < 2) {
        return vector<Slot>(begin, end);
    }
    auto firstHalf  = mergeSort<vector<Slot>>(begin, begin + n/2);
    auto secondHalf = mergeSort<vector<Slot>>(begin + n/2, end);

    T merged;

    std::merge(firstHalf.begin(), firstHalf.end(),
               secondHalf.begin(), secondHalf.end(),
               std::back_inserter(merged));
    return merged;
}


void Utility::schedule(std::string descriptor, std::map<Uc,std::vector<Slot>> slots){
    clear_screen();
    scheduleHeader(descriptor);
    std::cout << "|" << std::setfill(' ') << std::setw(12) << "Time" << std::setw(8) << "|" << std::setw(12) << "Monday"
              << setw(8) << "|" << setw(12) << "Tuesday" << setw(8) << "|" << setw(14) << "Wednesday" << setw(6) << "|" << setw(13) << "Thursday" << setw(7) << "|" << setw(11) << "Friday" << setw(9) << "|\n";
    std::cout << std::setfill('-');
    for (int i = 0; i <= 6; i++)
    {
        if(i == 6) break;
        std::cout << "|"  << std::setw(20);
    }
    std::cout << "|\n";
    vector<Slot> slots1;
    for (auto& [k, v] : slots)
    {
        for (auto& slot : v)
        {
            slot.setUC(k.get_uc_Code());
            slots1.push_back(slot);
        }
    }
    std::vector<Slot> slot2 = mergeSort<vector<Slot>>(slots1.begin(),slots1.end());

    //bubbleSort(slots1,slots1.size());
    int i = 1;

    for (auto slot: slot2){
        std::cout << "|" << std::setfill(' ') << std::setw(8) << std::to_string(slot.getStartHour()).substr(0,4) << "-" << std::to_string(slot.getEndHour()).substr(0,4) << setw(7);

        for (int i = 1; i <= 5; i++)
        {
            if(i == slot.getNum()){
                std::cout << "|" << std::setw(12) << slot.getUC() << "("<<  slot.getSlotType() << ")"<< std::setw(5);
            }else{
                std::cout << "|" << std::setw(20);
            }

        }
        std::cout << "|\n|";
        std::cout << setfill('-') << setw(120) << "|\n";
    }
    for(auto slot: slot2){
        std::cout << slot.getUC() << " - " << slot.getSlotType()  << " - " << slot.getStartHour() << " - " << slot.getEndHour() << "\n";
    }
    scheduleFooter();
}
void Utility::print_uc_students_table(std::multimap<std::string,std::string> m){
    std::cout <<"|" << std::setfill(' ') << std::setw(22)<< "Curricular Unit" << setw(7) << "|" <<  std::setw(17) << "Name" << std::setw(13) << "|\n";
    for(auto [k,v]: m){
        if(v[0] == '1' || v[0] == '2' || v[0] == '3'){
            std::cout << "|" << setfill(' ') << setw(19) << v << setw(11) << "|" << setw(20)<< k  << setw(9)<< "|\n" ;
        }else{
            std::cout << "|" << setfill(' ') << setw(19) << k << setw(11) << "|" << setw(20)<< v  << setw(9)<< "|\n" ;
        }

    }
}
void Utility::print_students(const std::set<Student>& sets){
    for(auto students: sets){
        std::cout << "|" << setfill(' ') << setw(25) << students.getName() << " (" << students.getCode() << ")" << setw(22) << "|\n";
    }
}

int Utility::getCode(int code) {
    while(true){
        if (std::cin.fail()) {
            std::cerr << "Sorry, I cannot read that. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }else if (code <= 0) {
            return -1;
        }

        return code;
    }
}

std::string Utility::stringInput(std::string s) {
    char c = s[0],c1 = 'L',c2 = '1',c3 = '2',c4 = '3';
    if (c != c1 || c != c2 || c != c3 || c != c4){
        std::cerr << "Sorry, I cannot read that. Please try again." << std::endl;
        return "";
    }
    else
        return s;
}




