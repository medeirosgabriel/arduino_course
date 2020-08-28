#define BTN_PIN 0
// INT 0 = PIN 2
// INT 1 = PIN 3

void setup(){
  pinMode(BTN_PIN, INPUT);
  Serial.begin(9600);
}

void interruption() {
    Serial.println(1);
}

void loop(){
  attachInterrupt(BTN_PIN, interruption, RISING);
  // LOW - WHILE IT IS LOW
  // CHANGE - CHANGES ONLY ONCE EVEN KEEPING PRESSED
  // RISING - LOW -> HIGH
  // FALLING - HIGH -> LOW
  while (true) {
	Serial.println(2);
    delay(500);
  }
}