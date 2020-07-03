#ifndef Stepper_h
#define Stepper_h

#include "Planner.h"
#include "../Events/Event.h"

class Stepper
{
private:
    int step_pin;
    int dir_pin;
    int en_pin;

    float currentAngle;
    float max_rpm;

    int resolution;

    bool moving;

    void makeStep();

    Planner* planner;
public:
    Stepper(int _en_pin, int _step_pin, int _dir_pin);
    Stepper(int _en_pin, int _step_pin, int _dir_pin, ResolutionSteps);
    Stepper(int _en_pin, int _step_pin, int _dir_pin, float _max_rpm);
    Stepper(int _en_pin, int _step_pin, int _dir_pin, ResolutionSteps, float _max_rpm);
    ~Stepper();
    void setResolution(ResolutionSteps);
    void setMaxRpm(float _rpm);

    void move(long steps);
    void move(float deg);
    bool isMoving();
};

typedef void (Stepper::* s_EvHandler)();

#endif