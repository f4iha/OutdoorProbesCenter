#include <Arduino.h>
#include "settings.h"

int InterruptCounter = 0;
float WindSpeed;
float MaxWindSpeed = 0;
float SumWindSpeed = 0;
int WindMeasureCounter = 0;

void resetWindData()
{
  SumWindSpeed = 0;
  WindMeasureCounter = 0;
  MaxWindSpeed = 0;
}
void countup()
{
  InterruptCounter++;
}
void measureWind()
{
  InterruptCounter = 0;
  attachInterrupt(digitalPinToInterrupt(SensorPin), countup, RISING);
  delay(1000 * RecordTime);
  detachInterrupt(digitalPinToInterrupt(SensorPin));
  WindSpeed = (float)InterruptCounter / (float)RecordTime * 2.4;
  if (MaxWindSpeed < WindSpeed)
  {
    MaxWindSpeed = WindSpeed;
  }
  SumWindSpeed += WindSpeed;
  WindMeasureCounter++;
}

