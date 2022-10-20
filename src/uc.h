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

#endif //FEUP_AED_UC_H
