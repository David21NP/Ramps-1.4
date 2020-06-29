#ifndef Ramps_h
#define Ramps_h

#include "./Stepper/Stepper.h"
#include "./Eeprom/Eeprom.h"
#include "./Stepper/Control.h"

class Ramps
{
private:
    int val1;
    int val2;
public:
    Ramps(/* args */);
    Ramps(int, int);
    ~Ramps();
    void aver();
};

#endif