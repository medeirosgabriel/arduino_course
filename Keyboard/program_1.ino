char mapKeyBoard[4][4] = {{'1', '2', '3', 'A'},
              			  {'4', '5', '6', 'B'},
                          {'7', '8', '9', 'C'},
                          {'*', '0', '#', 'D'}};

void setup(){
  // Lines 9,8,7,6
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  
  // Columns 5,4,3,2
  pinMode(5,INPUT_PULLUP);
  pinMode(4,INPUT_PULLUP);
  pinMode(3,INPUT_PULLUP);
  pinMode(2,INPUT_PULLUP);
  
  Serial.begin(9600);
}

void printInfo(int x, int y) {
	Serial.println(mapKeyBoard[x][y]);
}

void loop(){
  for (int p = 6; p < 10; p++) {
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(p, LOW);
    
    int x = abs(p-9);2
    
    if (!digitalRead(5)) {
		printInfo(x, 0);
      	while (!digitalRead(5)){}
    } else if (!digitalRead(4)) {
      	printInfo(x, 1);
      	while (!digitalRead(4)){}
    } else if (!digitalRead(3)) {
		printInfo(x, 2);
      	while (!digitalRead(3)){}
    } else if (!digitalRead(2)) {
		printInfo(x, 3);
      	while (!digitalRead(2)){}
    }
  }
}