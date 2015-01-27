/**************************************************************************/
/*!
@file     LIDARduino.h
@author   Stuart Feichtinger
@license  MIT (see license.txt)

Arduino Library for the LIDAR-Lite from PulsedLight, Inc.

@section  HISTORY
v0.0.1 - First release
*/
/**************************************************************************/

#pragma once

#include "Arduino.h"
#include "LIDARLite_registers.h"
#include <I2C.h>


class LIDAR{

  /***********PUBLIC*************************/
  LIDAR(),
  LIDAR( uint8_t i2cAddr );

  void
    begin( void ) ;

  int
    getDistance( void ) ,
    getVelocity( void ) ;






  /***********PRIVATE*************************/

  uint8_t
    _readI2C( uint8_t regAddress, int numBytes, uint8_t destAry[2] ) ;

  void
    _writeI2C( uint8_t regAddress, uint8_t value ) ;



  uint8_t const
    _I2CAddress ;




};
