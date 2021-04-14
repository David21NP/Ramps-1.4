#ifdef ARDUINO_AVR_MEGA2560
#include "Ramps.h"

Ramps::Ramps(/* args */)
{
}

Ramps::Ramps(int v1, int v2)
{
    val1 = v1;
    val2 = v2;
}

Ramps::~Ramps()
{
}
#endif