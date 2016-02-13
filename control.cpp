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
#include "control.h"

Controller::Controller(SwitchPanel* switches, 
                       IndicatorPanel* indicators, 
                       Timer* sessionTimer)
{
    this->switches = switches;
    this->indicators = indicators;
    this->sessionTimer = sessionTimer;
    
    startImmediately();
}

void Controller::startImmediately()
{
    switches->update();
    
    if(switches->timerOn)
        sessionTimer->start();
}

void Controller::update()
{
    // Check the state of the switches and act accordingly.
    switches->update();
    
    startStop();
    longShort();
    buzzer();
    
    // Check the session timer and act accordingly.
    checkTimer();
}

void Controller::startStop()
{
    if(switches->timerOn)
    {
        indicators->timerOn();
        
        if(switches->timerOnHasChanged)
        {
            sessionTimer->start();
        }
    }
    else
    {
        indicators->timerOff();
        
        if(switches->timerOnHasChanged)
        {
            sessionTimer->stop();
        }
    }
}

void Controller::longShort()
{
    if(switches->timeLong)
    {
        indicators->timeIsLong();
        sessionTimer->setDuration(LONG_TIME);
    }
    else
    {
        indicators->timeIsShort();
        sessionTimer->setDuration(SHORT_TIME);
    }
}

void Controller::buzzer()
{
    if(switches->buzzerOn)
    {
        indicators->buzzerOn();
        
        if(switches->buzzerOnHasChanged)
        {
        }
    }
    else
    {
        indicators->buzzerOff();
    }
}

void Controller::checkTimer()
{
    sessionTimer->update();
    
    if(sessionTimer->isComplete())
    {
        if(switches->buzzerOn)
        {
        }
        sessionTimer->stop();
    }
}
