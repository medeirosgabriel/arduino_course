#include <Servo.h>
#define POT A5

Servo s1;
Servo s2;

int angS1, angS2;

void setup(){
  angS1 = 0; angS2 = 180;
  s1.attach(2);
  s2.attach(3);
}

void setAngS1(int ang) {
  angS1 = (ang > 180) ? 0 : angS1;
  s1.write(angS1);
  angS1 += 90;
}

void setAngS2(int ang) {
  angS2 = (ang < 0) ? 180 : angS2;
  s2.write(angS2);
  angS2 -= 90;
}

void loop(){
  setAngS1(angS1);
  setAngS2(angS2);
  delay(2000);
}