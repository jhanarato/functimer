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

#ifndef PULSE_EFFECT_H
#define PULSE_EFFECT_H

#include "led_effect.h"
#include "timer.h"
#include "fader.h"

class PulseEffect : public LedEffect
{
public:
    PulseEffect(SwitchPanel* switches, IndicatorPanel* indicators);
    virtual void start();
    virtual void update();
private:
    Timer delayTimer;
    Fader fader;
};

#endif
