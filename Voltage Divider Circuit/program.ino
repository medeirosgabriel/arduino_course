#define AN A5

void setup(){
  pinMode(AN, INPUT);
  Serial.begin(9600);
}

void loop(){
  Serial.println(analogRead(AN));
}