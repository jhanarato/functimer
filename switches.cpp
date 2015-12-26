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
#include "switches.h"
#include "pins.h"

SwitchPanel::SwitchPanel()
{
    pinMode(timerOnTogglePin,    INPUT);
    pinMode(timeIsLongTogglePin, INPUT);
    pinMode(buzzerOnTogglePin,   INPUT);
    
    // Turn on pull-up resistors
    digitalWrite(timerOnTogglePin,    HIGH);
    digitalWrite(timeIsLongTogglePin, HIGH);
    digitalWrite(buzzerOnTogglePin,   HIGH);
    
    update();
}
void SwitchPanel::update()
{
    // NB: Bounce not handled here.
    bool newTimerOn    = digitalRead(timerOnTogglePin)    == HIGH;
    bool newTimeLong = digitalRead(timeIsLongTogglePin) == HIGH;
    bool newBuzzerOn   = digitalRead(buzzerOnTogglePin)   == HIGH;
    
    timerOnHasChanged =  timerOn != newTimerOn;
    timeLongHasChanged = timeLong != newTimeLong;
    buzzerOnHasChanged = buzzerOn != newBuzzerOn;
    
    timerOn = newTimerOn;
    timeLong = newTimeLong;
    buzzerOn = newBuzzerOn;
}
