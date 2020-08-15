#define LDR A5
#define LED 2

void setup(){
  pinMode(LDR, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop(){
  int v = analogRead(A5);
  if (v > 800) {
	digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
  Serial.println(v);
  delay(100);
}