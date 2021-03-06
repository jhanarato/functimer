/* 
This is the "official" arduino sketch for operating the "Functional Timer".

Copyright 2015, 2016 Bhikkhu Jhanarato 
  
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
#include "effects_manager.h"

class Controller
{
    // Hardware
    SwitchPanel* switches;
    IndicatorPanel* indicators;
    Buzzer* buzzer;
    
    // Light effects.
    EffectsManager* effects;
    
    // Keep track of time. I was using a pointer with
    // heap allocation, but ran into a compiler bug.
    Timer sessionTimer;
    
    // Check for events.
    void onOffToggled();
    void longShortToggled();
    void buzzerOnToggled();
    void sessionEnded();
    
public:
    Controller();
    void start();    
    void update();
};
#endif
