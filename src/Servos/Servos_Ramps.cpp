#include "Servos_Ramps.h"

namespace Ramps_1_4
{
    Servos_Ramps::Servos_Ramps()
    {
        Servos[0] = new Servo();
        Servos[1] = new Servo();
        Servos[2] = new Servo();
        Servos[3] = new Servo();
    }

    Servos_Ramps::~Servos_Ramps()
    {
        delete Servos[0];
        delete Servos[1];
        delete Servos[2];
        delete Servos[3];
    }

    void Servos_Ramps::begin()
    {
        Servos[0]->attach(SERVO_PIN_1);
        Servos[1]->attach(SERVO_PIN_2);
        Servos[2]->attach(SERVO_PIN_3);
        Servos[3]->attach(SERVO_PIN_4);
    }

    void Servos_Ramps::begin(int min, int max)
    {
        Servos[0]->attach(SERVO_PIN_1, min, max);
        Servos[1]->attach(SERVO_PIN_2, min, max);
        Servos[2]->attach(SERVO_PIN_3, min, max);
        Servos[3]->attach(SERVO_PIN_4, min, max);
    }

    void Servos_Ramps::move(uint8_t servo, uint8_t angle)
    {
        if (servo < 4)
        {
            Servos[servo]->write(angle);
        }
    }

    void Servos_Ramps::moveAll(uint8_t angle_1, uint8_t angle_2, uint8_t angle_3, uint8_t angle_4)
    {
        Servos[0]->write(angle_1);
        Servos[1]->write(angle_2);
        Servos[2]->write(angle_3);
        Servos[3]->write(angle_4);
    }

    void Servos_Ramps::moveMicroseconds(uint8_t servo, int value)
    {
        if (servo < 4)
        {
            Servos[servo]->writeMicroseconds(value);
        }
    }

    void Servos_Ramps::moveAllMicroseconds(int value_1, int value_2, int value_3, int value_4)
    {
        Servos[0]->writeMicroseconds(value_1);
        Servos[1]->writeMicroseconds(value_2);
        Servos[2]->writeMicroseconds(value_3);
        Servos[3]->writeMicroseconds(value_4);
    }
}