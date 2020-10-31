#include <WiFi.h>
#include <WebServer.h>
#include "DHT.h"

#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321

const char* ssid = "brisa-998109";
const char* senha = "hfnbn2is";

WebServer server(8888);

// DHT Sensor
int DHTPin = 14; 
               
// Initialize DHT sensor.
DHT dht(DHTPin, DHTTYPE);           

float temperatura;
float humidade;
 
void setup() {
  Serial.begin(115200);
  delay(100);
  
  pinMode(DHTPin, INPUT);

  dht.begin();

  Serial.print("Connecting to ");
  Serial.print(ssid);

  // Connect to your local wi-fi network
  WiFi.begin(ssid, senha);

  // Check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println("");
  Serial.println("WiFi conectada!");
  Serial.print("Seu IP: ");  Serial.println(WiFi.localIP());

  server.on("/", home_);
  server.onNotFound(notFound);

  server.begin();
  Serial.println("HTTP server no ar!");

}
void loop() {
  server.handleClient();
}

void home_() {
  temperatura = dht.readTemperature(); // Gets the values of the temperature
  humidade = dht.readHumidity(); // Gets the values of the humidity 
  server.send(200, "text/html", enviarHTML(temperatura,humidade)); 
}

void notFound(){
  server.send(404, "text/plain", "NOT FOUND");
}

String enviarHTML(float temperatura, float humidade){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>ESP32 Previsao do Tempo</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr +="p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1>ESP32 Previsao do Tempo</h1>\n";
  
  ptr +="<p>Temperatura: ";
  ptr +=(int)temperatura;
  ptr +="C</p>";
  ptr +="<p>Humidade: ";
  ptr +=(int)humidade;
  ptr +="%</p>";
  
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
