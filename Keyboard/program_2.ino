#include <Keypad.h>

#define ROWS 4
#define COLUMNS 4

char mapKeyBoard[4][4] = {{'1', '2', '3', 'A'},
              			  {'4', '5', '6', 'B'},
                          {'7', '8', '9', 'C'},
                          {'*', '0', '#', 'D'}};

byte portsRows[ROWS] = {9,8,7,6};
byte portsColumns[COLUMNS] = {5,4,3,2};

Keypad keyBoard = Keypad(makeKeymap(mapKeyBoard), portsRows, portsColumns, ROWS, COLUMNS);

void setup(){
  Serial.begin(9600);
}

void loop(){
  char key = keyBoard.getKey();
  if (key != NO_KEY) {
	Serial.println(key);
  }
}