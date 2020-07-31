#ifndef Steppers_h
#define Steppers_h

#include <A4988.h>
#include <BasicStepperDriver.h>
#include <MultiDriver.h>
#include <SyncDriver.h>

#include "../config/PinsRamps.h"

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
    A4988* Motor_x;
    A4988* Motor_y;
    A4988* Motor_z;

    A4988* Motor_e0;
    A4988* Motor_e1;

    SyncDriver* Driver_1;
    SyncDriver* Driver_2;

    float currentAngle[5];
    float max_rpm[5];

    int resolution[5];

    void makeStep();
public:
    Steppers();
    Steppers(const ResolutionSteps*);
    Steppers(const float* _max_rpm);
    Steppers(const ResolutionSteps*, const float* _max_rpm);
    ~Steppers();

    void moveAll(long steps1, long steps2, long steps3, long steps4, long steps5);
    void moveAll(float deg1, float deg2, float deg3, float deg4, float deg5);

    bool isMoving();
};

#endif