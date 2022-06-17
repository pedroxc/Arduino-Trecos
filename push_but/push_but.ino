#include <IRremote.hpp>

const int ir_rec = 7;
IRrecv irrecv(ir_rec);
decode_results results;

int led = 3;
int but = 4;
int pressed = 0;
int led_state =0;

void setup() {

  irrecv.enableIRIn();
pinMode(led,OUTPUT);
pinMode(but,INPUT);
Serial.begin(9600);



}

void loop() {

  pressed =digitalRead(but);
  if(pressed==HIGH){
    Serial.print("press");
    delay(500);
    switch(led_state){
      case 0:
      digitalWrite(led,HIGH);
      led_state = 1;
      break;
       case 1:
      digitalWrite(led,LOW);
      led_state = 0;
      break;
       
    }

}
if (irrecv.decode(&results)) {

 switch (results.value) {
  case 0xE0E028D7:

  Serial.print("ir");
      
    delay(500);
    switch(led_state){
      case 0:
      digitalWrite(led,HIGH);
      led_state = 1;
      break;
       case 1:
      digitalWrite(led,LOW);
      led_state = 0;
      break;
       
    }
  
  break;

 }
 irrecv.resume();
 }}
