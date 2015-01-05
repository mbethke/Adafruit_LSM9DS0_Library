/***************************************************************************
  This is a library for the LSM9DS0 Accelerometer and magnentometer/compass

  Designed specifically to work with the Adafruit LSM9DS0 Breakouts

  These sensors use I2C to communicate, 2 pins are required to interface.

  Adafruit invests time and resources providing this open source code,
  please support Adafruit andopen-source hardware by purchasing products
  from Adafruit!

  Written by Kevin Townsend for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ***************************************************************************/
#include <Adafruit_LSM9DS0_Wire.h>

bool Adafruit_LSM9DS0_Wire::begin()
{
    Wire.begin();
    return begin_common();
}

void Adafruit_LSM9DS0_Wire::write8(boolean type, byte reg, byte value)
{
    Wire.beginTransmission((type == GYROTYPE) ? LSM9DS0_ADDRESS_GYRO : LSM9DS0_ADDRESS_ACCELMAG);
    Wire.write(reg);
    Wire.write(value);
    Wire.endTransmission();
}

byte Adafruit_LSM9DS0_Wire::readBuffer(boolean type, byte reg, byte len, uint8_t *buffer)
{
    const byte address = (type == GYROTYPE) ? LSM9DS0_ADDRESS_GYRO : LSM9DS0_ADDRESS_ACCELMAG;

    Wire.beginTransmission(address);
    Wire.write(reg);
    Wire.endTransmission();
    Wire.requestFrom(address, (byte)len);

    // Wait around until enough data is available
    while (Wire.available() < len);

    for (uint8_t i=0; i<len; i++) {
        buffer[i] = Wire.read();
    }
    Wire.endTransmission();
    return len;
}

