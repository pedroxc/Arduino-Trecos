#include <IRremote.h>
int IRPIN = 2;
IRrecv irrecv(IRPIN);
decode_results result;
int button = 0;
void setup()
{
  Serial.begin(9600);
  Serial.println("Enabling IRin");
  irrecv.enableIRIn();
  Serial.println("Enabled IRin");
  Initialize_streamer();
}
void loop() 
{
  if (irrecv.decode(&result)) 
  {
    button = button+1;
    Serial.print("Value: ");
    Serial.println(result.value, HEX);
    Write_streamer();
    irrecv.resume(); 
  }
  delay(500);
}
void Initialize_streamer()
{
Serial.println("CLEARDATA"); //clears up any data left from previous projects
Serial.println("LABEL,Hex Code, Button"); //always write LABEL, to indicate it as first line
}
void Write_streamer()
  { 
    Serial.print("DATA"); //always write "DATA" to Indicate the following as Data
    Serial.print(","); //Move to next column using a ","
    Serial.print(result.value, HEX); //Store date on Excel
    Serial.print(","); //Move to next column using a ","
    Serial.print(button); //Store date on Excel
    Serial.print(","); //Move to next column using a ","
    Serial.println(); //End of Row move to next row
  }
