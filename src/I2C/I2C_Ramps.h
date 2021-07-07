#ifndef I2CDEV_H
#define I2CDEV_H

#include <I2Cdev.h>

namespace Ramps_1_4
{
    class I2C_Ramps
    {
    private:
        /* data */
    public:
        I2C_Ramps();
        ~I2C_Ramps();

        int8_t readBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint8_t *data);
        int8_t readBits(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t *data);
        int8_t readByte(uint8_t devAddr, uint8_t regAddr, uint8_t *data);

        bool writeBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint8_t data);
        bool writeBits(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t data);
        bool writeByte(uint8_t devAddr, uint8_t regAddr, uint8_t data);
    };
}


#endif