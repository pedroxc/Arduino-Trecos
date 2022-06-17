/*
 * Simple example for how to use multiple SinricPro Switch device:
 * - setup 4 switch devices
 * - handle request using multiple callbacks
 * 
 * If you encounter any issues:
 * - check the readme.md at https://github.com/sinricpro/esp8266-esp32-sdk/blob/master/README.md
 * - ensure all dependent libraries are installed
 *   - see https://github.com/sinricpro/esp8266-esp32-sdk/blob/master/README.md#arduinoide
 *   - see https://github.com/sinricpro/esp8266-esp32-sdk/blob/master/README.md#dependencies
 * - open serial monitor and check whats happening
 * - check full user documentation at https://sinricpro.github.io/esp8266-esp32-sdk
 * - visit https://github.com/sinricpro/esp8266-esp32-sdk/issues and check for existing issues or open a new one
 */

// Uncomment the following line to enable serial debug output
//#define ENABLE_DEBUG

#ifdef ENABLE_DEBUG
       #define DEBUG_ESP_PORT Serial
       #define NODEBUG_WEBSOCKETS
       #define NDEBUG
#endif 

#include <Arduino.h>
#include <IRremote.h>
#ifdef ESP8266 
       #include <ESP8266WiFi.h>
#endif 
#ifdef ESP32   
       #include <WiFi.h>
#endif

#include "SinricPro.h"
#include "SinricProSwitch.h"

#define WIFI_SSID         "Pedro_gato"    
#define WIFI_PASS         "07091822"
#define APP_KEY           "5707b2a0-847c-4296-9525-77ee85ca7bd5"      // Should look like "de0bxxxx-1x3x-4x3x-ax2x-5dabxxxxxxxx"
#define APP_SECRET        "da2e7b8d-08a0-40cf-9595-5f7e7389134f-3912567a-fef9-490a-b78e-2ff854f1bf70"   // Should look like "5f36xxxx-x3x7-4x3x-xexe-e86724a9xxxx-4c4axxxx-3x3x-x5xe-x9x3-333d65xxxxxx"

#define SWITCH_ID_1       "62a8ab9efce0b9e02e6f7a28"    // Should look like "5dc1564130xxxxxxxxxxxxxx"
#define SWITCH_ID_2       "62a8c0a4fb740f77fc0eab8f"    // Should look like "5dc1564130xxxxxxxxxxxxxx"
#define SWITCH_ID_3       "YOUR-DEVICE-ID"    // Should look like "5dc1564130xxxxxxxxxxxxxx"
#define SWITCH_ID_4       "YOUR-DEVICE-ID"    // Should look like "5dc1564130xxxxxxxxxxxxxx"

#define BAUD_RATE         9600                // Change baudrate to your need

const int RECV_PIN = 12;

#define lightPin 2
#define fanPin 14
#define fanSwtich 0

unsigned long lastBtnPress = 0;

bool lightState = false;
bool fanState = false;

IRrecv irrecv(RECV_PIN);
decode_results results;

bool onPowerState1(const String &deviceId, bool &state) {
  Serial.printf("Device 1 turned %s\r\n", state?"on":"off");
  lightState=state;
  digitalWrite(lightPin,lightState?HIGH:LOW);
  return true; // request handled properly
}

bool onPowerState2(const String &deviceId, bool &state) {
  Serial.printf("Device 2 turned %s\r\n", state?"on":"off");
  fanState=state;
  digitalWrite(fanPin,fanState?HIGH:LOW);
  return true; // request handled properly
}

bool onPowerState3(const String &deviceId, bool &state) {
  Serial.printf("Device 3 turned %s\r\n", state?"on":"off");
  return true; // request handled properly
}

bool onPowerState4(const String &deviceId, bool &state) {
  Serial.printf("Device 4 turned %s\r\n", state?"on":"off");
  return true; // request handled properly
}


