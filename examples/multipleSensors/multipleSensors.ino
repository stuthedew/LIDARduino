#include <LIDARduino.h>

#define NUM_SENSORS 4  // Number of LIDAR_Lites to read.

LIDAR_Lite_I2C sensors[ NUM_SENSORS ]; // Could be LIDAR_Lite_PWM also

uint8_t sensorPwrPins[] = {6, 7, 8, 9}; /*Hook up each arduino pin to each
                                          PWR_EN wire of LIDAR Lites (PWR_EN
                                          wire adjacent to Red 5V wire ) using
                                          1K - 10K resistor in series. */
void setup(){
  for(int i = 0; i < NUM_SENSORS; i++){ // disable all sensors
    sensors[i].begin();
    sensors[i].enablePowerCtrl( sensorPwrPins[i] );
    sensors[i].power(0);
  }
}

void loop(){

  for(int i = 0; i < NUM_SENSORS; i++){ // Read from each sensor individually
    sensors[i].power(1); //enable individual sensor

    Serial.print(F( "Sensor  "));
    Serial.print(i);
    Serial.print(F( " Distance Reading: " ));
    Serial.print(sensors[i].getDistance());
    Serial.println(F( " cm " ));

    sensors[i].power(0); //disable individual sensor
  }
delay(500);

}
