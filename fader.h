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

// Fader class:
//
// This code came about when trying to figure out how to fade
// three leds in and out sequentially. While very simple to do
// within a for-loop with delay() calls to change the rate of 
// fading, the code would block. Since the fading was planned
// to be the effect when the timer completed, it became very
// difficult to implement such that the algorithm could be
// terminated by the timer on / off toggle.
//
// The timing code has been separated out into the Timer class
// and the actual setting of the LED light level using PWM
// is in the IndicatorPanel class. What is left here is
// the algorithm for changing the level incrementally.
//
// The usage is very simple, regardless. The fadeInAndOut()
// function can be called repeatedly, returning the level
// to which the PWM can be set. 
class Fader
{
    // These three values are taken from the for-loop
    // and related to the "dimness" we are calculating.
    // Imagine: for(int i = minimum; i <= maximum; i += increment)
    // to fade in. Fading out being a similar for-loop.
    int increment;
    int minimum;
    int maximum;
    
    // The current level of dimness.
    int level;
    
    // True if we're fading in, false if fading out.
    bool isFadingIn;
    
public:
    // When created we're ready to fade in from dark.
    Fader();

    // Increase light level. Will go no higher than maximum.
    void fadeIn();
    
    // Decrease light level. Will go no lower than minimum.
    void fadeOut();
    
    // Cycle fading in and out.
    void fadeInAndOut();
    
    // Set the level to maximum brightness.
    void setMaximum();
    
    // Set the level to absolute darkness.
    void setMinimum();
    
    // Start from darkness again.
    void reset();
    
    // The level is as high as possible.
    bool isMaximum();
    
    // The level is as low as possible.
    bool isMinimum();
    
    // TODO: Issue 5. Confirm this method is necessary.
    // If we have reached a minimum, should we automatically
    // be ready to fade back up again?
    bool cycleComplete();
    
    // Return the most recently computed level.
    int getLevel();
};
