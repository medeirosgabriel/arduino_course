#include <Servo.h>
#define POT A5

Servo s1;
Servo s2;

int ang;

void setup(){
  ang = 0;
  s1.attach(2);
  s1.write(ang);
  s2.attach(3);
  s2.write(ang);
}

void loop(){
  ang = map(analogRead(POT), 0, 1024, 0, 180);
  s1.write(ang);
  s2.write(ang);
  delay(100);
}