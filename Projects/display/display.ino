// SEQUENCE: A,B,C,D,E,F,G,DP;

int numbers[10][8] = {{1,1,1,1,1,1,0,0}, // 0
                      {0,1,1,0,0,0,0,0}, // 1
                      {1,1,0,1,1,0,1,0}, // 2
                      {1,1,1,1,0,0,1,0}, // 3
                      {0,1,1,0,0,1,1,0}, // 4
                      {1,0,1,1,0,1,1,0}, // 5
                      {1,0,1,1,1,1,1,0}, // 6
                      {1,1,1,0,0,0,0,0}, // 7
                      {1,1,1,1,1,1,1,0}, // 8
                      {1,1,1,1,0,1,1,0}}; // 9

int mapNumbers[8] = {14,27,17,4,2,12,13,18};

void setup(){
  pinMode(14, OUTPUT);digitalWrite(14,0);
  pinMode(27, OUTPUT);digitalWrite(27,0);
  pinMode(17, OUTPUT);digitalWrite(17,0);
  pinMode(4, OUTPUT);digitalWrite(4,0);
  pinMode(2, OUTPUT);digitalWrite(2,0);
  pinMode(12, OUTPUT);digitalWrite(12,0);
  pinMode(13, OUTPUT);digitalWrite(13,0);
  pinMode(18, OUTPUT);digitalWrite(18,0);
}

int number = 0;

void loop(){
  for (int i = 0; i < 8; i++) {
    digitalWrite(mapNumbers[i], numbers[number][i]);
  }
  delay(1000);
  for (int i = 0; i < 8; i++) {
    digitalWrite(mapNumbers[i], 0);
  }
  number += 1;
  number = number % 10;
}
