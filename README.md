# dlay
A fork of timeObj in https://github.com/leftCoast/LC_baseTools (Tools to make programming Arduinos easier.)

This library was inspired by timeObj from LeftCoast.
There are several other libraries in the LC repository that I have yet to investigate,
so I recommend a visit to https://github.com/leftCoast/LC_baseTools (Tools to make programming Arduinos easier.)

Backstory:
I use the arduinoOTA library a lot and it is not reliable when there is any blocking code in the loop.
Working with millis fixes it, but using millis() can get messy.  I found timeObj and determined that
I could replace delay() altogether and hide the mess of millis. (It makes the code more readable).

dlay() is a stripped-down fork of timeObj. If you need accuracy in micros, then use timeObj.h

*   Useage:
   Initiate the object:
     dlay obj(int:time,bool:start)
     Where:
       time is the optional delay time in ms (default 10ms), and
       start is an optional boolean (default true) to begin timing immediately,
             or false, which means you have to manually start the timer: obj.start.

   Async, free-run:
     if(obj.ding()){
       //handle the ding
       obj.start();
     }

   One-shot:
     if(obj.ding()){
       //handle the ding
     }

     obj.start and obj.stop may be called from anywhere in loop().
