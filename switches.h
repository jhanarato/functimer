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
#ifndef SWITCHES_H
#define SWITCHES_H

#include "timer.h"

// SwitchPanel class:

// This is the driver for the panel of toggle switches. We can:
//    - Turn the timer on and off.
//    - Choose between long and short meditation sessions.
//    - Set the piezo buzzer to beep when the session ends.
// Issue #7 on github discusses debounce.
class SwitchPanel
{
    Timer debounceTimer;
public:
    // Set up panel, using pins defined in pins.h. Includes
    // enabling of pull-up resistors and calls update()
    // immediately.
    SwitchPanel();
    
    // Check the position of the three switches and check
    // whether anything has changed.
    void update();
    
    // Each are true if the relevant switch is toggled on.
    bool timerOn;
    bool timeLong;
    bool buzzerOn;
    
    // Each are true if the toggle state has changed
    // since update() was last called.
    bool timerOnHasChanged;
    bool timeLongHasChanged;
    bool buzzerOnHasChanged;
};
#endif
