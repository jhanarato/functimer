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
#ifndef CONTROL_H
#define CONTROL_H

#include "indicators.h"
#include "switches.h"
#include "buzzer.h"
#include "timer.h"

// The time in milliseconds for the two
// session lengths chosen via the toggle switch.
const int LONG_TIME =   20000;
const int SHORT_TIME =  5000;

class Controller
{
    SwitchPanel* switches;
    IndicatorPanel* indicators;
    Timer* sessionTimer;
    
    // Controller for toggle-one.
    void startStop();
    
    // Controller for toggle-two.
    void longShort();
    
    // Controller for toggle-three.
    void buzzer();
    
public:
    Controller(SwitchPanel* switches, 
               IndicatorPanel* indicators, 
               Timer* sessionTimer);
                 
    void update();
};
#endif
