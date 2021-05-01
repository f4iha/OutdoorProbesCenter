#include <Arduino.h>
#include <WiFi.h>
#include <Esp.h>
#include <PubSubClient.h>
#include "driver/adc.h"
#include <esp_wifi.h>
#include <esp_bt.h>

#include "settings.h"

int InterruptCounter = 0;
float WindSpeed;
float MaxWindSpeed = 0;
float SumWindSpeed = 0;
int WindMeasureCounter = 0;
int Light;


unsigned long Snooze_Time = 300000;

WiFiClient espClient;
PubSubClient client(espClient);

unsigned long Start_Time;
unsigned long Time_Elapsed;

void connect_wifi()
{
  delay(10);
  // We start by connecting to a WiFi network
  Serial.println();
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void close_wifi()
{
  Serial.println("Disconnecting from wifi");
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  esp_wifi_stop();
}

void connect_mqtt()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client"))
    {
      Serial.println("connected");
    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

bool pushData(const char* mqttTopic, char* value){
    return client.publish(mqttTopic, value);
}

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


void measureLight()
{
  Light = analogRead(SensorPhotoPin);
}

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