/* 
This is the "official" arduino sketch for operating the "Functional Timer".

Copyright 2015 Bhikkhu Jhanarato 
  
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#ifndef TIMER_H
#define TIMER_H

enum timer_mode_t { STARTED, STOPPED, COMPLETED };

// Timer class:
// Implemented to allow for multiple timers to run concurrently. 
// Several timer objects can exist at once, keeping track of time
// without blocking the execution of other parts of the code. This
// overcomes the problem with using delay() to make code like blinking
// or fading LEDs work. It does, however, introduce a certain amount
// of complexity in the name of Doing Things Right.
class Timer
{
    // The time in millis when the timer begun. Set to zero
    // unless mode is STARTED.
    long startTime;
    
    // The time we are waiting in millis.
    long duration;
    
    // The current mode of the timer. Using an enum type
    // to manage a state machine.
    timer_mode_t mode;
    
public:
    // Create a new timer - neither started nor complete.
    Timer();
    
    // Set the time in millis between the 
    // start and finish of the timer. This can be called
    // at any time after object instatiation.
    void setMilliseconds(long milliseconds);
    
    // As per setMilliseconds() but duration is in seconds.
    void setSeconds(long seconds);
    
    // As per setMilliseconds() but duration is in minutes.
    void setMinutes(long minutes);
    
    // Returns true if the timer has started
    // but is not complete.
    bool isStarted();
    
    // Returns true if the timer has started
    // and the time has elapsed. Will return false when
    // the timer is restarted.
    bool isComplete();
    
    // Start the timer.
    void start();
    
    // Do not continue timing. 
    void stop();
    
    // Check to see if the set time has elapsed.
    // If so, isComplete() returns true until
    // the timer is restarted.
    void update();
};
#endif
