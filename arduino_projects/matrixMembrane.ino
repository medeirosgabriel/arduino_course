#include <Keypad.h>

byte rows[] = {2,4,16,17};
byte columns[] = {5,18,19};

const byte n_rows = 4;
const byte n_cols = 3;

char keys[n_rows][n_cols] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*', '0','#'}
};

Keypad myKeypad = Keypad(makeKeymap(keys), rows, columns, n_rows, n_cols);

void setup() {
  Serial.begin(115200);
}

void loop() {
  char myKey = myKeypad.getKey();
  if (myKey != NULL){
    Serial.print("Key pressed: ");
    Serial.println(myKey);
  }
}
