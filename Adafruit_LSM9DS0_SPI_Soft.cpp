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
#include <Adafruit_LSM9DS0_SPI_Soft.h>

bool Adafruit_LSM9DS0_SPI_Soft::begin()
{
	pinMode(_clk, OUTPUT);
	pinMode(_mosi, OUTPUT);
	pinMode(_csxm, OUTPUT);
	pinMode(_csg, OUTPUT);
	digitalWrite(_csxm, HIGH);
	digitalWrite(_csg, HIGH);
	digitalWrite(_clk, HIGH);
	return begin_common();
}

void Adafruit_LSM9DS0_SPI_Soft::write8(boolean type, byte reg, byte value)
{
	const byte _cs = (type == GYROTYPE) ? _csg : _csxm;

	digitalWrite(_cs, LOW);
	// set address
	spixfer(reg | 0x40); // write multiple
	spixfer(value); 
	digitalWrite(_cs, HIGH);
}

byte Adafruit_LSM9DS0_SPI_Soft::readBuffer(boolean type, byte reg, byte len, uint8_t *buffer)
{
	const byte _cs = (type == GYROTYPE) ? _csg : _csxm;

	digitalWrite(_cs, LOW);
	// set address
	spixfer(reg | 0x80 | 0x40); // read multiple
	for (uint8_t i=0; i<len; i++) {
		buffer[i] = spixfer(0);
	}
	digitalWrite(_cs, HIGH);

	return len;
}

uint8_t Adafruit_LSM9DS0_SPI_Soft::spixfer(uint8_t data) {
	//Serial.println("Software SPI");
	uint8_t reply = 0;
	for (int i=7; i>=0; i--) {
		reply <<= 1;
		digitalWrite(_clk, LOW);
		digitalWrite(_mosi, data & (1<<i));
		digitalWrite(_clk, HIGH);
		if (digitalRead(_miso)) 
			reply |= 1;
	}
	return reply;
}
