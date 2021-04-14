#ifndef Steppers_h
#define Steppers_h

#include "../util/pch.h"
#include "EndStops/EndStops.h"

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
    SyncDriver* Driver;

    float currentAngle[5];
    float max_rpm[5];

    int resolution[5];

    int pins[3*5];

    int getPin(short, short);
public:
    BasicStepperDriver* Motors[5];

    Steppers();
    Steppers(const ResolutionSteps*);
    Steppers(const float* _max_rpm);
    Steppers(const ResolutionSteps*, const float* _max_rpm);
    ~Steppers();

    void setRPM(const float* _max_rpm);

    void begin();

    void moveAll(const long& step_x, const long& step_y, const long& step_z, const long& step_e0, const long& step_e1);
    void rotateAll(const long& degs_x, const long& degs_y, const long& degs_z, const long& degs_e0, const long& degs_e1);

    void moveX(const long& step);
    void rotateX(const float& degs);

    void moveY(const long& step);
    void rotateY(const float& degs);

    void moveZ(const long& step);
    void rotateZ(const float& degs);

    void moveXYZ(const long& step_x, const long& step_y, const long& step_z = 0);
    void rotateXYZ(const float& degs_x, const float& degs_y, const float& degs_z = 0);

    void moveE0(const long& step);
    void rotateE0(const float& degs);

    void moveE1(const long& step);
    void rotateE1(const float& degs);
};

#endif