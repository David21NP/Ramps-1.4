#ifndef Servos_Ramps_h
#define Servos_Ramps_h

#include "../util/pch.h"
#include <Servo.h>

class Servos_Ramps
{
private:
    Servo* Servos[4];
public:
    Servos_Ramps();
    ~Servos_Ramps();

    void move(uint8_t, uint8_t);
};


#endif