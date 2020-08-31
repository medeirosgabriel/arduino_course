#include <Wire.h>

#define LED 13
#define myAddress 0x102

void setup(){
  Wire.begin(myAddress);
  Wire.onReceive(receiver);
  pinMode(LED, OUTPUT);
}

void loop(){
  
}

void receiver(int quant) {
  if (Wire.available()) {
	char data = Wire.read();
    digitalWrite(LED, data);
  }
}