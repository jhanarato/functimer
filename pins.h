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

int timerOnTogglePin  = 14; // Analog 0
int longTimeTogglePin = 17; // Analog 3
int buzzerOnTogglePin = 19; // Analog 5

int timerOnLedPin  =   5;
int timeIsLongLedPin = 9;
int buzzerOnLedPin =   11;

int alarmBuzzerPin = 2;
