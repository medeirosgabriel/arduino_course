void setup(){
  Serial.begin(9600);
}

void loop(){
  Serial.write('1');
  Serial.flush();
  delay(1000);
  Serial.write('2');
  Serial.flush(); delay(1000);
}