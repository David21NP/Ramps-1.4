#include "Stepper.h"

int Stepper::steps_length;

Stepper::Stepper(const int &_steps_rev, const int &s_pin, const int &d_pin, const int &e_pin) : steps_per_rev(_steps_rev), step_pin(s_pin), dir_pin(d_pin), en_pin(e_pin)
{
    long step_count_per_action = 0;
    float deg = 0;
}

Stepper::~Stepper()
{
    delete discrete_steps;
}

long Stepper::deg_to_steps(const float &_deg)
{
    return (long)round((_deg / 360) * (steps_per_rev * microsteps));
}

void Stepper::begin(const float &_rpm = 200, const short &_microsteps = 1)
{
    pinMode(dir_pin, OUTPUT);
    digitalWrite(dir_pin, HIGH);

    pinMode(step_pin, OUTPUT);
    digitalWrite(step_pin, LOW);

    pinMode(en_pin, OUTPUT);
    disable();

    rpm = (_rpm > 200) ? 200 : _rpm;
    microsteps = _microsteps;
}

void Stepper::setSpeedProfile(const Mode &_mode)
{
    mode = _mode;
}

float Stepper::steps_to_deg(const long &_steps)
{
    return (float)((_steps * 360) / (steps_per_rev * microsteps));
}

void Stepper::rotate(const double &deg)
{
    move(deg_to_steps(deg));
}

void Stepper::enable()
{
    digitalWrite(en_pin, LOW);
}
void Stepper::disable()
{
    digitalWrite(en_pin, HIGH);
}

float Stepper::steps_per_second()
{
    return (float)((rpm * steps_per_rev * microsteps) / 60.0);
}

float Stepper::calc_movement(const long &steps)
{
    float tf;
    int samples;
    switch (mode)
    {
    case CONSTANT_SPEED:
        samples = (int)round(((float)abs(steps) * SAMPLE_FREQUENCY) / (steps_per_second()));

        steps_length = samples;

        discrete_steps = new int[samples];
        
        for (int i = 0; i < samples; i++)
        {
            discrete_steps[i] = round(steps_per_second() * SAMPLE_TIME);
        }

        for (int i = 0; i < samples; i++)
        {
            make_few_steps(discrete_steps[i]);
        }
        

        float sum = 0;
        for (int i = 0; i < samples; i++)
            sum += discrete_steps[i];
        return sum;
        break;

    case LINEAR_SPEED:
        break;

    case SQUARE_SPEED:
    default:

        break;
    }
}

void Stepper::make_few_steps(const short& steps)
{
    steps > 0 ? digitalWrite(dir_pin, HIGH) : digitalWrite(dir_pin, LOW);
    for (short i = 0; i < abs(steps); i++)
    {
        digitalWrite(step_pin, HIGH);
        delayMicroseconds(2);
        digitalWrite(step_pin, LOW);
        delayMicroseconds(1450);
    }
    
}

float Stepper::move(const long &steps)
{
    return calc_movement(steps);
}

static void Stepper::toEventExecute()
{
    
}