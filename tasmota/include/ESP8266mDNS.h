#pragma once
#if defined(ARDUINO_ARCH_ESP32)
  #include <ESPmDNS.h>
#else
  #include <ESP8266mDNS.h>
#endif
