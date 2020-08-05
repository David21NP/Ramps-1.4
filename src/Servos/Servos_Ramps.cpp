#include "Servos_Ramps.h"

Servos_Ramps::Servos_Ramps()
{
    Servos[0] = new Servo();
    Servos[1] = new Servo();
    Servos[2] = new Servo();
    Servos[3] = new Servo();

    Servos[0]->attach(SERVO_PIN_1);
    Servos[1]->attach(SERVO_PIN_2);
    Servos[2]->attach(SERVO_PIN_3);
    Servos[3]->attach(SERVO_PIN_4);
}

Servos_Ramps::~Servos_Ramps()
{
    delete Servos[0];
    delete Servos[1];
    delete Servos[2];
    delete Servos[3];
}

void Servos_Ramps::move(uint8_t servo, uint8_t angle)
{
    if (servo < 4)
    {
        Servos[servo]->write(angle);
    }
}