#include <Arduino.h>

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  static bool bOn = true;
  digitalWrite(LED_BUILTIN, bOn);
  bOn = !bOn;
  delay(125);
}