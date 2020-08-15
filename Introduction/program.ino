void setup(){
  pinMode(13, OUTPUT);
}

void loop(){
  digitalWrite(13, HIGH); // HIGH(5V) = ON LOW = OFF(~0V)
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}