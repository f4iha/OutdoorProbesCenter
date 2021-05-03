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

unsigned long Start_Time;
unsigned long Time_Elapsed;
char strJson[300];

void intervalSendingData()
{
  Time_Elapsed = millis() - Start_Time;

  // once defined time between 2 data push is elapsed
  if (Time_Elapsed >= Snooze_Time)
  {
    // measuring current light level
    measureLight();
    // connecting network and mqtt server
    connect_wifi();
    connect_mqtt();

    // preparing and pushing the content as JSON
    snprintf(strJson, sizeof(strJson), "{ \"max_wind\" : %f, \"avg_wind\" : %f, \"light\" : %i}", MaxWindSpeed, (SumWindSpeed / WindMeasureCounter), Light);
    Serial.println(strJson);
    pushData(mqttTopic, strJson);

    // disconnecting network and mqtt server
    close_mqtt();
    close_wifi();

    // reset to default measure values
    Start_Time = millis();
    resetWindData();
  }
}

// power consumption impact : reduce CPU + shutdown bluetooth 
void pwr_optim() {
  setCpuFrequencyMhz(80);
  btStop();
  esp_bt_controller_disable();
}

void setup()
{
  Serial.begin(9600);
  Start_Time = millis();

  pwr_optim();
  warmup_wifi();

  Serial.println("Setup fulling done");
}

void loop()
{
  measureWind();
  intervalSendingData();
}