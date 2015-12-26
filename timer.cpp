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
#include "Arduino.h"
#include "pins.h"
#include "timer.h"

Timer::Timer()
{
    startTime = 0;
    duration = 0;
    
    started = false;
    complete = false;
}

void Timer::setDuration(int duration)
{
    this->duration = duration;
}

bool Timer::isComplete()
{
    return complete;
}

void Timer::start()
{
    started = true;
    complete = false;
    
    startTime = millis();
}

void Timer::update()
{
    int now = millis();
    
    if(now >= startTime + duration)
    {
        complete = true;
        started = false;
        startTime = 0;
    }
}
