#define TRIGGER 35
#define ECHO 32

int dist_cm, dist_m;

void setup(){
  pinMode(TRIGGER, OUTPUT);
  pinMode(ECHO, INPUT);
  Serial.begin(115200);
}

void loop(){
  digitalWrite(TRIGGER, 0);
  delayMicroseconds(2);
  digitalWrite(TRIGGER, 1);
  delayMicroseconds(5);
  digitalWrite(TRIGGER, 0);
  
  // Returns how long it has been on in microseconds
  float timeDist = pulseIn(ECHO, HIGH);
  
  // Sound Speed = 0.0343 m/ms
  float dist = (0.0343 * timeDist)/2;
  
  Serial.println(dist);
  delay(1000);
}
