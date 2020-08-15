#define LED 11
#define AN5 A5

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(AN5, INPUT);
}

void loop(){
  // ANALOG -> 0 - 1023
  // PWM -> 0 - 255
  // analogWrite(LED, analogRead(AN5)/4);
  analogWrite(LED, map(analogRead(AN5), 0, 1023, 0, 255));
}