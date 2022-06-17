
#include <IRremote.h>

IRsend irsend;
void setup() {
  // put your setup code here, to run once:

pinMode(LED_BUILTIN, OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
delay(1000);
irsend.sendNEC(0xB24DBF40, 32);
}
