Adafruit LSM9DS0 Library
========================

This is a stripped-down, objectified and abused version of the original Adafruit
LSM9DS0 library by Tony DiCola
(https://github.com/adafruit/Adafruit_LSM9DS0_Library). 

Advantages over the original are:
* Just over half the size even though it has an enhanced API that allows you to adjust more
  parameters.s
* The size advantage is mainly due to stripping out of the Adafruit_Sensor code
  which I think is a fundamentally bad idea. It knows too much about the
  classes that implement it, such as the symbolic sensor types, defines bullshit
  categories (what's a gravity sensor as opposed to an acceleration sensor
  anyway?) and is usually only marginally useful. For example, for orienting
  myself in 3D I'm interested in the magnitude of any acceleration vector in
  relation to the two others, not in the absolute SI-unit values.
* It actually takes advantage of C++' features like inheritance and pure virtual
  methods to give you three versions for hardware SPI, software SPI and I2C
  ("Wire") that each contain only the necessary code and don't have to check
  which version to use each and every time through the code.
* Likely a bit faster, although I haven't benchmarked
  


Original README follows.

This is a library for the Adafruit triple-axis accelerometer/magnetometer/gyroscope LSM9DS0 breakouts

Designed specifically to work with the Adafruit LSM9DS0 Breakout & Flora Sensor
  ----> https://www.adafruit.com/products/2020
  ----> https://www.adafruit.com/products/2021

These sensors use I2C to communicate, 2 pins are required to interface
Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Check out the links above for our tutorials and wiring diagrams 

Written by Kevin Townsend for Adafruit Industries.  
BSD license, all text above must be included in any redistribution

To download. click the DOWNLOADS button in the top right corner, rename the uncompressed folder Adafruit_LSM9DS0. Check that the Adafruit_LSM9DS0 folder contains Adafruit_LSM9DS0.cpp and Adafruit_LSM9DS0.h

Place the Adafruit_LSM9DS0 library folder your *arduinosketchfolder*/libraries/ folder. You may need to create the libraries subfolder if its your first library. Restart the IDE.
