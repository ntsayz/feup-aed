//
// Created by Eriton Naife on 08/10/2022.
//

#include "Uc.h"
Uc::Uc(){

}
Uc::Uc(std::string uc_Code) {
    this->uc_Code = uc_Code;
}


Uc::Uc(std::string uc_Code,std::string class_Code){
	this->uc_Code = uc_Code;
	this->class_Code = class_Code;
}

void Uc::set_uc_Code(std::string uc_Code){
	this->uc_Code=uc_Code;
}

std::string Uc::get_uc_Code() const{
	return this->uc_Code;
}

void Uc::set_class_Code(std::string class_Code){
		this->class_Code=class_Code;
}

std::string Uc::get_class_Code()const{
	return class_Code;

}


