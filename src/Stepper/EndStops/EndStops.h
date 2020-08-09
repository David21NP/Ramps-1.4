#ifndef EndStops_h
#define EndStops_h

#include "../util/pch.h"

#define ES_PU INPUT_PULLUP
#define ES_NP INPUT

class EndStops
{
private:
    voidFuncPtr XaxisEvent[2];
    voidFuncPtr YaxisEvent[2];
    voidFuncPtr ZaxisEvent[2];
public:
    EndStops();
    
    ~EndStops();
};


#endif