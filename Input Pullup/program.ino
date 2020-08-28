#define LED 3
#define BTN 2

void setup(){  
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);
}

void loop(){
  digitalWrite(LED, digitalRead(BTN));
}