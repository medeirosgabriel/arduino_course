#define M1A 4
#define M1B 5
#define M2A 6
#define M2B 7
#define SPEED 3

void setup(){
  
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  pinMode(SPEED, OUTPUT);
  
  analogWrite(SPEED, 255);
  
  digitalWrite(M1A, LOW);
  digitalWrite(M1B, LOW);
  digitalWrite(M2A, LOW);
  digitalWrite(M2B, LOW);
  
}

void loop(){
  
  digitalWrite(M1A, 1);
  digitalWrite(M1B, 0);
  digitalWrite(M2A, 0);
  digitalWrite(M2B, 1);
  
  delay(3000);
  
  digitalWrite(M1A, 0);
  digitalWrite(M1B, 1);
  digitalWrite(M2A, 1);
  digitalWrite(M2B, 0);
  
  delay(3000);
  
}