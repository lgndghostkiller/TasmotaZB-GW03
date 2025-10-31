#pragma once

#if defined(ARDUINO_ARCH_ESP32)
  #include <Arduino.h>
  #include <WiFi.h>
  #include <WiFiClient.h>
  #include <HTTPClient.h>
  using ESP8266HTTPClient = HTTPClient;
#else
  #include <ESP8266HTTPClient.h>
#endif
