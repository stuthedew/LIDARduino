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
  LL_Basic,
  LL_Advanced

} LIDAR_LITE_MODE_E;


class LIDAR_Lite{
  public:
    virtual void
      begin()=0;

    void
      enablePowerCtrl( uint8_t powerPin ) ; // allow for multiple sensors on one I2C bus or PWM pin.
    bool
      power( bool state ) ,
      powerStatus( void ) const ;

      /*Example
          #define NUM_SENSORS 4
          LIDAR_Lite_I2C sensors[ NUM_SENSORS ]; // Could be LIDAR_Lite_PWM also
          uint8_t sensorCtrlPins[] = {6, 7, 8, 9};

          for(int i = 0; i < NUM_SENSORS; i++){ // disable all sensors
            sensors[i].begin();
            sensors[i].enablePowerCtrl( sensorPins[i] );
            sensors[i].power(0);
          }

          for(int i = 0; i < NUM_SENSORS; i++){ // Read from each sensor individually
            sensors[i].power(1); //enable individual sensor

            Serial.print(F("Sensor "));
            Serial.print(i);
            Serial.print(F(" Distance Reading: "));
            Serial.print(sensors[i].getDistance);
            Serial.println(F("cm"));

            sensors[i].power(0); //disable individual sensor
          }
      */




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
    getDistance( void ) , // return distance in cm.
    getVelocity( void ) ;


  uint8_t
    getHWversion( void ) ,
    getSWversion ( void ) ;




  /***********PRIVATE*************************/
private:

  uint8_t
    _readI2C( uint8_t regAddress );

  void
    _readI2C( uint8_t regAddress, int16_t numBytes, uint8_t destAry[] ),
    _writeI2C( uint8_t regAddress, uint8_t value );



  uint8_t const
    _I2CAddress ;


  LIDAR_LITE_MODE_E
      _mode;


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
