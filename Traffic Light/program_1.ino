#define RED 13 // Doesn't storage the variable, just replaces the text. It's the best choice.
int YELLOW = 12;
int GREEN = 11;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(YELLOW, OUTPUT);
}

void loop()
{
  digitalWrite(RED, HIGH);
  delay(7000);
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  delay(9000);
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  delay(3000);
  digitalWrite(YELLOW, LOW);
}