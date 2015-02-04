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

typedef enum{
  LL_DC = USE_DC, //Correct for DC (More accurate)
  LL_NO_DC = NO_DC //Don't correct (Faster)

} LL_READ_MODE_E;


typedef enum{
  LL_10_MS = 1, // sets the velocity measurement separation to 10msec resulting in a velocity calibration in meters/sec
  LL_100_MS = 0 // sets the  measurement separation to 100msec.

} LL_V_RESOLUTION_E;

typedef enum{
  dump_success = 0,
  dump_min_bounds,
  dump_max_bounds,
  dump_timeout

} dump_error_t;

typedef union{

struct{
  unsigned int
    low:4 ,
    hi:4  ;
  } nib;
  uint8_t full;
}reg_u;

class LIDAR_Lite{
  public:
    virtual void
      begin()=0;

    void
      enablePowerCtrl( uint8_t powerPin ) , // allow for multiple sensors on one I2C bus or PWM pin.
      correlationDump( Stream* s, uint8_t startAddress=0, uint8_t stopAddress=0x10 );

    bool
      power( bool state ) ,
      powerStatus( void ) const ;


  private:
      uint8_t
        _powerPin = 255;

      bool
        _pwrState = 1;

};

class LIDAR_Lite_I2C : public LIDAR_Lite{


  /***********PUBLIC*************************/
public:

  LIDAR_Lite_I2C(),
  LIDAR_Lite_I2C( uint8_t i2cAddr );

  virtual void
    begin( void ) ;

  int16_t
    getDistance( LL_READ_MODE_E e = LL_DC ) , // return distance in cm.
    getVelocity( void ) ,
    easyDistance( void ) ,
    easyVelocity( void ) ;



  uint8_t
    getHWversion( void ) , // laser units revisions begin with 0x01 (short range ), 0x20 for long range lasers, and Led units begin with 0x40
    getSWversion( void ) , // laser units revisions begin with 0x01 (short range ), 0x20 for long range lasers, and Led units begin with 0x40
    getStatus( void ),
    getRSSI( void ) ,
    getMaxCount( void ) ;

  void
    enableVelocity( LL_V_RESOLUTION_E e) ,
    disableVelocity( void ),
    setMaxCount( uint8_t count ),
    reset( void ) ;




  /***********PRIVATE*************************/
private:

  uint8_t
    _readI2C( uint8_t regAddress ); //read single byte

  void
    _readI2C( uint8_t regAddress, int16_t numBytes, uint8_t destAry[] ), //read array of bytes
    _writeI2C( uint8_t regAddress, uint8_t value ),
    _overWriteI2C( uint8_t regAddress, uint8_t value );

  inline void
    _triggerRead( LL_READ_MODE_E e ) ;


  uint8_t const
    _I2CAddress ;



};

class LIDAR_Lite_PWM: public LIDAR_Lite{

public:
  LIDAR_Lite_PWM( uint8_t triggerPin, uint8_t readPin ) ;

  virtual void
    begin();

  unsigned long
    getDistance( void );

private:
  uint8_t const
    _triggerPin ,
    _readPin ;



};
