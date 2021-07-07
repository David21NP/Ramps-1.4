#ifndef Thermistors_h
#define Thermistors_h

#include "../util/pch.h"

namespace Ramps_1_4
{
    class Thermistors
    {
    private:
        uint8_t thermPin[3];
    public:
        Thermistors();
        ~Thermistors();

        int getOutputOf(uint8_t therm);
    };
}

#endif