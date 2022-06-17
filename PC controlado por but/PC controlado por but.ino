 int rele =9;
 int but =7;
 int EstadoBut = 0;

void setup() {
  // put your setup code here, to run once:
pinMode(rele,OUTPUT);
pinMode (but,INPUT);
}


void loop() {
  // put your main code here, to run repeatedly:
EstadoBut = digitalRead(but);

if (EstadoBut == HIGH){
delay(1000);
digitalWrite(rele,LOW);
delay(1000);
digitalWrite(rele,HIGH);

} 
else {
digitalWrite(rele,HIGH);
}
}
