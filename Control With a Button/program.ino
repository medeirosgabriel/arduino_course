#define LED 13
#define BTN 12

int up = 0;
int down = 0;

void setup(){
  pinMode(LED, OUTPUT);
  pinMode(BTN, INPUT);
}

void changeStatus() {
  if (digitalRead(LED) == HIGH) {
    digitalWrite(LED, LOW);
  }else {
    digitalWrite(LED, HIGH);
  }
}

void turnOnOff() {
  if (up == 1 && down == 1) {
    up = 0;
    down = 0;
	changeStatus();
  }
}

void loop(){
  
  if (digitalRead(BTN) == HIGH) {
    up = 1;
  	down = 0;
  } else {
	down = 1;
  }
  
  turnOnOff();
}