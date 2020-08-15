#define LED 13
#define BTN 12

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
}

void loop()
{
  if (digitalRead(BTN) == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
	digitalWrite(LED, LOW);
  }
}