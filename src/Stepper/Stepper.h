#ifndef Stepper_h
#define Stepper_h

#include "../util/pch.h"
#include "control.h"

#define FULL_STEP 1
#define HALF_STEP 2
#define QUARTER_STEP 4
#define EIGHTH_STEP 8
#define SIXTEENTH_STEP 16

namespace Ramps_1_4 {
    class Stepper
    {
    private:
        int step_pin;
        int dir_pin;
        int en_pin;

        float currentAngle;

        int resolution;

        bool moving;
    public:
        Stepper(int, int, int);
        ~Stepper();
        void setResolution(int);

        void move(long steps);
        bool isMoving();
    };
}

#endif