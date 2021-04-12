#include "Steppers.h"

Steppers::Steppers()
{
    for (short i = 0; i < 5; i++)
    {
        max_rpm[i] = 10;
        resolution[i] = FULL_STEP;
        currentAngle[i] = 0;
    }

    pins[0] = X_EN;
    pins[1] = X_STEP;
    pins[2] = X_DIR;

    pins[3] = Y_EN;
    pins[4] = Y_STEP;
    pins[5] = Y_DIR;

    pins[6] = Z_EN;
    pins[7] = Z_STEP;
    pins[8] = Z_DIR;

    pins[9] = E0_EN;
    pins[10] = E0_STEP;
    pins[11] = E0_DIR;

    pins[12] = E1_EN;
    pins[13] = E1_STEP;
    pins[14] = E1_DIR;

    for (short i = 0; i < 5; i++)
        Motors[i] = new A4988(200, getPin(i, 2), getPin(i, 1), getPin(i, 0));
}

Steppers::Steppers(const ResolutionSteps *res) : Steppers()
{
    if (sizeof(resolution) == sizeof(res))
        memcpy(resolution, res, sizeof(resolution));
}

Steppers::Steppers(const float *_max_rpm) : Steppers()
{
    if (sizeof(max_rpm) == sizeof(_max_rpm))
        memcpy(max_rpm, _max_rpm, sizeof(max_rpm));
}

Steppers::Steppers(const ResolutionSteps *res, const float *_max_rpm) : Steppers()
{
    if (sizeof(max_rpm) == sizeof(_max_rpm))
        memcpy(max_rpm, _max_rpm, sizeof(max_rpm));
    if (sizeof(resolution) == sizeof(res))
        memcpy(resolution, res, sizeof(resolution));
}

Steppers::~Steppers()
{
}

void Steppers::begin()
{
    for (short i = 0; i < 5; i++)
        Motors[i]->begin(max_rpm[i], resolution[i]);
}

int Steppers::getPin(short axis, short pin)
{
    return pins[axis * 3 + pin];
}

void Steppers::moveAll(const long *steps)
{
    for (short i = 0; i < 5; i++)
        Motors[i]->move(steps[i]);
}

void Steppers::moveAll(const float *degs)
{
    for (short i = 0; i < 5; i++)
        Motors[i]->rotate(degs[i]);
}

void Steppers::moveX(const long &step)
{
    Motors[0]->move(step);
}

void Steppers::moveX(const float &degs)
{
    Motors[0]->rotate(degs);
}

void Steppers::moveY(const long &step)
{
    Motors[1]->move(step);
}

void Steppers::moveY(const float &degs)
{
    Motors[1]->rotate(degs);
}

void Steppers::moveZ(const long &step)
{
    Motors[2]->move(step);
}

void Steppers::moveZ(const float &degs)
{
    Motors[2]->rotate(degs);
}