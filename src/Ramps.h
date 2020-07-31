#ifndef Ramps_h
#define Ramps_h

#include "./I2C/I2C_Ramps.h"
#include "./Stepper/Steppers.h"
#include "./Eeprom/Eeprom.h"
#include "./Events/Event.h"

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