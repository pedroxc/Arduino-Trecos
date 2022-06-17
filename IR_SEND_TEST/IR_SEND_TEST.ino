#include <IRremote.h>

IRsend irsend;
const int buttonPin = 2; // the number of the pushbutton pin
//const int ledPin = 3;
int buttonState = 0; // variable for reading the pushbutton status
void setup()
{
// pinMode(ledPin, OUTPUT);
// initialize the pushbutton pin as an input:
pinMode(buttonPin, INPUT);
Serial.begin(9600);
}

void loop() {


irsend.sendNEC(0x40BDCA35, 32);
Serial.print("foi");
delay(500);


}
