void setup() {
  // put your setup code here, to run once:
pinMode(12,INPUT);
pinMode(11,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

if (digitalRead(12)==HIGH){

  digitalWrite(11,LOW);
  
}if (digitalRead(12)==LOW){

  digitalWrite(11,HIGH);
}
}
