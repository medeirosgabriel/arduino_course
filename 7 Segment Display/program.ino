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

int mapNumbers[8] = {8,9,3,4,5,7,6,2};

void setup(){
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
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