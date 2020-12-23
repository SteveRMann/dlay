# dlay
A fork of timeObj in https://github.com/leftCoast/LC_baseTools (Tools to make programming Arduinos easier.)

This library was inspired by timeObj from LeftCoast.
There are several other libraries in the LC repository that I have yet to investigate,
so I recommend a visit to https://github.com/leftCoast/LC_baseTools (Tools to make programming Arduinos easier.)

Backstory:<br>
I use the _arduinoOTA library_ a lot and it is not reliable when there is any blocking code in the loop.
Working with _millis()_ fixes it, but using millis() can get messy.  I found _timeObj_ and determined that
I could replace delay() altogether and hide the mess of millis. (And, it makes the code more readable).

_dlay()_ is a stripped-down fork of _timeObj_. If you need accuracy in micros, then use timeObj.h

## Useage:
### Initiate the object:
```dlay obj(int:time_ms,bool:start)```<br>
Where:<br>
   **time** is the optional delay time in ms (default 10ms), and<br>
   **start** is an optional boolean (default false).<br>
>**false**
means you have to manually start the timer using: `obj.start`<br>
>**true**
means that the timer starts immediately.<br>

### Async, (free-run):
```
if(obj.ding()){
  //handle the ding
  obj.start();
}
```

### One-shot:
```
if(obj.ding()){
  obj.stop();
  //handle the ding
}
```

**obj.stop()** resets the state of the timer. Otherwise, every call to ding() will be true with a time of zero.<br>
**obj.start** and obj.stop may be called from anywhere in loop().<br>
**obj.setTime**(float inMs, bool startNow) sets a new time. startNow is true or false.<br>
