#ifndef Stepper_h
#define Stepper_h

#include "../../util/pch.h"
#include "../TimerEvents/TimEvents.h"

enum Mode {CONSTANT_SPEED, LINEAR_SPEED, SQUARE_SPEED};

template<int _size>
struct Steps_data
{
    int discrete_steps[_size];
    int size = _size;
};


class Stepper
{
private:
    int step_pin;
    int dir_pin;
    int en_pin;

    short microsteps;

    int steps_per_rev;

    float rpm;

    long step_count_per_action;
    float deg = 0;

    long deg_to_steps(const float& _deg);
    float steps_to_deg(const long& _steps);

    float calc_movement(const long& steps);

    void make_few_steps(const short& steps);

    int *discrete_steps;
    Steps_data<2> current_data;

    static int steps_length;

    Mode mode = CONSTANT_SPEED;
    // Mode mode = SQUARE_SPEED;

public:

    Stepper(const int& _steps_rev, const int& s_pin, const int& d_pin, const int& e_pin);
    ~Stepper();

    void begin(const float& _rpm = 200, const short& _microsteps = 1);

    void setSpeedProfile(const Mode& mode);

    float move(const long& steps);

    void rotate(const double& deg);

    void enable();
    void disable();

    float steps_per_second();

    static void toEventExecute();
};

#endif