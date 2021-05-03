#ifndef CONFIG_H_
#define CONFIG_H_


const int RecordTime = 3;      //Define Measuring Time (Seconds)
const int SensorPin = 23;      //Define Pin for Wind measurement
const int SensorPhotoPin = 33; //Define Pin for Photoresistor

const char *ssid = "Arkannoide";                  // Enter your WiFi name
const char *password = "!olivier@alkannoide_69?"; // Enter WiFi password

// Add your MQTT Broker IP address, example:
const char *mqttServer = "192.168.1.10";
const char *mqttTopic = "outdoor_sensor";

#endif