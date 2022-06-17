#define led 2
#include <MideaIR.h>
#define IR_EMITER       3

#include <IRremote.h>
IRsend irsend;
MideaIR remote_control(&irsend);

void setup() {
  
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(IR_EMITER, OUTPUT);
pinMode(led,OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0){

  char c=Serial.read();
  if (c == 'A') {
   remote_control.turnON();
   remote_control.turnON();
   remote_control.turnON();
   digitalWrite(led,HIGH);
      
    }
  if (c== 'a'){
    remote_control.turnOFF();
    remote_control.turnOFF();
    remote_control.turnOFF();
    digitalWrite(led,LOW);
    }
  }
}
