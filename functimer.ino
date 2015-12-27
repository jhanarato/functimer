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

void setup()
{
    fader.setMinimum();
}

void loop()
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



