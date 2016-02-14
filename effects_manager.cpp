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

#include "effects_manager.h"

EffectsManager::EffectsManager(SwitchPanel* switches, 
                               IndicatorPanel* indicators) 
{
    this->switches = switches;
    this-> indicators = indicators;
    
    pulseEffect = new PulseEffect(switches, indicators);
    blinkEffect = new BlinkEffect(switches, indicators);
    offEffect = new OffEffect(switches, indicators);
    switchIndicatorEffect = new SwitchIndicatorEffect(switches, indicators);
    
    // Default effect
    currentEffect = switchIndicatorEffect;
}

void EffectsManager::start()
{
    currentEffect->start();
}

void EffectsManager::update()
{
    currentEffect->update();
}

void EffectsManager::pulse()
{
    currentEffect = pulseEffect;
}

void EffectsManager::blink()
{
    currentEffect = blinkEffect;
}

void EffectsManager::off()
{
    currentEffect = offEffect;
}
void EffectsManager::switchIndicator()
{
    currentEffect = switchIndicatorEffect;
}
