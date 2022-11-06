//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_SLOT_H
#define FEUP_AED_SLOT_H
#include <string>
#include <vector>
class Slot {
private:
    unsigned short weekday;
    std::string uc;
    std::string weekdaystr;
    float startHour, endHour,duration;
    std::string type;
public:
    /// Constructor
    Slot(std::string weekdaystr,float startHour,float duration,std::string type);
    void loadClassesData();
    /// Gets weekday
    std::string getWeekday();
    /// Gets duration of class
    float getDuration();
    /// Gets type of class
    std::string getSlotType();
    /// Gets start hour of class
    float getStartHour();
    ///Auxiliary
    bool operator<(const Slot& slot) const{
        return this->startHour < slot.startHour;
    }
    ///Auxiliary
    bool operator>(const Slot& slot) const{
        return this->startHour > slot.startHour;
    }
    ///Auxiliary
    bool operator==(const Slot& slot) const{
        return this->weekday == slot.weekday && this->startHour == slot.startHour ;
    }
    /// Gets end hour of class
    float getEndHour();
    /// Gets weekday as number
    unsigned short getNum();
    /// Auxiliary
    void setUC(const std::string& basicString);
    /// Auxiliary
    std::string getUC();
};

/*
 * map<uc,<map<Class,list<Slot>>> schd;
 *
 * map<Class,list<Uc>> ucclasses;
 *
 * // get horario de uma turma
 *
 * // lista de ucs associadas a turma
 * lista de ucs = ucclasses[class]
 * // por cada uc na tal lista get slot da uc to print
 * for (uc in lista de ucs)
 *      lista de slots = schd[uc][class]
 *      // do wtv i need to do
 *
*
 *  // get horario de uc (pode ter mais collisions)
 *  (for k,v in vschd[uc])
 *      for slot in v
 *          //do wtv i need to do
*
 *
 *  // get horario de um aluno
 *
 *  aluno por numero mecanografico
 *  for uc,classList studuucclasses[student]
 *      for aClass in schd[uc]:
 *          for slot in schd[uc][class]
 *              // do wtv
 *
 * */


#endif //FEUP_AED_SLOT_H
