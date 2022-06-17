
#include <IRremote.h>


IRsend irsend;

 const int ledIR = 3;   
void setup() {
 pinMode(ledIR ,OUTPUT);
}

void loop() {
     
      irsend.sendNEC(0xE0E0E01F, 32);
      delay(100);
    }

   
