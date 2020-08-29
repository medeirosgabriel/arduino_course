#include <LiquidCrystal.h>

#define BTN 0
// Interruption Button
// INT 0 = PIN 2
// INT 1 = PIN 3
#define POT A0
#define TEMP A1

LiquidCrystal lcd(8,7,6,5,4,3);

int choice = 1;

void setup(){
  pinMode(BTN, INPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  lcd.begin(16,2);
  Serial.begin(9600);
}

void changeInfo() {
  	lcd.clear();
	choice *= -1;
}

void loop(){
  attachInterrupt(BTN, changeInfo, RISING);
  int umidity = map(analogRead(A0), 0, 1023, 0, 100);
  int temp = map(analogRead(A1), 20, 358, -40, 125);
  if (choice == -1) {
    lcd.setCursor(0,0);
    lcd.print("Temperature:");
    lcd.setCursor(13,0);
    lcd.print(temp);
    lcd.print("C");
  } else if (choice == 1){
	lcd.setCursor(0,0);
    lcd.print("Umidity:");
    lcd.setCursor(9,0);
    lcd.print(temp);
    lcd.print("%");
  }
  delay(100);
}