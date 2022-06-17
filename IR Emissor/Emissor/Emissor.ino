#include <Pushbutton.h>

#include <IRremote.h> // Biblioteca para controlar o led infravermelho   
#include <Pushbutton.h>
#define LED_PIN 2
#define BUTTON_PIN 9

 IRsend irsend; //variável para poder enviar o código a TV   
  //variáveis constantes para o controle remoto   
  const int maisvolume = 7;     
  const int menosvolume = 8;   
  const int maiscanal = 9;   
  const int menoscanal = 10;
  const int power = 11; 
  const int menu = 12;  
  const int sair = 13;  
  const int led = 2;    
  const int ledIR = 3;   
 

Pushbutton button1(maisvolume);
Pushbutton button2(menosvolume);
Pushbutton button3(maiscanal);
Pushbutton button4(menoscanal);
Pushbutton button5(power);
Pushbutton button6(menu);
Pushbutton button7(sair);
       
  void setup() {   
  pinMode(led, OUTPUT); // saida led     
  pinMode(ledIR ,OUTPUT); // saída do infravermelho   
  Serial.begin(9600);   
  //configurando a entrada dos botoes   
  pinMode(maisvolume, INPUT_PULLUP);    
  pinMode(menosvolume, INPUT_PULLUP);    
  pinMode(maiscanal, INPUT_PULLUP);    
  pinMode(menoscanal, INPUT_PULLUP); 
  pinMode(power, INPUT_PULLUP);
  pinMode(menu, INPUT_PULLUP);
  pinMode(sair, INPUT_PULLUP);
    pinMode(LED_PIN, OUTPUT);   
  } 





void loop()
{

  while (1)
  {
    if (button1.getSingleDebouncedRelease())
    {
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
  irsend.sendNEC(0xBD30CF, 32);// código que sera enviado a tv para aumentar o volume
      break;
    }

    if (button2.getSingleDebouncedRelease())
    {
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
 irsend.sendNEC(0xBD08F7, 32);// código que sera enviado a tv para diminuir o volume  
      break;
    }

     if (button3.getSingleDebouncedRelease())
    {
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
 irsend.sendNEC(0xBD18E7, 32);// código que sera enviado a tv para diminuir o volume  
      break;
    }
    
     if (button4.getSingleDebouncedRelease())
    {
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
 irsend.sendNEC(0xBD38C7, 32);// código que sera enviado a tv para diminuir o volume  
      break;
    }

    if (button5.getSingleDebouncedRelease())
    {
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
 irsend.sendNEC(0xBD50AF, 32);// código que sera enviado a tv para diminuir o volume  
      break;
    }

    if (button6.getSingleDebouncedRelease())
    {
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
 irsend.sendNEC(0xBDE01F, 32);// código que sera enviado a tv para diminuir o volume  
      break;
    }

         if (button7.getSingleDebouncedRelease())
    {
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
 irsend.sendNEC(0xBD807F, 32);// código que sera enviado a tv para diminuir o volume  
      break;
    }
    
  }
}
