#define M1A 4
#define M1B 5
#define SPEED 3

void setup(){
  
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(SPEED, OUTPUT);
  
  analogWrite(SPEED, 255);
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, HIGH);
  
}

void loop(){
  
  digitalWrite(M1A, 1);
  digitalWrite(M1B, 0);
  
  delay(3000);
  
  digitalWrite(M1A, 0);
  digitalWrite(M1B, 1);
  
  delay(3000);
  
}