#include <Arduino.h>

int Light;

void measureLight()
{
  Light = analogRead(SensorPhotoPin);
}