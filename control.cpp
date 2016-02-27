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

Controller::Controller()
{
    switches = new SwitchPanel();
    indicators = new IndicatorPanel();
    
    effects = new EffectsManager(switches, indicators);
    sessionTimer = new Timer();
}

void Controller::start()
{
    sessionTimer->setSeconds(3);
    
    effects->switchIndicator();
    effects->start();
}

void Controller::update()
{  
    switches->update();
    
    bool timerToggledOn = true;
    
    // The state of the timer-on switch has not changed.
    if(!switches->timerOnHasChanged) timerToggledOn = false;
    
    // The state of the timer-on switch is off.
    if(!switches->timerOn) timerToggledOn = false;
    
    if(timerToggledOn)
    {
        effects->switchIndicator();
        effects->start();
        
        sessionTimer->start();
    }
    
    sessionTimer->update();
    
    if(sessionTimer->isComplete())
    {
        effects->pulse();
        effects->start();
        sessionTimer->stop();
    }
    
    effects->update();
}
