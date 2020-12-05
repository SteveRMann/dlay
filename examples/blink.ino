/*
  Blink

  This is the example blink.ino sketch using my dlay library. Basically a stripped-down version of
  timeObj in LC_BaseTools:
  https://github.com/leftCoast/LC_baseTools (Tools to make programming Arduinos easier.)

  If you need accuracy in micros, then use timeObj.h

  This example turns an LED on for one second, then off for one second, repeatedly.
  
*/

#include "dlay.h"
dlay aDelay(1000, true);              // Declare an object of dlay and start it



void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}



void loop() {
  static bool LEDSTATE = true;              //Save the current state of the LED
  if (aDelay.ding()) {
    digitalWrite(LED_BUILTIN, LEDSTATE);    // turn the LED off by making the voltage LOW
    LEDSTATE = !LEDSTATE;                   //Toggle the LEDSTATE for the next time
    aDelay.start();                         //Restart the delay timer
  }
}
