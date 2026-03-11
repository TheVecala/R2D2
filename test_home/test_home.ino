#include "arduino_secrets.h"

 /* Projekt: Google Home LED Control */

#include "thingProperties.h"

void setup() {
  Serial.begin(9600);
  delay(1500); 

  // Inicializace vlastnostÃ­ definovanÃ½ch v Cloudu
  initProperties();

  // PÅipojenÃ­ k Arduino IoT Cloudu
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  // NastavenÃ­ vestavÄnÃ© LED jako vÃ½stupu
  pinMode(LED_BUILTIN, OUTPUT);
  
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  // Tato funkce udrÅ¾uje spojenÃ­ s Cloudem a synchronizuje data
  ArduinoCloud.update();
}

// Tato funkce se automaticky spustÃ­, kdyÅ¾ zmÄnÃ­te stav v Google Home aplikaci
void onLightChange()  {
  if (light) {
    digitalWrite(LED_BUILTIN, HIGH);
    Serial.println("Google Home: LED ZAPNUTA");
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    Serial.println("Google Home: LED VYPNUTA");
  }
}