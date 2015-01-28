#include "LIDARduino1.h"
#include <I2C.h>

LIDAR_Lite_I2C l;

void setup(){
  Serial.begin(115200);
  while (!Serial) ; //only needed for Arduino Leonardo (Atmega 32u4)

  l.begin();
  Serial.println(F("Starting Easy Distance Reading..."));

  Serial.print(F("Hardware Version: 0x"));
  Serial.println( l.getHWversion() );
  Serial.print(F("Software Version: 0x"));
  Serial.println( l.getHWversion() );


}

void loop(){


  Serial.print(l.easyDistance());
  Serial.println(F("cm"));
  delay(500);

}
