////
// Created by Eriton Naife on 10/17/22.
//


#ifndef FEUP_AED_MANAGER_H
#define FEUP_AED_MANAGER_H
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>


class Uc 
{
private:
	std::string uc_Code, class_Code;
public:
	//Uc default constructor
	Uc();

	//Uc constructor
	Uc(std::string uc_Code, std::string class_Code);
	
	//set uc_Code
	void setUc_Code(std::string uc_Code);
	
	//set class_code
	void setClass_Code(std::string class_Code);

	//returns uc_Code
	std::string getUc_Code() const;
	
	//returns class_Code
	std::string getClass_Code() const;
};

class Schedule: public Uc {

private:
	std::string weekday, class_Type;
	float start_Hour, duration;
public:
	//default constructor
	Schedule();

	//Schedule constructor
	Schedule(std::string class_Code, std::string uc_Code, std::string weekday,float start_hour,float duration,std::string class_Type);

	//Set weekday
	void setWeekday(std::string weekday);

	//Set class type
	void setClass_Type(std::string class_Type);
	
	//Set start hour
	void setStart_Hour(float start_Hour);

	//Set class duration
	void setDuration(float duration);

	//Get weekday
	std::string getWeekday() const;

	//Get class type
	std::string getClass_Type() const;

	//Get start hour
	float getStart_Hour() const;

	//Get duration
	float getDuration() const;	
};

class Students: public Uc{
private:
	int student_Code;
	std::string student_Name;
public:
	//default constructor
	Students();

	//Student constructor
	Students(int student_Code, std::string student_Name, std::string uc_Code, std::string class_Code);
	
	//Set student Code
	void setStudent_Code(int student_Code);
	
	//Set student name
	void setStudent_Name(std::string student_Name);
	
	//Get student code
	int getStudent_Code() const;
	
	//Get student name
	std::string getStudent_Name() const;

};


#endif //F//FEUP_AED_MANAGER_H