#include <IRremote.h>
#include "LowPower.h"

IRsend irsend;

const int b1  = 8;  //on off
const int b2  = 5;  //Vol +
const int b3  = 6;  //vol -
const int b4  = 7;  //HDMI



int timer;
int modeCounter = 0;



void wakeUp() {
  timer = 0;
}

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  pinMode(b3, INPUT);
  pinMode(b4, INPUT);
}

void loop() {
  attachInterrupt(0, wakeUp, HIGH);
  while (timer < 10000) {
    
    if (digitalRead(b1) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(0xE0E036C9, 32);  //just remove my remote code and add your                                          //remote hex value
    }

    if (digitalRead(b2) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(16585453, 32);
    }

    if (digitalRead(b3) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(16618093, 32);
    }

    if (digitalRead(b4) == HIGH) {
      timer = 0;
      delay(50);
      irsend.sendNEC(16644103, 32);
    }

   
    delay(1);
    timer = timer + 1;

  }
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
}
