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

#include "switch_indicator_effect.h"

SwitchIndicatorEffect::SwitchIndicatorEffect(SwitchPanel* switches, IndicatorPanel* indicators)
{
    this->switches = switches;
    this->indicators = indicators;
}

void SwitchIndicatorEffect::update()
{
    switches->update();
    
    if(switches->timerOn)
        indicators->timerOn();
    else
        indicators->timerOff();
    
    if(switches->timeLong)
        indicators->timeIsLong();
    else
        indicators->timeIsShort();
    
    if(switches->buzzerOn)
        indicators->buzzerOn();
    else
        indicators->buzzerOff();
}
