#include <Arduino.h>
#include <WiFi.h>
#include "settings.h"

// connecting to the wifi network
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

// closing to the wifi network and stop the wifi hardware
void close_wifi()
{
    Serial.println("Disconnecting from wifi");
    WiFi.disconnect(true);
    WiFi.mode(WIFI_OFF);
    esp_wifi_stop();
}

// warmup wifi during setup()
void warmup_wifi()
{
    connect_wifi();
    delay(3000);
    close_wifi();
}