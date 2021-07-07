#ifdef ARDUINO_AVR_MEGA2560
#include "Ramps.h"

Ramps::Ramps()
{
}

Ramps::~Ramps()
{
}

void Ramps::begin()
{
    m_pwo.begin();
    m_servos.begin();
    m_steppers.begin();
}

#endif