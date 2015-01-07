#include <Adafruit_LSM9DS0_SPI_Hard.h>

Adafruit_LSM9DS0_SPI_Hard::Adafruit_LSM9DS0_SPI_Hard(int8_t xmcs, int8_t gcs) {
    _csg = gcs;
    _csxm = xmcs;
}

bool Adafruit_LSM9DS0_SPI_Hard::begin()
{
    pinMode(_csxm, OUTPUT);
    pinMode(_csg, OUTPUT);
    digitalWrite(_csxm, HIGH);
    digitalWrite(_csg, HIGH);
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV8);
    SPI.setDataMode(SPI_MODE0);
    return begin_common();
}

void Adafruit_LSM9DS0_SPI_Hard::write8(boolean type, byte reg, byte value)
{
    const byte _cs = (type == GYROTYPE) ? _csg : _csxm;

    digitalWrite(_cs, LOW);
    SPI.transfer(reg); // set address
    SPI.transfer(value); 
    digitalWrite(_cs, HIGH);
}

byte Adafruit_LSM9DS0_SPI_Hard::readBuffer(boolean type, byte reg, byte len, uint8_t *buffer)
{
    const byte _cs = (type == GYROTYPE) ? _csg : _csxm;
    reg &= 0x3f;    // clear 2 MSB

    digitalWrite(_cs, LOW);
    if (len > 1)
        SPI.transfer(0xC0 | reg); // set READ | MULTIPLE | address
    else
        SPI.transfer(0x80 | reg); // set READ | address
    for (int i=0; i<len; i++) {
        buffer[i] = SPI.transfer(0);
    }
    digitalWrite(_cs, HIGH);

    return len;
}

uint8_t Adafruit_LSM9DS0_SPI_Hard::spixfer(uint8_t data) {
    return SPI.transfer(data);
}
