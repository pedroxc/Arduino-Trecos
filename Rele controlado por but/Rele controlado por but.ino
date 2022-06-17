#define rele 7
#define but 9
int EstadoBut=0;


void executarAcao();

void setup() {
  // put your setup code here, to run once:
pinMode (rele,OUTPUT);
pinMode (but,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
EstadoBut= digitalRead ( but);
if (EstadoBut==HIGH)
{
  executarAcao();
}
}

void executarAcao()
{
 delay(500);
 digitalWrite(rele,!digitalRead(rele));

}
