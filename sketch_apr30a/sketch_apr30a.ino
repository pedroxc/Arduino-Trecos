#include <IRremote.h>
#include <MideaIR.h>

#define IR_EMITER       3


// IRsend Object and Remote Control object
IRsend irsend;
MideaIR remote_control(&irsend);
void setup(){
    // Start communication in 9600
    Serial.begin(9600);

     int i;

   
}
    void loop(){
       // Define IR PIN as Output
    pinMode(IR_EMITER, OUTPUT);
    
   
    // Try to turn ON the Air Conditioner
    Serial.println(F("Trying to Turn ON the Air Conditioner..."));
    remote_control.turnON();
    delay(2500);
/*
    Serial.println(F("Testing Turbo mode..."));
    remote_control.seTurboMode();

    delay(60000);
*/
    // Try to turn OFF
    Serial.println(F("Trying to Turn OFF the Air Conditioner..."));
    remote_control.turnOFF();
    delay(2500);
  
  }
