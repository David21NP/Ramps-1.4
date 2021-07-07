#ifdef ARDUINO_AVR_MEGA2560
#ifndef Ramps_h
#define Ramps_h

#include "./util/IRamps.h"

class Ramps
{
private:
public:
    Ramps_1_4::Eeprom m_eeprom;
    Ramps_1_4::I2C_Ramps m_i2c;
    Ramps_1_4::Power_Output m_pwo;
    Ramps_1_4::Servos_Ramps m_servos;
    Ramps_1_4::Steppers m_steppers;
    Ramps_1_4::Thermistors m_thermistors;
    Ramps();
    ~Ramps();
    void begin();
};

#endif
#endif