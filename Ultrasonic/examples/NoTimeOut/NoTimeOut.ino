// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// Rev.4 (06/2012)
// J.Rodrigo ( www.jra.so )
// more info at www.ardublog.com
//
// Pin Connect
//   Arduino      HR-SC04
//   5V-----------VCC
//   D9-----------Trig PIN
//   D7-----------Trig PIN
//   D8-----------Echo PIN
//   GND----------GND

#include <Ultrasonic.h>

Ultrasonic ultrasonic(9,8,CM,20); // (Trig PIN,Echo PIN,CM or INC,Distance)

void setup() {
  Serial.begin(9600);
  ultrasonic.onReset(7);  // (Reset PIN)
}

void loop()
{
  Serial.print(ultrasonic.Ranging(CM)); // Unit: CM or INC
  Serial.println(" cm" ); // milliseconds
  delay(100);
}
