#ifndef Planner_h
#define Planner_h

#include "../util/pch.h"

enum ResolutionSteps : uint8_t
{
    FULL_STEP = 1,
    HALF_STEP = 2,
    QUARTER_STEP = 4,
    EIGHTH_STEP = 8,
    SIXTEENTH_STEP = 16
};

typedef struct StepperData
{
    uint16_t* stepsPerSample;
    uint8_t direction;
    unsigned long sampleTime;
    bool compareMicros;

    ~StepperData() { delete stepsPerSample;}
} StepperData_t;


class Planner
{
private:
    StepperData_t plannedMovement;
    bool planned;
public:
    Planner();
    ~Planner();

    void planMovement(float final_pos, float max_speed, ResolutionSteps);
    bool isPlanned();
};


#endif