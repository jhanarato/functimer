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

#ifndef INDICATORS_H
#define INDICATORS_H

// IndicatorPanel class:
// Represents the three LED panel on the timer. Simply
// make an instance and turn LEDs on and off and dim them
// with PWM.
class IndicatorPanel
{ 
public:
    IndicatorPanel();
    
    void timerOn();
    void timerOff();
    void timerDim(int dimness);

    void timeIsLong();
    void timeIsShort();
    void longShortDim(int dimness);
        
    void buzzerOn();
    void buzzerOff();
    void buzzerDim(int dimness);
    
    void allOn();
    void allOff();
    void allDim(int dimness);
};

#endif
