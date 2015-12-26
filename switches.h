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
The driver for the panel of toggle switches. We can:
    - Turn the timer on and off.
    - Choose between long and short meditation sessions.
    - Set the piezo buzzer to beep when the session ends.
    
NOTE: I'm not sure if I can get this to work without some kind of 
      debounce. I'll test that later.
*/

class SwitchPanel
{
public:
    SwitchPanel();
    
    void update();
    
    bool timerOn;
    bool timeLong;
    bool buzzerOn;
    
    bool timerOnHasChanged;
    bool timeLongHasChanged;
    bool buzzerOnHasChanged;
};
