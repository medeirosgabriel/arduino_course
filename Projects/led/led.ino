#include <WiFi.h>
 
const char* ssid = "brisa-998109";
const char* password = "hfnbn2is";

#define LED 17

WiFiServer server(80);
 
void setup() {
  
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  
  Serial.print("Conectando-se a ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println("");
  Serial.println("WiFi conectada.");
  Serial.print("Endereço de IP: ");
  Serial.println(WiFi.localIP());
 
  server.begin();
}
 
void loop() {
  WiFiClient client = server.available();
  if (client) {
    String currentLine = "";
    while (client.connected()) {
      if (client.available()) { // Verifica se existe um cliente com dados a serem transmitidos
        char c = client.read(); // Ler o próximo byte do cliente - Stream de dados - URL
        if (c == '\n') { // Verifica se a linha terminou
          if (currentLine.length() == 0) { // Verifica se a mensagem terminou
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
