#ifndef Eeprom_h
#define Eeprom_h

#include "../util/pch.h"

namespace Ramps_1_4 {
    class Eeprom
    {
    private:
        int length;
    public:
        Eeprom();
        ~Eeprom();

        void WriteMem(int, byte);
        byte ReadMem(int);
        void ClearMem();

        void WriteFloat(int, float);
        float ReadFloat(int);
    };
}


#endif