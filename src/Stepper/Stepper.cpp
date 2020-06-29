#include "Stepper.h"

namespace Ramps_1_4 {
    Stepper::Stepper(int _en_pin, int _step_pin, int _dir_pin) : en_pin(_en_pin), step_pin(_step_pin), dir_pin(_dir_pin)
    {
        currentAngle = 0;
        moving = false;

        pinMode(en_pin, OUTPUT);
        pinMode(step_pin, OUTPUT);
        pinMode(dir_pin, OUTPUT);

        digitalWrite(en_pin, HIGH);
        digitalWrite(step_pin, LOW);
        digitalWrite(dir_pin, LOW);
    }
    
    Stepper::~Stepper()
    {
    }

    void Stepper::setResolution(int res)
    {
        resolution = res;
    }
}