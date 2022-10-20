//
// Created by Eriton Naife on 08/10/2022.
//

#include "Uc.h"
Uc::Uc(){

}

Uc::Uc(std::string uc_Code,std::string class_Code){
	this->uc_Code = uc_Code;
	this->class_Code = class_Code;
}

Uc::void set_uc_Code(std::string uc_Code){
	this->uc_Code=uc_Code;
}

Uc::std::string get_uc_Code() const{
	return uc_Code
}

Uc::void set_class_Code(std::string class_Code){
		this->class_Code=class_Code;
}

Uc::std::string get_class_Code()const{
	return class_Code;

}