//
// Created by Eriton Naife on 08/10/2022.
//

#ifndef FEUP_AED_UC_H
#define FEUP_AED_UC_H
#include <string>
#include <vector>

class Uc {
protected:
    std::string uc_Code,class_Code;
public:
    //default constructor
    Uc();

    //Uc constructor
    Uc(std::string uc_Code,std::string class_Code);

    //set UcCode
    void set_uc_Code(std::string uc_Code);

    //return UcCode
    std::string get_uc_Code() const;
};

class schedule:
        public Uc
        {
        private:
            std::string weekday,type;
            int duration,startHour;
        public:

            schedule();


            schedule(std::string class_Code,std::string uc_Code,std::string weekday,
                     int startHour,int duration,std::string type);

            void set_weekday(std::string weekday);
            std::string get_weekday() const;

            void set_type(std::string type);
            std::string get_type() const;

            void set_duration(int duration);
            int get_duration() const;

            void set_startHour(int startHour);
            int get_startHour() const;
};


#endif //FEUP_AED_UC_H
