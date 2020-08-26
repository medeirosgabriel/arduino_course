#define SOUND 5

void setup(){
  pinMode(SOUND, OUTPUT);
}

void loop(){
  // Frequency -> 31 - 4978
  // tone(port, frequency)
  // tone(port, frequency, time)
  // noTone(port)
  tone(SOUND, 200, 500);
  delay(550);
  tone(SOUND, 300, 500);
  delay(550);
  tone(SOUND, 400, 500);
  delay(550);
  tone(SOUND, 500, 500);
  delay(3000);
}