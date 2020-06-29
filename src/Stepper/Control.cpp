#include "Control.h"

Control::Control()
{
    set_ts(0.4);
}

Control::Control(float _ts)
{
    set_ts(_ts);
}

Control::~Control()
{
}

void Control::set_ts(float _ts)
{
}

float Control::get_ts()
{
    return ts;
}