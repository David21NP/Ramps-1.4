#include "EndStops.h"

EndStops::EndStops()
{
}

EndStops::~EndStops()
{
}

void EndStops::begin(voidFuncPtr xmin_action, voidFuncPtr xmax_action, voidFuncPtr ymin_action, voidFuncPtr ymax_action, voidFuncPtr zmin_action, voidFuncPtr zmax_action)
{
    pinMode(XMIN, ES_NP);
    pinMode(XMAX, ES_NP);
    pinMode(YMIN, ES_NP);
    pinMode(YMAX, ES_NP);
    pinMode(ZMIN, ES_NP);
    pinMode(ZMAX, ES_NP);

    XaxisEvent[0] = xmin_action;
    XaxisEvent[1] = xmax_action;
    YaxisEvent[0] = ymin_action;
    YaxisEvent[1] = ymax_action;
    ZaxisEvent[0] = zmin_action;
    ZaxisEvent[1] = zmax_action;
}