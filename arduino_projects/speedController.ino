#include <Thread.h>
#include <ThreadController.h>

#define LED 26
#define POT 34
#define OUTPULSE 12
#define INPULSE 14
#define MAXSPEED 200

Thread frequency; // Thread used to generate the electrical pulses

unsigned long time1; // Time of the first pulse
unsigned long time2; // Time of the second pulse

void ledInterrupt() {
  time2 = millis(); // Get the time
  unsigned long diff = time2 - time1; // Time difference between the pulses
  int cond = map(diff,0,2000,MAXSPEED, 0); // Mapping the difference
  Serial.println(cond);
  if (cond >= 20) {
    digitalWrite(LED, 1);
  } else {
    digitalWrite(LED, 0);
  }
  time1 = time2;
}

void setup() {
  time1 = 0;
  time2 = 0;
  frequency.setInterval(10000); // Time interval between thread executions 
  frequency.onRun(pulse); // Definition of thread function
  // MicroController Configuration
  pinMode(LED, OUTPUT);
  pinMode(OUTPULSE, OUTPUT);
  pinMode(INPULSE, INPUT);
  pinMode(POT, INPUT);
  Serial.begin(115200);
  // When the port changes from 0 to 1 the execution is paused to execute the ledInterrupt function;
  attachInterrupt(digitalPinToInterrupt(INPULSE), ledInterrupt, RISING); 
}

int time_ = 0; // Represents the new Thread interval.

void pulse() {
  digitalWrite(OUTPULSE, 1);
  digitalWrite(OUTPULSE, 0);
}

void loop() {
  time_ = map(analogRead(POT),0,4095,2000,0); // Calculates the new Thread interval.
  frequency.setInterval(time_); // Change thread execution interval
  if (frequency.shouldRun()) { // Checks if the thread should be executed
    frequency.run(); // Execute the thread
  }
}
