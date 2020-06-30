#include "Stepper.h"
#include "../Events/Event.h"

Stepper::Stepper(int _en_pin, int _step_pin, int _dir_pin) : en_pin(_en_pin), step_pin(_step_pin), dir_pin(_dir_pin)
{
    max_rpm = 250;
    resolution = FULL_STEP;

    planner = new Planner();
    currentAngle = 0;
    moving = false;

    pinMode(en_pin, OUTPUT);
    pinMode(step_pin, OUTPUT);
    pinMode(dir_pin, OUTPUT);

    digitalWrite(en_pin, HIGH);
    digitalWrite(step_pin, LOW);
    digitalWrite(dir_pin, LOW);
}

Stepper::Stepper(int _en_pin, int _step_pin, int _dir_pin, ResolutionSteps _resolution)
{
    Stepper(_en_pin, _step_pin, _dir_pin);

    resolution = _resolution;
}

Stepper::Stepper(int _en_pin, int _step_pin, int _dir_pin, float _max_rpm)
{
    Stepper(_en_pin, _step_pin, _dir_pin);

    max_rpm = _max_rpm;
}

Stepper::Stepper(int _en_pin, int _step_pin, int _dir_pin, ResolutionSteps _resolution, float _max_rpm)
{
    Stepper(_en_pin, _step_pin, _dir_pin);

    max_rpm = _max_rpm;
    resolution = _resolution;
}

Stepper::~Stepper()
{
    delete planner;
}

void Stepper::setResolution(ResolutionSteps res)
{
    resolution = res;
}

void Stepper::setMaxRpm(float _rpm)
{
    max_rpm = _rpm;
}

void Stepper::makeStep()
{
    digitalWrite(step_pin, HIGH);
    delayMicroseconds(2);
    digitalWrite(step_pin, LOW);
}

void Stepper::move(long steps)
{
    planner->planMovement((float)steps * (1.8 / resolution), max_rpm, resolution);
    while (!planner->isPlanned()) { }
    Event::AddEvent(&Stepper::makeStep);
}

void Stepper::move(float deg)
{
    planner->planMovement(deg, max_rpm, resolution);
    while (!planner->isPlanned()) { }
}