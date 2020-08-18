#define AN5 A5
#define TR 3

void setup(){
  pinMode(TR, OUTPUT);
  pinMode(AN5, INPUT);
}

void loop(){
  int i = analogRead(AN5);
  int o = map(i, 0, 1023, 0, 255);
  analogWrite(TR, o);
}