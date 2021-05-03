#include <Arduino.h>
#include "settings.h"

// definition of the various variable used during the measurements
int InterruptCounter = 0;
float WindSpeed;
float MaxWindSpeed = 0;
float SumWindSpeed = 0;
int WindMeasureCounter = 0;

// Reset the measurements params
void resetWindData()
{
  SumWindSpeed = 0;
  WindMeasureCounter = 0;
  MaxWindSpeed = 0;
}

// increment the interruption
void countup()
{
  InterruptCounter++;
}

// measurement of wind speed during the defined period of time
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

