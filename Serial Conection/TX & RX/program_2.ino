#define LED 2

void setup(){
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  if (Serial.available() > 0) {
	char c = Serial.read();
    if (c == '1') {
		digitalWrite(LED, HIGH);
    } else {
		digitalWrite(LED, LOW);
    }
  }
}