//
// Created by ntsayz on 10/20/22.
//

#ifndef FEUP_AED_UTILITIES_H
#define FEUP_AED_UTILITIES_H
#include <iostream>

class Utilities {
private:

public:
    Utilities();
    /// Gets and sanitizes user's input
    static short getInput(short choice, short min, short max);
    /// Clear screen (Cross-Platform)
    static void clear_screen() ;
    /// Make sure that all files exist before starting program
    [[nodiscard]] bool checkFiles() const;




};


#endif //FEUP_AED_UTILITIES_H
