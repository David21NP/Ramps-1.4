#ifndef EndStops_h
#define EndStops_h

#include "../../util/pch.h"

#define ES_PU INPUT_PULLUP
#define ES_NP INPUT

typedef void (*voidFuncPtr)();

static void doNothing() {}

class EndStops
{
private:
    voidFuncPtr XaxisEvent[2];
    voidFuncPtr YaxisEvent[2];
    voidFuncPtr ZaxisEvent[2];
    
public:
    EndStops();
    
    ~EndStops();

    void begin(voidFuncPtr xmin_action = doNothing, voidFuncPtr xmax_action = doNothing, voidFuncPtr ymin_action = doNothing, voidFuncPtr ymax_action = doNothing, voidFuncPtr zmin_action = doNothing, voidFuncPtr zmax_action = doNothing);
};


#endif