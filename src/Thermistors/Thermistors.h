#ifndef Thermistors_h
#define Thermistors_h

#include "../util/pch.h"

class Thermistors
{
private:
    uint8_t thermPin[3];
public:
    Thermistors();
    ~Thermistors();

    int getOutputOf(uint8_t therm);
};

#endif