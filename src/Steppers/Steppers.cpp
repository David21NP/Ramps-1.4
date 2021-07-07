#include "Steppers.h"

voidFuncPtr stopMotor(BasicStepperDriver& motor)
{
    motor.stop();
}

namespace Ramps_1_4
{
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
        delete Driver;
        delete endStops;
    }

    void Steppers::setRPM(const float* _max_rpm)
    {
        if (sizeof(max_rpm) == sizeof(_max_rpm))
            memcpy(max_rpm, _max_rpm, sizeof(max_rpm));

        for (short i = 0; i < 5; i++)
        {
            Motors[i]->setRPM(max_rpm[i]);
        }
        
    }

    void Steppers::begin()
    {
        for (short i = 0; i < 3; i++)
            Motors[i] = new BasicStepperDriver(200, getPin(i, 2), getPin(i, 1), getPin(i, 0));

        for (short i = 3; i < 5; i++)
            Motors[i] = new A4988(200, getPin(i, 2), getPin(i, 1), getPin(i, 0));

        for (short i = 0; i < 5; i++)
            Motors[i]->begin(max_rpm[i], resolution[i]);

        Driver = new SyncDriver(*Motors[0], *Motors[1], *Motors[2]);

        endStops = new EndStops();
        endStops->begin(stopMotor(*Motors[0]), stopMotor(*Motors[0]), stopMotor(*Motors[1]), stopMotor(*Motors[1]), stopMotor(*Motors[2]), stopMotor(*Motors[2]));
    }

    int Steppers::getPin(short axis, short pin)
    {
        return pins[axis * 3 + pin];
    }

    void Steppers::moveAll(const long& step_x, const long& step_y, const long& step_z, const long& step_e0, const long& step_e1)
    {
        moveXYZ(step_x, step_y, step_z);
        Motors[3]->move(step_e0);
        Motors[4]->move(step_e1);
    }

    void Steppers::rotateAll(const long& degs_x, const long& degs_y, const long& degs_z, const long& degs_e0, const long& degs_e1)
    {
        rotateXYZ(degs_x, degs_y, degs_z);
        Motors[3]->rotate(degs_e0);
        Motors[4]->rotate(degs_e1);
    }

    void Steppers::moveX(const long &step)
    {
        Motors[0]->move(step);
    }

    void Steppers::rotateX(const float &degs)
    {
        Motors[0]->rotate(degs);
    }

    void Steppers::moveY(const long &step)
    {
        Motors[1]->move(step);
    }

    void Steppers::rotateY(const float &degs)
    {
        Motors[1]->rotate(degs);
    }

    void Steppers::moveZ(const long &step)
    {
        Motors[2]->move(step);
    }

    void Steppers::rotateZ(const float &degs)
    {
        Motors[2]->rotate(degs);
    }

    void Steppers::moveXYZ(const long& step_x, const long& step_y, const long& step_z)
    {
        Driver->move(step_x, step_y, step_z);
    }

    void Steppers::rotateXYZ(const float& degs_x, const float& degs_y, const float& degs_z)
    {
        Driver->rotate(degs_x, degs_y, degs_z);
    }

    void Steppers::moveE0(const long& step)
    {
        Motors[3]->move(step);
    }

    void Steppers::rotateE0(const float& degs)
    {
        Motors[3]->rotate(degs);
    }

    void Steppers::moveE1(const long& step)
    {
        Motors[4]->move(step);
    }

    void Steppers::rotateE1(const float& degs)
    {
        Motors[4]->rotate(degs);
    }

    // void Steppers::calibrateEndStops()
    // {
    //     while (/* condition */)
    //     {
    //         /* code */
    //     }
    // }
}
