#include<IRremote.h>
#define potPin 0
#define ledPin 9
const int RECV_PIN = 7;
IRrecv irrecv(RECV_PIN);
decode_results results;
int valPot = 0;
int valPot_1=0;

void setup() {

irrecv.enableIRIn();
  irrecv.blink13(true);
pinMode(ledPin,OUTPUT);

Serial.begin(9600);
}

void loop() {

valPot = analogRead(potPin);

if (valPot<135){
  valPot_1 =0;
}
 else{
      
  valPot_1 = map(valPot,0,1023,0,255);    
   
  if (valPot>900){
    valPot_1=255;
  }
  else{
      
  valPot_1 = map(valPot,0,1023,0,255);    
  }
 }


}
