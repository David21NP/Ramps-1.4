#include "Steppers.h"

// Steppers::Steppers()
// {
//     max_rpm = 250;
//     resolution = FULL_STEP;

//     //planner = new Planner();
//     currentAngle = 0;
//     moving = false;

//     pinMode(en_pin, OUTPUT);
//     pinMode(step_pin, OUTPUT);
//     pinMode(dir_pin, OUTPUT);

//     digitalWrite(en_pin, HIGH);
//     digitalWrite(step_pin, LOW);
//     digitalWrite(dir_pin, LOW);
// }

// Steppers::Steppers(ResolutionSteps _resolution) : Steppers()
// {
//     resolution = _resolution;
// }

// Steppers::Steppers(float _max_rpm) : Steppers(_en_pin, _step_pin, _dir_pin)
// {
//     max_rpm = _max_rpm;
// }

// Steppers::Steppers(int _en_pin, int _step_pin, int _dir_pin, ResolutionSteps _resolution, float _max_rpm) : Steppers(_en_pin, _step_pin, _dir_pin)
// {
//     max_rpm = _max_rpm;
//     resolution = _resolution;
// }

Steppers::~Steppers()
{
    
}

void Steppers::makeStep()
{
    // digitalWrite(step_pin, HIGH);
    // delayMicroseconds(2);
    // digitalWrite(step_pin, LOW);
}