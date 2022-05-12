#include <ACS712.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

#define SENSOROUT A0

float rawval;

const char* ssid = "hucth4g"; 
const char* password = "Kanishka1988";

char server[] = "192.168.43.17";


WiFiClient client;    


void setup()
{
 Serial.begin(115200);
  delay(10);
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
 
  // Start the server
  Serial.println("Server started");
  Serial.print(WiFi.localIP());
  delay(1000);
  Serial.println("connecting...");
 }
void loop()
{ 
  int sensorValue = analogRead(A0);
  dataTrasnmit(); 
  delay(5000);
}

 void dataTrasnmit()   //CONNECTING WITH MYSQL
 {
   if (client.connect(server, 80)) {
    Serial.println("connected");
    // Make a HTTP request:
    Serial.print("GET /acs712testcodes/Test 2/acs712rawdata.php?rawval=");
    client.print("GET /acs712testcodes/Test 2/acs712rawdata.php?rawval=");
    Serial.println(rawData);
    client.print(rawData);
    client.print(" ");      //SPACE BEFORE HTTP/1.1
    client.print("HTTP/1.1");
    client.println();
    client.println("Host: 192.168.43.17");
    client.println("Connection: close");
    client.println();
  } else {
    // if didn't get a connection to the server:
    Serial.println("connection failed");
  }
 }
