#define redpin 3
#define greenpin 5
#define bluepin 6
int r = 255;
int g = 0;
int b = 0;
int len =0;

String  Rstring, Gstring, Bstring, Comando;
void setup() {
  Serial.begin(9600);
  pinMode(redpin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(bluepin, OUTPUT);

}

void rgb(int r, int g, int b) {
  analogWrite(redpin, r);
  analogWrite(greenpin, g);
  analogWrite(bluepin, b);
}


void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0)
  {
    char data = Serial.read(); // reading the data received from the bluetooth module
    Comando.concat(data);



    switch (data)
    {
      case 'a':
        Serial.print("RAINBOW ON");
        for (int i = 0; i < 255; i++) {
          rgb(r, g, b);
          g++;
          delay(2);
        }
        for (int i = 0; i < 255; i++) {
          rgb(r, g, b);
          r--;
          delay(2);
        }
        for (int i = 0; i < 255; i++) {
          rgb(r, g, b);
          b++;
          delay(2);
        }
        for (int i = 0; i < 255; i++) {
          rgb(r, g, b);
          g--;
          delay(2);
        }
        for (int i = 0; i < 255; i++) {
          rgb(r, g, b);
          r++;
          delay(2);
        }
        for (int i = 0; i < 255; i++) {
          rgb(r, g, b);
          b--;
          delay(2);
        }
        Comando = "";
        break;

      case 'd':
        rgb(0, 0, 0);
        Serial.print("OFF");
        Comando = "";
      
        break; // when d is pressed on the app on your smart phone


      case 'f' :
      char buf[12];   
      Comando.toCharArray(buf, 12);
      char* r_char = strtok(buf,"#");
      char* g_char = strtok(NULL,"$");
      char* b_char = strtok(NULL,"%");

      int r = atoi(r_char);
      int g = atoi(g_char);
      int b = atoi(b_char);
      Serial.print(r);
      Serial.print(g);
      Serial.print(b);
      rgb(r,g,b);
      Comando = "";
         break;
    }
  }
  delay(50);
}
