#define RED 13
#define BLUE 12
#define GREEN 11
#define BTN 7

class Button {
public:
  int down, up, port;
  
  Button(int p) {
    this -> port = p;
    down = 0; up = 0;
  }
  
  bool isPressed() {
    if (digitalRead(port) == HIGH) {
      down = 1;
      up = 0;
    } else {
      up = 1;
    }
    if (down && up) {
      down = 0;
      up = 0;
      return true;
    } else {
      return false;
    }
  }
};

class Color {
public:
  int pRed, pBlue, pGreen, lColor;
  
  Color(int pRed, int pGreen, int pBlue) {
    this -> pRed = pRed;
    this -> pGreen = pGreen;
    this -> pBlue = pBlue;
    this -> lColor = 0;
  }
  
  void changeColor() {
    if (lColor % 3 == 0) {
      color(1, 0, 0);
    } else if (lColor % 3 == 1) {
      color(0, 1, 0);
    } else {
      color(0, 0, 1);
    }
    this -> lColor++;
  }
  
private:
  void color(int r, int g, int b) {
    // 1 = HIGH, 0 = LOW
	digitalWrite(pRed, r);
    digitalWrite(pGreen, g);
    digitalWrite(pBlue, b);
  }
};

Button btn(BTN);
Color color_(RED, GREEN, BLUE);

void setup(){
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BTN, INPUT);
}

void loop(){
  if (btn.isPressed()){
	color_.changeColor();
  }
}