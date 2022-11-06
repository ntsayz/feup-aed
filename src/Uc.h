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
    /// Default constructor
    Uc();

    Uc(std::string uc_Code);
    /// UC constructor
    Uc(std::string uc_Code,std::string class_Code);
    /// Sets UcCode
    void set_uc_Code(std::string uc_Code);
    /// Sets Class Code
    void set_class_Code(std::string class_Code);
    /// Gets UC code
    std::string get_uc_Code() const;
    int getCode() const;
    
    /// Gets Class Code
    std::string get_class_Code() const;
    /// Auxiliary
    bool operator<(Uc uc) const{
        return this->get_uc_Code()< uc.get_uc_Code();
    }
    /// Auxiliary
    bool operator==(Uc uc) const{
        return this->get_uc_Code()== uc.get_uc_Code();
    }



};

#endif //FEUP_AED_UC_H
