#include "LIDARduino1.h"
#include <I2C.h>

LIDAR_Lite_I2C l;

void setup(){
  Serial.begin(115200);
  while (!Serial) ;

  l.begin();
  Serial.println(F("Starting LIDAR Test..."));

  Serial.print(F("Hardware Version: 0x"));
  Serial.println( l.getHWversion() );
  Serial.print(F("Software Version: 0x"));
  Serial.println( l.getHWversion() );
  l.enableVelocity( LL_10_MS );

}

void loop(){


Serial.println(l.getVelocity());
delay(500);

}
