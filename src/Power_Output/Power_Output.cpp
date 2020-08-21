#include "Power_Output.h"

Power_Output::Power_Output()
{
    outDictionary[0] = POWER_O_1;
    outDictionary[1] = POWER_O_2;
    outDictionary[2] = POWER_O_3;

    pinMode(POWER_O_1, OUTPUT);
    pinMode(POWER_O_2, OUTPUT);
    pinMode(POWER_O_3, OUTPUT);
}

Power_Output::~Power_Output()
{
}

void Power_Output::setOutputTo(uint8_t out, int value)
{
    if(out < 3)
    {
        analogWrite(outDictionary[out], map(value, 0, 100, 0, 255));
    }
}