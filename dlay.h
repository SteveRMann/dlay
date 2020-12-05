#ifndef dlay_h
#define dlay_h

// Inspired by timeObj in LC_BaseTools 
// There are several other libraries in the LC repository that I have yet to investigate.
// Visit https://github.com/leftCoast/LC_baseTools (Tools to make programming Arduinos easier.)
//
// This library is basically timeObj stripped down to just the timer functions.



class dlay {
  public:
    dlay(float inMs = 10, bool startNow = true);
    virtual ~dlay(void);

    void setTime(float inMs, bool startNow = false);      // Change the time duration for next start..
    virtual void start(void);                             // Start the timer "now".
    ///virtual void stepTime(void);                          // Restart the timer from last end time.
    bool ding(void);                                      // Timer expired?
    ///unsigned long getTime(void);                          // How long does this go for?
    ///float getFraction(void);                              // Fuel gauge. What fraction of time is left.
    void stop(void);                                      // Reset to the preStart state. (Reset and stop are identical)
    ///void reset(void);                                     // Reset to the preStart state.
    ///void printState(void);                                // Debugging.

  private:
    enum dlayStates { preStart, running, expired };

    dlayStates ourState;
    unsigned long waitTime;
    unsigned long startTime;
    unsigned long endTime;
};

#endif
