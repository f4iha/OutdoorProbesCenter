#ifndef CONFIG_H_
#define CONFIG_H_


const int RecordTime = 3;      //Define Measuring Time (Seconds)
const int SensorPin = 23;      //Define Pin for Wind measurement
const int SensorPhotoPin = 33; //Define Pin for Photoresistor

const char *ssid = "";                  // Enter your WiFi name
const char *password = ""; // Enter WiFi password

// Add your MQTT Broker IP address, example:
const char *mqttServer = "";
const char *mqttTopic = "";

#endif