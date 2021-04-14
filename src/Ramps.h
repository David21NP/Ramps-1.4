#ifdef ARDUINO_AVR_MEGA2560
#ifndef Ramps_h
#define Ramps_h

#include "./util/IRamps.h"

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
#endif