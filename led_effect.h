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

#ifndef LED_EFFECT_H
#define LED_EFFECT_H

#include "indicators.h"
#include "switches.h"

// LedEffect class.
// The base class for effects that control the
// LED panel on the timer.
class LedEffect
{
public:
    LedEffect(SwitchPanel* switches, IndicatorPanel* indicators) 
              : switches(switches), indicators(indicators) {}
              
    virtual void start();
    virtual void update();
    
    SwitchPanel* switches; 
    IndicatorPanel* indicators;
};

#endif
