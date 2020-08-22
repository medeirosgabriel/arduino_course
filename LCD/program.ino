#include <LiquidCrystal.h>

LiquidCrystal lcd(7,6,5,4,3,2);

void setup(){
  lcd.begin(16,2); // Rows and Columns - Dimensions
  lcd.clear(); // Clean the Screen
}

void loop(){
  lcd.setCursor(5,0); // Where the text begins
  lcd.print("Gabriel");
  lcd.setCursor(6,1);
  lcd.print("Paiva");
  delay(3000);
  
  for (int i = 0; i < 5; i++) {
    lcd.scrollDisplayLeft();
    delay(100);
  }
  
  for (int i = 0; i < 9; i++) {
    lcd.scrollDisplayRight();
    delay(100);
  }
  
  for (int i = 0; i < 4; i++) {
    lcd.scrollDisplayLeft();
    delay(100);
  }
  
  delay(1000);
  
  // Flash
  lcd.noDisplay();
  delay(200);
  lcd.display();
  delay(200);
  
  lcd.noDisplay();
  delay(200);
  lcd.display();
  delay(200);
  
  lcd.noDisplay();
  delay(200);
  lcd.display();
  delay(200);
  
  lcd.noDisplay();
  delay(200);
  lcd.display();
  delay(200);
}