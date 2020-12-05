#include "dlay.h"
#include <Arduino.h>

#define  MAX_MICROS  4000000 // Could be a little more, but 4,000,000 (4 seconds) is fine. (This * 1,000 = micros)

// Our lovely constructor.
dlay::dlay(float inMs, bool startNow) {
  startTime = 0;              // Just some default.
  endTime = 0;                // And another default.
  ourState = preStart;        // We are sitting on pre Start state.
  setTime(inMs, startNow);    // This sets startTime and endTime. Maybe starts things up?
}


// And wonderful destructor..
dlay::~dlay(void) { }



// Test- converts input to micros.
void dlay::setTime(float inMs, bool startNow) {
  waitTime = inMs;
  ourState = preStart;              // At this point we are in preStart mode..
  if (startNow) start();            // If they passed in true for startNow.. Start now!
}



// Start the timer
void dlay::start(void) {
  startTime = millis();               // Save the current milliseconds.
  endTime = startTime + waitTime;     // Calculate the end time.
  ourState = running;                 // And we are running!
}



/* ----------- dlay() -----------
  Has the timer expired?
  Well, if it hasn't been started then no.
  If its running then lets calculate if its finished. And return that if it has expired, then yes.
*/
bool dlay::ding(void) {
  switch (ourState) {                           // If the state is...
    case preStart : return false;               // preStarted, not expired, return false.
    case running :                              // Started and running our timer, return true when we expire.
      if (millis() - startTime > waitTime) {  // If our time has expired..
        ourState = expired;                   // We are now expired.
        return true;                          // Return true!
      } else {                                // Else, we are running but our time has NOT expired..
        return false;                         // Return false!
      }
    case expired : return true;                 // If we are expired, return true.
  }
  return false;                                 // Just to shut up compiler.
}


// This brings your timer back to the preStart state. Ready for a start() call. Does not
// change the delay time already set in the object. Therefore its ready to start again
// when you need it. You don't need to use this call. ITs only used if you want to shut
// off the timer to be restarted at a later time.

void dlay::stop(void) {
  ourState = preStart;
}
