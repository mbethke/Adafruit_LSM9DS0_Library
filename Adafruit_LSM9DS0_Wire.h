#ifndef __LSM9DS0_WIRE_H__
#define __LSM9DS0_WIRE_H__

#include "Adafruit_LSM9DS0.h"
#include <Wire.h>

class Adafruit_LSM9DS0_Wire : Adafruit_LSM9DS0
{
	public:
		Adafruit_LSM9DS0_Wire ( int32_t sensorID = 0 );

		bool    begin       ( void );
		void    write8      ( boolean type, byte reg, byte value );
		byte    read8       ( boolean type, byte reg);
		byte    readBuffer  ( boolean type, byte reg, byte len, uint8_t *buffer);
};

#endif // __LSM9DS0_WIRE_H__
