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
#include "buzzer.h"

Buzzer::Buzzer()
{
    pinMode(alarmBuzzerPin, OUTPUT);
    
    buzzerTimer.setMilliseconds(50); // Audible and brief.
}

void Buzzer::start()
{
    buzzerTimer.start();
    digitalWrite(alarmBuzzerPin, HIGH);
}

void Buzzer::update()
{
    buzzerTimer.update();
    
    if(buzzerTimer.isComplete())
    {
        digitalWrite(alarmBuzzerPin, LOW);
        buzzerTimer.stop();
    }
}
