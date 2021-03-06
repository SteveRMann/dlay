/*
 *******************************************************************************
   blink_async

   In this example, two LEDs will blink at different rates. After 5 blinks ledA stops
   blinking, ledB continues blinking for a short time, then ledB stops and restarts
   ledA, blinking five more times.

Useage:
   Initiate the object:
     dlay obj(int:time_ms,bool:start)
     Where:
       time is the optional delay time in ms (default 10ms), and
       start is an optional boolean (default false) to begin timing immediately,
             or false, which means you have to manually start the timer: obj.start.

   //Async, free-run:
     if(obj.ding()){
       //handle the ding
       obj.start();
     }

   //One-shot:
     if(obj.ding()){
       obj.stop();
       //handle the ding
     }

   obj.stop() resets the state of the timer. Otherwise, every call to ding() will be true with a time of zero.
   obj.start and obj.stop may be called from anywhere in loop().


 *******************************************************************************
*/


#define LED_OFF LOW
#define LED_ON HIGH

#define ledA D5
#define ledB D6

#include <dlay.h>
dlay aTimer(500, false);               //Initialize an object, 500ms, no autostart.
dlay bTimer(400, false);
bool ledaState;                            //Save the state of the LEDs
bool ledbState;


void setup() {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println (F("nBlink2.ino"));

  pinMode(ledA, OUTPUT);          //Initialize the digital pins as output.
  pinMode(ledB, OUTPUT);
  digitalWrite(ledA, LED_OFF);    //Turn the LEDs off.
  digitalWrite(ledB, LED_OFF);    
  ledaState = false;
  ledbState = false;

  //aTimer.setTime(500);                //You can use setTime to change the delay time.
  aTimer.start();                       //Fire up the timers
  bTimer.start();                       //Fire up the timers
}


void loop() {
  static int i = 5;                    //Blink count
  static int j = 10;  

  if (aTimer.ding()) {                 //If the timer has finished,
    if (ledaState) {                   //toggle the LED.
      digitalWrite(ledA, LED_OFF);     //Turn the LED off.
      ledaState = false;               //Save the LED state
      i--;                             //Count the blinks
    } else {
      digitalWrite(ledA, LED_ON);      //Turn the LED on.
      ledaState = true;
    }
    aTimer.start();                    //Restart the timer.
  }


  if (bTimer.ding()) {                 //If the timer has finished,
    if (ledbState) {                   //toggle the LED.
      digitalWrite(ledB, LED_OFF);     //Turn the LED off.
      ledbState = false;               //Save the LED state
      j--;                             //Count the blinks
    } else {
      digitalWrite(ledB, LED_ON);      //Turn the LED on.
      ledbState = true;
    }
    bTimer.start();                    //Restart the timer.
  }


  //Stop after x blinks.
  if (i <= 0) {
    aTimer.stop();
  }

  //Stop ledB after 5 blinks and restart ledA blinking five more times.
  if (j <= 0) {
    bTimer.stop();
    aTimer.start();
    i=5;
    j=1;    // So that we don't keep falling into this if statement, restarting aTimer.
  }

}
