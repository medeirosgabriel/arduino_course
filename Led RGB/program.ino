#define RED 13
#define BLUE 12
#define GREEN 11
#define BTN 7

int btnDown = 0;
int btnUp = 0;
int color = 0;

void setup(){
  pinMode(BTN, INPUT);
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
}

void changeColor() {
  if (color % 3 == 0) {
    digitalWrite(RED, LOW);
  } else if (color % 3 == 1) {
	digitalWrite(GREEN, LOW);
  } else {
	digitalWrite(BLUE, LOW);
  }
  digitalWrite(11 + color % 3, HIGH);
  color ++;
}


void turnOnLight() {
  if (btnDown == 1 && btnUp == 1) {
    btnDown = 0;
    btnUp = 0;
    changeColor();
  }
}

void loop(){
  if (digitalRead(BTN) == HIGH) {
    btnDown = 1;
    btnUp = 0;
  } else {
	btnUp = 1;
  }
  turnOnLight();
}