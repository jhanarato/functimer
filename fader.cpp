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
#include "fader.h"

Fader::Fader()
{
    // These are the default settings for our fader. This is
    // unlikely to change and I have avoided putting them
    // in the construtor parameters.
    increment = 5;
    maximum = 255;
    minimum = 0;
    level = minimum;
    isFadingIn = true;
}

void Fader::fadeIn()
{
    level += increment;
    if(level > maximum) setMaximum();
}

void Fader::fadeOut()
{
    level -= increment;
    if(level < minimum) setMinimum(); 
}

void Fader::fadeInAndOut()
{
    if(isMaximum()) isFadingIn = false;
    if(isMinimum()) isFadingIn = true;
    
    if(isFadingIn) 
        fadeIn();
    else
        fadeOut();
}

bool Fader::cycleComplete()
{
    return !isFadingIn && isMinimum();
}

void Fader::setMaximum()
{
    level = maximum;
}

void Fader::setMinimum()
{
    level = minimum;
}

void Fader::reset()
{
    setMinimum();
    isFadingIn = true;
}

bool Fader::isMaximum()
{
    return level == maximum;
}

bool Fader::isMinimum()
{
    return level == minimum;
}
    
int Fader::getLevel()
{
    return level;
}
