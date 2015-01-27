/**************************************************************************/
/*!
@file     LIDARduino.cpp
@author   Stuart Feichtinger
@license  MIT (see license.txt)

Arduino Library for the LIDAR-Lite from PulsedLight, Inc.

@section  HISTORY
v0.0.1 - First release
*/
/**************************************************************************/

#include "LIDARduino1.h"


LIDAR::LIDAR( void ):_I2CAddress( LIDARLite_ADDRESS ){

}

LIDAR::LIDAR( uint8_t i2cAddr ):_I2CAddress( i2cAddr ){

}

void LIDAR::begin( void ){
  I2c.begin();
  delay(100);
  I2c.timeOut(50);

}

int LIDAR::getDistance( void ){
  _writeI2C( LIDAR_COMMAND,  )
  uint8_t readAry[2];
  int distance = 1;
  return distance;
}

int LIDAR::getVelocity( void ){
  uint8_t readAry[1];


  return((int)((char)readAry[0]));

}


uint8_t LIDAR::_readI2C( uint8_t regAddress, int numBytes, uint8_t destAry[2] ){
  uint8_t nackack = 100;
  while(nackack != 0){
    nackack = I2c.read(_I2CAddress, regAddress, numBytes, destAry ); // Read 1-2 Bytes from LIDAR-Lite Address and store in array
    delay(2); // Wait 2 ms to prevent overpolling
  }
  return destAry[2]; // Return array for use in other functions
}

void LIDAR::_writeI2C( uint8_t regAddress, uint8_t value ){
  uint8_t nackack = 100;
  while(nackack != 0){
    nackack = I2c.write(_I2CAddress, regAddress, value ); // Write to LIDAR-Lite Address with Value
    delay(2); // Wait 2 ms to prevent overpolling
  }
}
