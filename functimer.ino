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
#include "fader.h"

// The time in milliseconds for the two
// session lengths chosen via the toggle switch.
const int LONG_TIME =   20000;
const int SHORT_TIME =  5000;

IndicatorPanel indicators;
SwitchPanel switches;
Buzzer buzzer = Buzzer();
Fader fader;

// Keep track of the the time for the given
// session - that is, the time between starting
// and indicating the end of the meditation
// session.
Timer sessionTimer;

void setup()
{
    // If the device is turned on with the session
    // timer switched on, start the session immediately.
    switches.update();
    if(switches.timerOn)
        sessionTimer.start();
}

// Check the physical controls and act accordingly.
void control()
{
    if(switches.timerOn)
    {
        indicators.timerOn();
        
        if(switches.timerOnHasChanged)
        {
            sessionTimer.start();
        }
    }
    else
    {
        indicators.timerOff();
        
        if(switches.timerOnHasChanged)
        {
            sessionTimer.stop();
        }
    }
    
    if(switches.timeLong)
    {
        indicators.timeIsLong();
        sessionTimer.setDuration(LONG_TIME);
    }
    else
    {
        indicators.timeIsShort();
        sessionTimer.setDuration(SHORT_TIME);
    }
    
    if(switches.buzzerOn)
    {
        indicators.buzzerOn();
        
        if(switches.buzzerOnHasChanged)
        {
            buzzer.buzz();
        }
    }
    else
    {
        indicators.buzzerOff();
    }
}

void loop()
{
    switches.update();
    
    control();

    sessionTimer.update();
    
    if(sessionTimer.isComplete())
    {
        if(switches.buzzerOn)
        {
            buzzer.buzz();
        }
        sessionTimer.stop();
    }         
}
