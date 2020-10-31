#include <Keypad.h>
#include <WiFi.h>
#include <WebServer.h>

#define senhaCofre "124"

byte linhas[] = {2,4};
byte colunas[] = {5,18};

const byte nLinhas = 4;
const byte nColunas = 3;

char teclas[nLinhas][nColunas] = {
  {'1','2'},
  {'4','5'},
};

Keypad myKeypad = Keypad(makeKeymap(teclas), linhas, colunas, nLinhas , nColunas);

const char* ssid = "brisa-998109";
const char* senha = "hfnbn2is";

WebServer server(8888);

void setup() {
  Serial.begin(115200);
  Serial.print("Conectando à ");
  Serial.print(ssid);
  
  WiFi.begin(ssid, senha);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println("");
  Serial.println("WiFi conectada!");
  Serial.print("Seu IP: ");  
  Serial.println(WiFi.localIP());

  server.on("/", home_);
  server.onNotFound(notFound);

  server.begin();
  Serial.println("HTTP server no ar!");
}

String senhasDigitadas[100] = {};
int indice = 0;
String senhaDigitada = "";

void loop() {
  server.handleClient();
  char tecla = myKeypad.getKey();
  if (tecla != NULL){
    if (tecla == '5') {
      senhasDigitadas[indice%100] = senhaDigitada;
      Serial.println(senhaDigitada);
      if (senhaDigitada == senhaCofre) {
        Serial.println("OK");
      } else {
        Serial.println("Senha Incorreta");
      }
      indice ++;
      senhaDigitada = "";
    } else {
      Serial.println(tecla);
      senhaDigitada += tecla;
    }
  }
}

void home_() {
  server.send(200, "text/html", enviarHTML()); 
}

void notFound(){
  server.send(404, "text/plain", "NOT FOUND");
}

String enviarHTML(){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>ESP32 Seguranca de Cofre</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr +="p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1>ESP32 Seguranca de Cofre</h1>\n";
  for (int i = 0; i < sizeof(senhasDigitadas)/sizeof(String); i++) {
    ptr += "<p>";
    ptr += senhasDigitadas[i];
    ptr += "</p>";
  }
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
