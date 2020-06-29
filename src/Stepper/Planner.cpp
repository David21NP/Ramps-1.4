#include "Planner.h"

Planner::Planner()
{
    planned = false;
}

Planner::~Planner()
{
}

void Planner::planMovement(float final_pos, float max_speed, ResolutionSteps resolution)
{
    planned = false;

    if (final_pos == 0)
        return;

    float position = 0;
    float velocity = 0;
    float aceleration = 0;
    float samtime = (abs(final_pos) / (4 * max_speed)) / 10;
    float jerk = final_pos / (8 * (pow(samtime * 10, 3)));

    plannedMovement.stepsPerSample = new int[71];
    plannedMovement.direction = (final_pos > 0) ? HIGH : LOW;
    plannedMovement.sampleTime = (samtime >= 0.1) ? (unsigned long)(samtime * 1000) : (unsigned long)(samtime * 1000000);
    plannedMovement.compareMicros = !(samtime >= 0.1);

    plannedMovement.stepsPerSample[0] = 0;

    for (int i = 0; i < 70; i++)
    {
        float _jerk = 0;

        if (((i >= 0) && (i < 10)) || ((i >= 60) && (i < 70)))
            _jerk = jerk;
        else if (((i >= 20) && (i < 30)) || ((i >= 40) && (i < 50)))
            _jerk = (jerk * (-1));

        position += velocity * samtime + (aceleration / 2) * pow(samtime, 2) + (_jerk / 6) * pow(samtime, 3);
        velocity += aceleration * samtime + (_jerk / 2) * pow(samtime, 2);
        aceleration += _jerk * samtime;
        plannedMovement.stepsPerSample[i + 1] = round(((float)resolution * position) / 1.8) - plannedMovement.stepsPerSample[i];
    }

    planned = true;
}

bool Planner::isPlanned()
{
    return planned;
}