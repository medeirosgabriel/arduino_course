#define LED 3
#define MAX 255
#define MIN 0
#define TMP 10

// Analogic Signal - 8 bits (0 - 255)

void setup(){
  pinMode(LED, OUTPUT);
}

void loop(){
  
  for (int i = MIN; i < MAX; i++) {
    analogWrite(LED, i);
    delay(TMP);
  }
  
  for (int i = MAX; i > MIN; i--) {
    analogWrite(LED, i);
    delay(TMP);
  }
  
}