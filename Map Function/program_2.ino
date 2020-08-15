#define AN5 A5

int leds[] = {2,3,4,5,6,7};
int size = sizeof(leds)/sizeof(int);

void setup(){
  for (int i = 0; i < size; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(AN5, INPUT);
}

void turnOn(int x) {
  for (int i = 0; i < x; i++) {
	digitalWrite(leds[i], HIGH);
  }
  for (int i = x; i < size; i++) {
	digitalWrite(leds[i], LOW);
  }
}

void loop(){
  // ANALOG -> 0 - 1023
  int value = map(analogRead(AN5), 0, 1023, 0, 6);
  turnOn(value);
}