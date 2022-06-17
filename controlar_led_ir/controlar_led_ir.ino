// Include IR Remote Library by Ken Shirriff
#include <IRremote.h>

// Define sensor pin
const int RECV_PIN = 7;

// Define LED pin
#define FAN    5
#define LIGHT 6


// Define integer to remember toggle state
int FANState = 0;
int LIGHTState = 0;

// Define IR Receiver and Results Objects
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  Serial.begin(9600);
  // Enable the IR Receiver
  irrecv.enableIRIn();
  // Set LED pins as Outputs
  pinMode(FAN, OUTPUT);
  pinMode(LIGHT, OUTPUT);

}


void loop() {


  if (irrecv.decode(&results)) {

    switch (results.value) {

      case 0xE0E036C9:
      delay(200);

          if (FANState == 0) {
          digitalWrite(FAN, HIGH);
          FANState = 1;
          
          
               
        }
        else {
          digitalWrite(FAN, LOW);
          FANState = 0;

        }

        break;

      case 0xE0E028D7:
      
      delay(400);

        if (LIGHTState == 0) {
          digitalWrite(LIGHT, HIGH);
          LIGHTState = 1;
             }
        else {
          digitalWrite(LIGHT, LOW);
          LIGHTState = 0;

        }
        break;

      

        }

    }
    irrecv.resume();
  }
