#define AN5 A5

void setup(){
  pinMode(AN5, INPUT);
  Serial.begin(9600); // Communication Speed to Serial Port
}

void loop(){
  Serial.println(analogRead(AN5));
  delay(500);
}