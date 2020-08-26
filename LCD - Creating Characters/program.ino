#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

// Special Caracters
byte heart[8]={B00000,
               B01010,
               B11111,
               B11111,
               B11111,
               B01110,
               B00100,
               B00000};

byte batteryL[8]={B01110,
                  B10001,
                  B10001,
                  B10001,
                  B10001,
                  B10001,
                  B10001,
                  B11111};

byte batteryM[8]={B01110,
                  B10001,
                  B10001,
                  B10001,
                  B11111,
                  B11111,
                  B11111,
                  B11111};

byte batteryF[8]={B01110,
                  B11111,
                  B11111,
                  B11111,
                  B11111,
                  B11111,
                  B11111,
                  B11111};

void setup(){
  lcd.begin(16,2);
  lcd.createChar(1,heart);
  lcd.createChar(2,batteryL);
  lcd.createChar(3,batteryM);
  lcd.createChar(4,batteryF);
}

void loop(){
  
  lcd.clear();
  
  lcd.setCursor(0,1);
  lcd.write(1);
  
  lcd.setCursor(0,0);
  lcd.write(2);
  delay(3000);
  
  lcd.setCursor(0,0);
  lcd.write(3);
  delay(3000);
  
  lcd.setCursor(0,0);
  lcd.write(4);
  delay(3000);
}















