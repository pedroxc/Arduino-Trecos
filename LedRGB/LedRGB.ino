#define redpin 3
#define greenpin 5
#define bluepin 6
int r = 255;
int g = 0;
int b = 0;
void setup() {
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
}
