#ifndef __LSM9DS0_SPI_HARD_H__
#define __LSM9DS0_SPI_HARD_H__

#include <Adafruit_LSM9DS0.h>
#include <SPI.h>

class Adafruit_LSM9DS0_SPI_Hard : public Adafruit_LSM9DS0
{
    public:
        Adafruit_LSM9DS0_SPI_Hard ( int8_t xmcs, int8_t gcs );

        bool    begin       ( void );

    private:
        uint8_t spixfer     ( uint8_t data );
        void    write8      ( boolean type, byte reg, byte value );
        byte    read8       ( boolean type, byte reg);
        byte    readBuffer  ( boolean type, byte reg, byte len, uint8_t *buffer);

        int8_t  _csg, _csxm;
};

#endif // __LSM9DS0_SPI_HARD_H__
