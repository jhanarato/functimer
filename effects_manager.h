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
#ifndef EFFECTS_MANAGER_H
#define EFFECTS_MANAGER_H

#include "led_effect.h"
#include "pulse_effect.h"
#include "blink_effect.h"
#include "off_effect.h"
#include "switch_indicator_effect.h"

class EffectsManager 
{
    SwitchPanel* switches;
    IndicatorPanel* indicators;
    
    LedEffect* currentEffect;
    PulseEffect* pulseEffect;
    BlinkEffect* blinkEffect;
    OffEffect* offEffect;
    SwitchIndicatorEffect* switchIndicatorEffect;
    
public:
    EffectsManager(SwitchPanel* switches, 
                   IndicatorPanel* indicators); 
                   
    void start();
    void update();
    void pulse();
    void blink();
    void off();
    void switchIndicator();               
};

#endif
