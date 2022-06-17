
#include <IRremote.h>
IRsend irsend;

void setup() {
  Serial.begin(9600);
}

void loop() {
    irsend.sendNEC(0xE0E028D7, 16);
    delay(500); 
}
