#include "Power_Output.h"

Power_Output::Power_Output()
{
    outputs[0] = POWER_O_1;
    outputs[1] = POWER_O_2;
    outputs[2] = POWER_O_3;
}

Power_Output::~Power_Output()
{
}

void Power_Output::begin()
{
    pinMode(POWER_O_1, OUTPUT);
    pinMode(POWER_O_2, OUTPUT);
    pinMode(POWER_O_3, OUTPUT);
}

void Power_Output::setOutputTo(uint8_t out, uint8_t value)
{
    if(out < 3)
    {
        analogWrite(outputs[out], map(value, 0, 100, 0, 255));
    }
}