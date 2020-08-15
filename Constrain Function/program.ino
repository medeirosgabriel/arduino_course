#define POT A5

void setup(){
  pinMode(POT, INPUT);
  Serial.begin(9600);
}

void loop(){
  int v = constrain(analogRead(POT), 200, 500);
  Serial.println(v);
}