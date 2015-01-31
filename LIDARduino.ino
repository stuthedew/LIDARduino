#include "LIDARduino1.h"
#include <I2C.h>

LIDAR_Lite_I2C l;

void setup(){
  Serial.begin(115200);
  //while (!Serial) ;

  l.begin();



  Serial.println(F("Starting LIDAR Test..."));
  Serial.print(F("Hardware Version: 0x"));
  Serial.println( l.getHWversion(), HEX );
  Serial.print(F("Software Version: 0x"));
  Serial.println( l.getSWversion(), HEX );
  Serial.println( l.getMaxCount(), HEX);
  delay(1000);
  l.setMaxCount(128);
  Serial.println( l.getMaxCount(), HEX);
  delay(2000);


}

void loop(){

  Serial.println(l.getDistance());
  Serial.println(l.getStatus(), BIN);
  Serial.println(l.getRSSI());

Serial.println();
delay(500);

}
