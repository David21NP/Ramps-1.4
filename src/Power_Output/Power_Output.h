#ifndef Power_Output_h
#define Power_Output_h

#include "../util/pch.h"

class Power_Output
{
private:
    uint8_t outDictionary[3];
public:
    Power_Output();
    ~Power_Output();

    void setOutputTo(uint8_t out, int value);
};


#endif