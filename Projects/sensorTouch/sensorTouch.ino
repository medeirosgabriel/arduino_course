#define OTSENSOR 26

void setup() {
  pinMode(OTSENSOR, INPUT);
  Serial.begin(115200);
}

void loop() {
  Serial.println(digitalRead(OTSENSOR));
  delay(250);
}
