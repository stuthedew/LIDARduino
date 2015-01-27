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

  LIDAR() ;

  void
    begin( void ) ;

  /***********PUBLIC*************************/




  /***********PRIVATE*************************/


  uint8_t
    _I2CAddress ;

  


};
