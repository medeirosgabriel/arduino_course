#include <IRremote.h>
#define RECEIVER 11

IRrecv recIR(RECEIVER);
decode_results result;


void setup(){
	Serial.begin(9600);
  	recIR.enableIRIn(); // Starts the receiver
}

void loop(){
  if (recIR.decode(&result)) {
    Serial.print("Value: ");
    Serial.println(result.value, HEX); // In Hexadecimal
    recIR.resume(); // Prepares to read a new command
  }
}