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
    std::string weekdaystr;
    float startHour, endHour,duration;
    std::string type;
    unsigned short getNum();
public:
    /// Constructor
    Slot(std::string weekdaystr,float startHour,float duration,std::string type);
    void loadClassesData();
    ///really?
    std::string getWeekday();
    bool operator<(const Slot& slot){
        return this->weekday < slot.weekday;
    }
    bool operator==(const Slot& slot){
        return this->weekday == slot.weekday;
    }
    bool operator>(const Slot& slot){
        return this->weekday == slot.weekday;
    }
};

/*
 * map<uc,<map<Class,list<Slot>>> schd;
 *
 * map<Class,list<Uc>> ucclasses;
 *
 * // get horario de uma turma
 *
 * // lista de associadas a turma
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
