#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"

#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321

const char* ssid = "******";
const char* password = "******";

WebServer server(8888);

// DHT Sensor
int DHTPin = 14; 
               
// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);           

float temperature;
float humidity;
 
void setup() {
  Serial.begin(115200);
  delay(100);
  
  pinMode(DHTPin, INPUT);

  dht.begin();

  Serial.print("Connecting to ");
  Serial.print(ssid);

  // Connect to your local wi-fi network
  WiFi.begin(ssid, password);

  // Check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println("");
  Serial.println("Connected!");
  Serial.print("IP Address: ");  Serial.println(WiFi.localIP());

  server.on("/", home_);
  server.onNotFound(notFound);

  server.begin();
  Serial.println("HTTP server running!");

}
void loop() {
  server.handleClient();
}

void home_() {
  temperature = dht.readTemperature(); // Gets the values of the temperature
  humidity = dht.readHumidity(); // Gets the values of the humidity 
  server.send(200, "text/html", sendHTML(temperature,humidity)); 
}

void notFound(){
  server.send(404, "text/plain", "NOT FOUND");
}

String sendHTML(float temperatura, float humidade){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>ESP32 Weather Forecast </title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr +="p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1>ESP32 Weather Forecast</h1>\n";
  
  ptr +="<p>Temperatura: ";
  ptr +=(int)temperature;
  ptr +="C</p>";
  ptr +="<p>Humidity: ";
  ptr +=(int)humidity;
  ptr +="%</p>";
  
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
