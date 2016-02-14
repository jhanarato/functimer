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
    
    effects->switchIndicator();
    effects->start();
    
    sessionTimer = new Timer();
    sessionTimer->setMilliseconds(5000);
    sessionTimer->start();
}

void Controller::update()
{  
    switches->update();
    sessionTimer->update();
    
    if(sessionTimer->isComplete())
    {
        effects->pulse();
        effects->start();
        sessionTimer->stop();
    }
    
    effects->update();
}

bool Controller::sessionStarted()
{
    // Bug - for some reason this always returns true;
    switches->update();
    return switches->timerOn && switches->timerOnHasChanged;
}
