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

    Uc(std::string uc_Code);
    //Uc constructor
    Uc(std::string uc_Code,std::string class_Code);

    //set UcCode
    void set_uc_Code(std::string uc_Code);

    //set Class Code
    void set_class_Code(std::string class_Code);

    //return UcCode
    std::string get_uc_Code() const;
    
    //return Class Code
    std::string get_class_Code() const;

    bool operator<(Uc uc) const{
        return get_uc_Code()< get_uc_Code();
    }



};

#endif //FEUP_AED_UC_H
