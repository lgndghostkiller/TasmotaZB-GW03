#pragma once
#if defined(ARDUINO_ARCH_ESP32)
  #include <WebServer.h>
  using ESP8266WebServer = WebServer;
#else
  #include <ESP8266WebServer.h>
#endif
