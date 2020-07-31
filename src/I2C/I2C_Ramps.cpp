#include "I2C_Ramps.h"

I2C_Ramps::I2C_Ramps(/* args */)
{
}

I2C_Ramps::~I2C_Ramps()
{
}

int8_t I2C_Ramps::readBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint8_t *data)
{
    return I2Cdev::readBit(devAddr, regAddr, bitNum, data);
}

int8_t I2C_Ramps::readBits(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t *data)
{
    return I2Cdev::readBits(devAddr, regAddr, bitStart, length, data);
}

int8_t I2C_Ramps::readByte(uint8_t devAddr, uint8_t regAddr, uint8_t *data)
{
    return I2Cdev::readByte(devAddr, regAddr, data);
}

bool I2C_Ramps::writeBit(uint8_t devAddr, uint8_t regAddr, uint8_t bitNum, uint8_t data)
{
    return I2Cdev::writeBit(devAddr, regAddr, bitNum, data);
}

bool I2C_Ramps::writeBits(uint8_t devAddr, uint8_t regAddr, uint8_t bitStart, uint8_t length, uint8_t data)
{
    return I2Cdev::writeBits(devAddr, regAddr, bitStart, length, data);
}

bool I2C_Ramps::writeByte(uint8_t devAddr, uint8_t regAddr, uint8_t data)
{
    return I2Cdev::writeByte(devAddr, regAddr, data);
}