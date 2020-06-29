#ifndef Stepper_h
#define Stepper_h

#include "control.h"

enum ResolutionSteps : uint8_t
{
    FULL_STEP = 1,
    HALF_STEP = 2,
    QUARTER_STEP = 4,
    EIGHTH_STEP = 8,
    SIXTEENTH_STEP = 16
};

class Stepper
{
private:
    int step_pin;
    int dir_pin;
    int en_pin;

    float currentAngle;

    int resolution;

    bool moving;

    void makeStep();
public:
    Stepper(int, int, int);
    ~Stepper();
    void setResolution(ResolutionSteps);

    void move(long steps);
    bool isMoving();
};

#endif