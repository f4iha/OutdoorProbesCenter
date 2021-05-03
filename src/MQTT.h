#include <PubSubClient.h>

WiFiClient espClient;
PubSubClient client(espClient);

// connect to mqtt server
void connect_mqtt()
{
  client.setServer(mqttServer, 1883);
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

// pushing the data to the mqtt topic
bool pushData(const char* mqttTopic, char* value){
    return client.publish(mqttTopic, value);
}

// disconnect the mqtt client
void close_mqtt(){
    return client.disconnect();
}