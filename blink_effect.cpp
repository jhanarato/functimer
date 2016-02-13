/* 
Copyright 2016 Bhikkhu Jhanarato 
  
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

#include "blink_effect.h"

BlinkEffect::BlinkEffect(SwitchPanel* switches, IndicatorPanel* indicators)
{
    this->switches = switches;
    this->indicators = indicators;
    ledsOn = true;
    delayTimer.setDuration(3000);
}

void BlinkEffect::start()
{
    delayTimer.start();
}

void BlinkEffect::update()
{
    delayTimer.update();
    
    if(delayTimer.isComplete())
    {
        if(ledsOn)
        {
            indicators->timerOn();
            indicators->timeIsLong();
            indicators->buzzerOn();
        }
        else
        {
            indicators->timerOff();
            indicators->timeIsShort();
            indicators->buzzerOff();
        } 
          
        ledsOn = !ledsOn;  
        delayTimer.start();
    }
}
