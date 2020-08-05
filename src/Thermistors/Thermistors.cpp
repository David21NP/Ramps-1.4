#include "Thermistors.h"

Thermistors::Thermistors()
{
    thermPin[0] = THERM0;
    thermPin[1] = THERM1;
    thermPin[2] = THERM2;
}

Thermistors::~Thermistors()
{
}

int Thermistors::getOutputOf(uint8_t therm)
{
    if(therm < 3)
    {
        return analogRead(thermPin[therm]);
    }
    return 0;
}