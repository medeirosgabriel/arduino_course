#define OPSENSOR 26

void setup() {
  pinMode(OPSENSOR, INPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.println(digitalRead(OPSENSOR));
  delay(250);
}
