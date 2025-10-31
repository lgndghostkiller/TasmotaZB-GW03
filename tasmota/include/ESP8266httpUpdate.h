#pragma once
#if defined(ARDUINO_ARCH_ESP32)
  #include <Arduino.h>
  #include <WiFi.h>
  #include <WiFiClient.h>
  #include <HTTPClient.h>
  #include <HTTPUpdate.h>
  // Auf ESP8266 heißt die Klasse/Instanz ESPhttpUpdate.
  // Auf ESP32 heißt sie HTTPUpdate/httpUpdate.
  using ESP8266HTTPUpdate = HTTPUpdate;
  #define ESPhttpUpdate httpUpdate
#else
  #include <ESP8266httpUpdate.h>
#endif
