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
    SPCRback = SPCR;
    SPI.begin();
    SPI.setClockDivider(SPI_CLOCK_DIV8);
    SPI.setDataMode(SPI_MODE0);
    mySPCR = SPCR;
    SPCR = SPCRback;
    return begin_common();
}

void Adafruit_LSM9DS0_SPI_Hard::write8(boolean type, byte reg, byte value)
{
    const byte _cs = (type == GYROTYPE) ? _csg : _csxm;

    SPCRback = SPCR;
    SPCR = mySPCR;
    digitalWrite(_cs, LOW);
    // set address
    spixfer(reg | 0x40); // write multiple
    spixfer(value); 
    digitalWrite(_cs, HIGH);
    SPCR = SPCRback;
}

byte Adafruit_LSM9DS0_SPI_Hard::readBuffer(boolean type, byte reg, byte len, uint8_t *buffer)
{
    const byte _cs = (type == GYROTYPE) ? _csg : _csxm;

    SPCRback = SPCR;
    SPCR = mySPCR;
    digitalWrite(_cs, LOW);
    // set address
    spixfer(reg | 0x80 | 0x40); // read multiple
    for (uint8_t i=0; i<len; i++) {
        buffer[i] = spixfer(0);
    }
    digitalWrite(_cs, HIGH);
    SPCR = SPCRback;

    return len;
}

uint8_t Adafruit_LSM9DS0_SPI_Hard::spixfer(uint8_t data) {
    return SPI.transfer(data);
}
