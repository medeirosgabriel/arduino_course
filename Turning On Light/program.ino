int LED = 10;

void setup(){
  pinMode(LED, OUTPUT);
}

void loop(){
  digitalWrite(LED, HIGH);
  delay(300); // Wait for 1000 millisecond(s)
  digitalWrite(LED, LOW);
  delay(300); // Wait for 1000 millisecond(s)
}