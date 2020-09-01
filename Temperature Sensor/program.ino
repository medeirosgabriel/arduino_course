#define TEMP A0

int values[10];
int cTemp = 0, lTemp = 0;

void setup(){
  Serial.begin(9600);
  pinMode(TEMP, INPUT);
}

void loop(){
  cTemp = map(analogRead(TEMP), 20, 358, -40, 125);
  if (cTemp != lTemp) {
    Serial.print("Temperature: ");
    Serial.print(cTemp);
    Serial.println("C");
    lTemp = cTemp;
  }
  delay(1000);
}