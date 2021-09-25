#include <Keypad.h>
#include <WiFi.h>
#include <WebServer.h>

#define passwordBox "124"

byte rows[] = {2,4};
byte cols[] = {5,18};

const byte n_rows = 4;
const byte n_cols = 3;

char keys[n_rows][n_cols] = {
  {'1','2'},
  {'4','5'},
};

Keypad myKeypad = Keypad(makeKeymap(keys), rows, cols, n_rows , n_cols);

const char* ssid = "*********";
const char* password = "*********";

WebServer server(8888);

void setup() {
  Serial.begin(115200);
  Serial.print("Connecting to ");
  Serial.print(ssid);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println("");
  Serial.println("Connected WiFi!");
  Serial.print("IP Address: ");  
  Serial.println(WiFi.localIP());

  server.on("/", home_);
  server.onNotFound(notFound);

  server.begin();
  Serial.println("HTTP server running!");
}

String typedPasswords[100] = {};
int index = 0;
String typedPassword = "";

void loop() {
  server.handleClient();
  char key = myKeypad.getKey();
  if (key != NULL){
    if (key == '5') {
      typedPasswords[index%100] = typedPassword;
      Serial.println(typedPassword);
      if (typedPassword == passwordBox) {
        Serial.println("OK");
      } else {
        Serial.println("Incorrect Password");
      }
      index ++;
      typedPassword = "";
    } else {
      Serial.println(key);
      typedPassword += key;
    }
  }
}

void home_() {
  server.send(200, "text/html", sendHTML()); 
}

void notFound(){
  server.send(404, "text/plain", "NOT FOUND");
}

String sendHTML(){
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr +="<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr +="<title>ESP32 Safe Box</title>\n";
  ptr +="<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr +="body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;}\n";
  ptr +="p {font-size: 24px;color: #444444;margin-bottom: 10px;}\n";
  ptr +="</style>\n";
  ptr +="</head>\n";
  ptr +="<body>\n";
  ptr +="<div id=\"webpage\">\n";
  ptr +="<h1>ESP32 Safe Box</h1>\n";
  for (int i = 0; i < sizeof(typedPasswords)/sizeof(String); i++) {
    ptr += "<p>";
    ptr += typedPasswords[i];
    ptr += "</p>";
  }
  ptr +="</div>\n";
  ptr +="</body>\n";
  ptr +="</html>\n";
  return ptr;
}
