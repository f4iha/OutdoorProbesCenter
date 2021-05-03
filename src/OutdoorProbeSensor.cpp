#include <Arduino.h>
#include <Esp.h>
#include "driver/adc.h"
#include <esp_wifi.h>
#include <esp_bt.h>

#include "settings.h"
#include "WifiNetwork.h"
#include "MQTT.h"
#include "Light.h"
#include "Wind.h"

unsigned long Snooze_Time = 300000;

unsigned long Start_Time;
unsigned long Time_Elapsed;

void intervalSendingData()
{
  Time_Elapsed = millis() - Start_Time;

  if (Time_Elapsed >= Snooze_Time)
  {
    measureLight();
    connect_wifi();
    connect_mqtt();
    char s[300];
    snprintf(s, sizeof(s), "{ \"max_wind\" : %f, \"avg_wind\" : %f, \"light\" : %i}", MaxWindSpeed, (SumWindSpeed / WindMeasureCounter), Light);
    Serial.println(s);
    pushData(mqttTopic, s);
    client.disconnect();
    close_wifi();
    Start_Time = millis();
    resetWindData();
  }
}

void setup()
{
  Serial.begin(9600);
  // power consumption impact : reduce CPU + shutdown bluetooth 
  setCpuFrequencyMhz(80);
  btStop();
  esp_bt_controller_disable();

  Start_Time = millis();

  connect_wifi();
  client.setServer(mqttServer, 1883);
  close_wifi();
  Serial.println("Setup fulling done");
}

void loop()
{
  measureWind();
  intervalSendingData();
}