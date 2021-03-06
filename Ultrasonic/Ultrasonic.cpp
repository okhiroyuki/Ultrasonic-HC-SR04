// Ultrasonic - Library for HR-SC04 Ultrasonic Ranging Module.
// GitHub: https://github.com/JRodrigoTech/Ultrasonic-HC-SR04
// #### LICENSE ####
// This code is licensed under Creative Commons Share alike
// and Attribution by J.Rodrigo ( http://www.jrodrigo.net ).

#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int TP, int EP)
{
   pinMode(TP,OUTPUT);
   pinMode(EP,INPUT);
   Trig_pin=TP;
   Echo_pin=EP;
   Time_out=3000;  // 30ms = 5 m // 3ms = 50cm
   Reset_pin=0;
}

Ultrasonic::Ultrasonic(int TP, int EP, long TO)
{
   pinMode(TP,OUTPUT);
   pinMode(EP,INPUT);
   Trig_pin=TP;
   Echo_pin=EP;
   Time_out=TO;
   Reset_pin=0;
}

void Ultrasonic::setMaxDistance(int sys, int max_dist)
{
  if(sys){ //CM
    Time_out=max_dist*2*29;
  }else{  //INC
    Time_out=max_dist*2*79;
  }
}

void Ultrasonic::setResetPin(int RP)
{
  pinMode(RP,OUTPUT);
  Reset_pin = RP;
}

long Ultrasonic::Timing()
{
  digitalWrite(Trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig_pin, LOW);
  duration = pulseIn(Echo_pin,HIGH,Time_out);
  if ( duration == 0 ) {
    duration = Time_out;
    if(Reset_pin != 0){
      digitalWrite(Reset_pin,HIGH);
      delay(25);
      digitalWrite(Reset_pin,LOW);
      delay(225);
    }
  }
  return duration;
}

long Ultrasonic::Ranging(int sys)
{
  Timing();
  if (sys) {
	  distacne_cm = duration /29 / 2 ;
	  return distacne_cm;
  } else {
	  distance_inc = duration / 74 / 2;
	  return distance_inc;
  }
}
