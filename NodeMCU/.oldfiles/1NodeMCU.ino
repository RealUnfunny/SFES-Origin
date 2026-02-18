#include ".src/libraries/ESP8266WiFi/src/ESP8266WiFi.h"
#include ".src/libraries/ESP8266WebServer/src/ESP8266WebServer.h"
#include "PubSub/src/PubSubClient.h"

const char* ssid = "***";
const char* password = "***";

ESP8266WebServer server(80);

bool LedStats = LOW;

void setup()
{
  Serial.begin(9600);
  delay(100);
  pinMode(D4, OUTPUT);

  Serial.println("Connecting to");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED)
  {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi Connected!");
  Serial.print("Got IP:");
  Serial.print(WiFi.localIP());

  server.on("/", OnConnect);
  server.on("/", OnYes);
  server.on("/", OnNo);
  server.onNotFound(HandleNotFound);
}

void loop()
{}

void OnConnect()
{}

void OnYes()
{}

void OnNo()
{}

void HandleNotFound()
{}
