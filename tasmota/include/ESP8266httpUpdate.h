#pragma once
#if defined(ARDUINO_ARCH_ESP32)
  #include <Arduino.h>
  #include <WiFi.h>
  #include <WiFiClient.h>
  #include <HTTPClient.h>
  #include <Update.h>
  #include <HTTPUpdate.h>
  using ESP8266HTTPUpdate = HTTPUpdate;
  #define ESPhttpUpdate httpUpdate
#else
  #include <ESP8266httpUpdate.h>
#endif
