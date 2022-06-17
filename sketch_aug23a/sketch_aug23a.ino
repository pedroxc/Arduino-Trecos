
#include <IRremote.h>

IRsend irsend;

void setup() {
  Serial.begin(9600);
}

void loop() {
 
 
  //Volume Up//
  
    irsend.sendNEC(0xB24D9F60, 32); //Volume Up Code
    Serial.println("liga");
    delay(2000);
  
   //Volume Down//
  
    irsend.sendNEC(0xB24D7B84, 32); //Volume Down Code
    Serial.println("desliga ");
    delay(2000);
 
  
}
