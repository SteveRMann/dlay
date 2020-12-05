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

## Useage:
### Initiate the object:<br>
```dlay obj(int:time_ms,bool:start)```
Where:
   time is the optional delay time in ms (default 10ms), and
   start is an optional boolean (default false) to begin timing immediately,
   or false, which means you have to manually start the timer: <br>
```obj.start```

   ### //Async, free-run:<br>
     if(obj.ding()){
       //handle the ding
       obj.start();
     }

   ### //One-shot:<br>
     if(obj.ding()){
       obj.stop();
       //handle the ding
     }

   obj.stop() resets the state of the timer. Otherwise, every call to ding() will be true with a time of zero.
   obj.start and obj.stop may be called from anywhere in loop().
   
   Some basic Git commands are:
```
git status
git add
git commit
```
