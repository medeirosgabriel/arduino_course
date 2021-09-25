#include <WiFi.h>
 
const char* ssid = "*******";
const char* password = "*******";

#define LED 17

WiFiServer server(80);
 
void setup() {
  
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("Connected WiFi.");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
 
  server.begin();
}
 
void loop() {
  WiFiClient client = server.available();
  if (client) {
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) { // Checks if there is a client with data to be transmitted 
        char c = client.read(); // Read Client Next Byte - Data Stream - URL 
        if (c == '\n') { // Check if the line ended 
          if (currentLine.length() == 0) { // Check if the message ended 
            client.print("<a href=\"/H\">LIGAR LED.</a><br>");
            client.print("<a href=\"/L\">DESLIGAR LED.</a><br>");
            client.println();
            break;
          } else {
            currentLine = "";
          }
        } else if (c != '\r') {
          currentLine += c;
        }
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(LED, 1);
          Serial.println("LIGADA.");
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(LED, 0);
          Serial.println("DESLIGADA.");
        }
      }
    }
    client.stop();
  }
}