// setup function for WiFi connection
void setupWiFi() {
  Serial.printf("\r\n[Wifi]: Connecting");
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.printf(".");
    delay(250);
  }

  Serial.printf("connected!\r\n[WiFi]: IP-Address is %s\r\n", WiFi.localIP().toString().c_str());
}

void handleButtonPress() {
  unsigned long actualMillis = millis(); // get actual millis() and keep it in variable actualMillis
  if (digitalRead(fanSwtich) == LOW && actualMillis - lastBtnPress > 1000)  { // is button pressed (inverted logic! button pressed = LOW) and debounced?
    if (fanState) {     // flip fanState: if it was true, set it to false, vice versa
      fanState = false;
    } else {
      fanState = true;
    }
    digitalWrite(fanPin, fanState?LOW:HIGH); // if fanState indicates device turned on: turn on led (builtin led uses inverted logic: LOW = LED ON / HIGH = LED OFF)

    // get Switch device back
    SinricProSwitch& mySwitch = SinricPro[SWITCH_ID_1];
    // send powerstate event
    mySwitch.sendPowerStateEvent(fanState); // send the new powerState to SinricPro server
    Serial.printf("Device %s turned %s (manually via flashbutton)\r\n", mySwitch.getDeviceId().c_str(), fanState?"on":"off");

    lastBtnPress = actualMillis;  // update last button press variable
  } 
}

// setup function for SinricPro
void setupSinricPro() {
  // add devices and callbacks to SinricPro
  SinricProSwitch& mySwitch1 = SinricPro[SWITCH_ID_1];
  mySwitch1.onPowerState(onPowerState1);

  SinricProSwitch& mySwitch2 = SinricPro[SWITCH_ID_2];
  mySwitch2.onPowerState(onPowerState2);

  SinricProSwitch& mySwitch3 = SinricPro[SWITCH_ID_3];
  mySwitch3.onPowerState(onPowerState3);

  SinricProSwitch& mySwitch4 = SinricPro[SWITCH_ID_4];
  mySwitch4.onPowerState(onPowerState4);

  // setup SinricPro
  SinricPro.onConnected([](){ Serial.printf("Connected to SinricPro\r\n"); }); 
  SinricPro.onDisconnected([](){ Serial.printf("Disconnected from SinricPro\r\n"); });
  SinricPro.begin(APP_KEY, APP_SECRET);
}

// main setup function
void setup() {
  pinMode(fanSwtich,INPUT_PULLUP);
    irrecv.enableIRIn();
  pinMode(lightPin,OUTPUT);
  pinMode(fanPin,OUTPUT);
  Serial.begin(BAUD_RATE); Serial.printf("\r\n\r\n");
  setupWiFi();
  setupSinricPro();
}

void loop() {
  
  if (irrecv.decode(&results)) {
    switch (results.value) {
      case 0xE0E0A857:
      delay(200);
          if (fanState == 0) {
          digitalWrite(fanPin, LOW);
          SinricProSwitch& mySwitch1 = SinricPro[SWITCH_ID_1];
          mySwitch1.sendPowerStateEvent(fanState);
          
          fanState = 1;       
                       }
        else {
          digitalWrite(fanPin, HIGH);
          SinricProSwitch& mySwitch1 = SinricPro[SWITCH_ID_1];
          mySwitch1.sendPowerStateEvent(fanState);
          fanState = 0;
          }
        break;
        
      case 0xE0E06897:
      delay(400);
        if (lightState == 0) {
          digitalWrite(lightPin, LOW);
          SinricProSwitch& mySwitch2 = SinricPro[SWITCH_ID_2];
          mySwitch2.sendPowerStateEvent(lightState);
          lightState = 1;
             }
        else {
          digitalWrite(lightPin, HIGH);
          SinricProSwitch& mySwitch2 = SinricPro[SWITCH_ID_2];
          mySwitch2.sendPowerStateEvent(lightState);
          lightState = 0;
        }
        break;            }
    }
    irrecv.resume();
    handleButtonPress();
  SinricPro.handle();
}
