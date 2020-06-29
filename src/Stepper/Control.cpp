#include "Control.h"

Control::Control()
{
    set_ts(0.4);
}

Control::Control(float _st)
{
    set_ts(_st);
}

Control::~Control()
{
}

void Control::set_st(float _st)
{
    st = _st;
}

float Control::get_st()
{
    return st;
}