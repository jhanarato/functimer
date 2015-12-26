#include "indicators.h"

IndicatorPanel indicators;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    //indicators.allOn();
    delay(3000);
    indicators.allOff();
    delay(3000);
    
}
