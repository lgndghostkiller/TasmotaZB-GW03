#pragma once
#if defined(ARDUINO_ARCH_ESP32)
  #include <WiFiMulti.h>
  using ESP8266WiFiMulti = WiFiMulti;
#else
  #include <ESP8266WiFiMulti.h>
#endif
