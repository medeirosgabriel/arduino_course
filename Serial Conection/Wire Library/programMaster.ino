#include <Wire.h>

#define sl1Address 0x101 // 0 - 255
#define sl2Address 0x102 // 0 - 255

bool led1 = HIGH;
bool led2 = LOW;

void setup(){
  Wire.begin();
}

void loop(){
  Wire.beginTransmission(sl1Address);
  Wire.write(led1);
  Wire.endTransmission();
  led1 = !led1;
  Wire.beginTransmission(sl2Address);
  Wire.write(led2);
  Wire.endTransmission();
  led2 = !led2;
  delay(1000);
}