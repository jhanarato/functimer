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

#include "indicators.h"
#include "switches.h"
#include "buzzer.h"
#include "timer.h"
#include "control.h"

// Defer instantiation to setup() function - put them on the heap.
IndicatorPanel* indicators = 0;
SwitchPanel* switches = 0;
Timer* sessionTimer = 0;

void setup()
{
    indicators = new IndicatorPanel();
    switches = new SwitchPanel();
    sessionTimer = new Timer();
    
    // If the device is turned on with the session
    // timer switched on, start the session immediately.
    // TODO: Defer this functionality to the control class.
    switches->update();
    if(switches->timerOn)
        sessionTimer->start();
}

void loop()
{
    switches->update();
    
    control(switches, indicators, sessionTimer);

    sessionTimer->update();
    
    if(sessionTimer->isComplete())
    {
        if(switches->buzzerOn)
        {
            // TODO: Perhaps Buzzer could be a simple function
            // rather than a class.
            Buzzer buzzer;
            buzzer.buzz();
        }
        sessionTimer->stop();
    }         
}
