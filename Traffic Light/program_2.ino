#define RED 13 // Doesn't storage the variable, just replaces the text. It's the best choice.
int YELLOW = 12;
int GREEN = 11;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
}


void turnOnLed(int led, int time) {
	digitalWrite(led, HIGH);
  	delay(time);
  	digitalWrite(led, LOW);
}

void loop()
{
  turnOnLed(RED, 7000);
  turnOnLed(GREEN, 9000);
  turnOnLed(YELLOW, 3000);
}