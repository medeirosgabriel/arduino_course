#include <IRremote.h>

#define CONTROL 11
#define MOT1A 9
#define MOT1B 8
#define SPEED 10

void stop(int portA, int portB);
void front(int portA, int portB);
void back(int portA, int portB);

IRrecv recIR(CONTROL);
decode_results result;

void setup(){
  pinMode(SPEED, OUTPUT);
  pinMode(MOT1A, OUTPUT);
  pinMode(MOT1B, OUTPUT);
  recIR.enableIRIn();
  Serial.begin(9600);
}

void loop(){
  if (recIR.decode(&result)) {
    Serial.println(result.value, HEX);
    switch(result.value) {
      case 0xFD807F:
      	front(MOT1A, MOT1B);
      	break;
      case 0xFD906F:
      	back(MOT1A, MOT1B);
     	break;
      case 0xFDA05F:
      	stop(MOT1A, MOT1B);
      	break;
    }
    recIR.resume();
  }
}

void stop(int portA, int portB) {
  digitalWrite(portA, 0);
  digitalWrite(portB, 0);
  analogWrite(SPEED, 0);
}

void front(int portA, int portB) {
  digitalWrite(portA, 1);
  digitalWrite(portB, 0);
  analogWrite(SPEED, 255);
}

void back(int portA, int portB) {
  digitalWrite(portA, 0);
  digitalWrite(portB, 1);
  analogWrite(SPEED, 255);
}
