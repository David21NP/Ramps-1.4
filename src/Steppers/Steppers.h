#ifndef Steppers_h
#define Steppers_h

#include "../util/pch.h"
#include "EndStops/EndStops.h"
#include "Stepper/Stepper.h"

#include <A4988.h>
#include <BasicStepperDriver.h>
#include <MultiDriver.h>
#include <SyncDriver.h>

enum ResolutionSteps : uint8_t
{
    FULL_STEP = 1,
    HALF_STEP = 2,
    QUARTER_STEP = 4,
    EIGHTH_STEP = 8,
    SIXTEENTH_STEP = 16
};

class Steppers
{
private:
    SyncDriver* Drivers[2];

    float currentAngle[5];
    float max_rpm[5];

    int resolution[5];

    int pins[3*5];

    int getPin(short, short);
public:
    A4988* Motors[5];

    Steppers();
    Steppers(const ResolutionSteps*);
    Steppers(const float* _max_rpm);
    Steppers(const ResolutionSteps*, const float* _max_rpm);
    ~Steppers();

    void begin();

    void moveAll(const long* steps);
    void moveAll(const float* degs);

    void moveX(const long& step);
    void moveX(const float& degs);

    void moveY(const long& step);
    void moveY(const float& degs);

    void moveZ(const long& step);
    void moveZ(const float& degs);

    bool isMoving();
};

#endif