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

#include "control.h"

// Debug settings.
const int LONG_SESSION_SECONDS = 20;
const int SHORT_SESSION_SECONDS = 10;

const int LONG_SESSION_MINUTES = 2;
const int SHORT_SESSION_MINUTES = 1;

Controller::Controller()
{
    switches = new SwitchPanel();
    indicators = new IndicatorPanel();
    buzzer = new Buzzer();
    
    effects = new EffectsManager(switches, indicators);
}

void Controller::start()
{    
    switches->start();
    
    effects->switchIndicator();
    effects->start();

    sessionTimer.setMinutes(SHORT_SESSION_MINUTES);
    // sessionTimer.setSeconds(SHORT_SESSION_SECONDS);
    
    sessionTimer.stop();
}

void Controller::update()
{     
    switches->update();
    sessionTimer.update();
    
    onOffToggled();
    longShortToggled();
    buzzerOnToggled();
    sessionEnded();
    
    effects->update();
    buzzer->update();
}

void Controller::onOffToggled()
{
    if(switches->timerOnHasChanged)
    {
        if(switches->timerOn)
        {
            effects->switchIndicator();
            effects->start();
            
            sessionTimer.start();
        }
        else
        {
            effects->switchIndicator();
            effects->start();
            
            sessionTimer.stop();
        }
    }
}

void Controller::longShortToggled()
{
    if(switches->timeLongHasChanged)
    {
        if(switches->timeLong)
        {
            sessionTimer.setMinutes(LONG_SESSION_MINUTES);
            // sessionTimer.setSeconds(LONG_SESSION_SECONDS);
        }
        else
        {
            sessionTimer.setMinutes(SHORT_SESSION_MINUTES);
            // sessionTimer.setSeconds(SHORT_SESSION_SECONDS);              
        }
    }
}

void Controller::buzzerOnToggled()
{
    if(switches->buzzerOnHasChanged)
    {
        if(switches->buzzerOn)
        {
            buzzer->start();
        }
    }
}

void Controller::sessionEnded()
{
    if(sessionTimer.isComplete())
    {
        effects->pulse();
        effects->start();
        sessionTimer.stop();
        
        if(switches->buzzerOn)
        {
            buzzer->start();
        }
    }
}
