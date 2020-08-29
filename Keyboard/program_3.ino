#include <Keypad.h>

#define ROWS 4
#define COLUMNS 4
#define RED 10
#define YELLOW 11
#define GREEN 12

char mapKeyBoard[4][4] = {{'1', '2', '3', 'A'},
              			  {'4', '5', '6', 'B'},
                          {'7', '8', '9', 'C'},
                          {'*', '0', '#', 'D'}};

byte portsRows[ROWS] = {9,8,7,6};
byte portsColumns[COLUMNS] = {5,4,3,2};

Keypad keyBoard = Keypad(makeKeymap(mapKeyBoard), portsRows, portsColumns, ROWS, COLUMNS);

int signal = -1;
String password = "123A";
String typedPassword = "";

bool checkPassword(String typedPassword, String realPassword);

void setup () {
  pinMode(RED,OUTPUT);
  pinMode(YELLOW,OUTPUT);
  pinMode(GREEN,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  char key = keyBoard.getKey();
  if (key != NO_KEY) {
    Serial.println(key);
    if (key == '#') {
      if (checkPassword(typedPassword, password)) {
		leds(0,0,1);
        delay(1000);
        leds(0,0,0);
      } else {
        leds(1,0,0);
        delay(1000);
        leds(0,0,0);
      }
      typedPassword = "";
    } else {
      typedPassword += key;
      leds(0,1,0);
    }
  }
}

bool checkPassword(String typedPassword, String realPassword) {
	return typedPassword.compareTo(realPassword) == 0;
}

void leds(int r, int y, int g) {
  digitalWrite(RED, r);
  digitalWrite(YELLOW, y);
  digitalWrite(GREEN, g);
}
