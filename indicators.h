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

/* 
The driver for the panel of three LEDs indicating the following:
    - The timer is on (counting down) or off.
    - The length of time is long or short.
    - The buzzer will sound when the time is complete.
*/
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
