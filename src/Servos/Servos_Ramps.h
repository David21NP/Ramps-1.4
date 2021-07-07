#ifndef Servos_Ramps_h
#define Servos_Ramps_h

#include "../util/pch.h"
#include <Servo.h>

namespace Ramps_1_4
{
    class Servos_Ramps
    {
    private:
        Servo* Servos[4];
    public:
        Servos_Ramps();
        ~Servos_Ramps();

        void begin();
        void begin(int min, int max);

        void move(uint8_t, uint8_t);
        void moveAll(uint8_t, uint8_t, uint8_t, uint8_t);

        void moveMicroseconds(uint8_t, int);
        void moveAllMicroseconds(int, int, int, int);
    };
}


#endif