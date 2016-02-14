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
    mode = STOPPED;
}

void Timer::setMilliseconds(int milliseconds)
{
    this->duration = milliseconds;
}

void Timer::setSeconds(int seconds)
{
    this->duration = seconds * 1000;
}

void Timer::setMinutes(int minutes)
{
    this->duration = minutes * 60 * 1000;
}

bool Timer::isStarted()
{
    return mode == STARTED;
}

bool Timer::isComplete()
{
    return mode == COMPLETED;
}

void Timer::start()
{
    mode = STARTED;
    startTime = millis();
}

void Timer::stop()
{
    mode = STOPPED;
    startTime = 0;
}

void Timer::update()
{
    if(mode == STARTED)
    {
        int now = millis();
        
        if(now >= startTime + duration)
        {
            mode = COMPLETED;
            startTime = 0;
        }
    }
}
