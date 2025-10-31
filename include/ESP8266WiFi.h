#pragma once
#if defined(ARDUINO_ARCH_ESP32)
  #include <WiFi.h>
  using ESP8266WiFiClass = WiFiClass;
  #define ESP8266WiFi WiFi
#else
  #include <ESP8266WiFi.h>
#endif
