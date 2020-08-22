#include <Servo.h>

#define POT1 A5
#define POT2 A4
#define POT3 A3
#define POT4 A2

#define S1 2
#define S2 3
#define S3 4
#define S4 5

Servo s1, s2, s3, s4;
int angS1 = 0, angS2 = 0, angS3 = 0, angS4 = 0;

void setup(){
  pinMode(POT1, INPUT);
  pinMode(POT2, INPUT);
  pinMode(POT3, INPUT);
  pinMode(POT4, INPUT);
  s1.attach(S1);
  s2.attach(S2);
  s3.attach(S3);
  s4.attach(S4);
}

void loop(){
  angS1 = map(analogRead(POT1), 0, 1023, 0,  180);
  angS2 = map(analogRead(POT2), 0, 1023, 0,  180);
  angS3 = map(analogRead(POT3), 0, 1023, 0,  180);
  angS4 = map(analogRead(POT4), 0, 1023, 0,  180);
  s1.write(angS1);
  s2.write(angS2);
  s3.write(angS3);
  s4.write(angS4);
  delay(100);
}