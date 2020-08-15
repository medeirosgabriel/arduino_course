#define MOTOR 12

void setup(){
  pinMode(MOTOR, OUTPUT);
}

void loop(){
  digitalWrite(MOTOR, HIGH);
}