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

IndicatorPanel indicators;
SwitchPanel switches;
Buzzer buzzer = Buzzer(300);
Fader fader;

Timer testTimer;
bool ledOn;

void setup()
{
    fader.setMinimum();
    testTimer.setDuration(1000); // Do something every second.
    testTimer.start();
    ledOn = true; // Start with light on.
}

// This runs when the session is complete.
void finishEffect()
{
    while(!fader.cycleComplete())
    {
        fader.fadeInAndOut();
        int level = fader.getLevel();
        indicators.buzzerDim(level);
        delay(30);
    }
    
    fader.reset();
    
    while(!fader.cycleComplete())
    {
        fader.fadeInAndOut();
        int level = fader.getLevel();
        indicators.longShortDim(level);
        delay(30);
    }
    
    fader.reset();
    
    while(!fader.cycleComplete())
    {
        fader.fadeInAndOut();
        int level = fader.getLevel();
        indicators.timerDim(level);
        delay(30);
    }
    
    fader.reset();
}

void flashWithTimerEffect()
{
    testTimer.update();
    if(testTimer.isComplete())
    {
        if(ledOn)
        {
            indicators.allOn();
        }
        else
        {
            indicators.allOff();
        }
        ledOn = !ledOn;
        testTimer.start();
    }
}

// Keep track of the state of the device as per issue #2.
// This could, perhaps, be refactored when happy with
// the functionality.
void manageState()
{
    if(switches.timerOn)
    {
        indicators.timerOn();
        
        if(switches.timerOnHasChanged)
        {
            // TODO: Start the session timer.
        }
        
    }
    else
    {
        indicators.timerOff();
        
        if(switches.timerOnHasChanged)
        {
            // TODO: Cancel the session timer.
        }
    }
    
    if(switches.timeLong)
    {
        indicators.timeIsLong();
        
        if(switches.timeLongHasChanged)
        {
            // TODO: Change session timer to long duration.
        }     
    }
    else
    {
        indicators.timeIsShort();
        
        if(switches.timeLongHasChanged)
        {
            // TODO: Change the session timer to short duration.
        }
    }
    
    if(switches.buzzerOn)
    {
        indicators.buzzerOn();
        
        if(switches.buzzerOnHasChanged)
        {
            buzzer.buzz(); // Auditory indication of beep setting.
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
    delay(50); // Debounce. See issue #7.
    manageState();    
}



