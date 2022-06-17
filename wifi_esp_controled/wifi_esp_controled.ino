
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "8fbcb32654514b19a73fe2dfe1f87d55";
char ssid[] = "office";
char pass[] = "07091822";

void setup()
{
  // Debug console
  Serial.begin(9600);
pinMode(4,OUTPUT);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  if (digitalRead(0)==HIGH)
  {
    digitalWrite(4,HIGH);
    delay(1000);
    digitalWrite(4,LOW);
    digitalWrite(0,LOW);
    
  }
  Blynk.run();
}
