#pragma once
// HTTPUpdateLight-Wrapper für ESP32 (Arduino Core 2.x):
// stellt dieselbe API bereit, ruft aber die gültigen Overloads mit WiFiClient auf.

#if defined(ARDUINO_ARCH_ESP32)
  #include <Arduino.h>
  #include <WiFi.h>
  #include <WiFiClient.h>
  #include <HTTPClient.h>
  #include <Update.h>
  #include <HTTPUpdate.h>

  class HTTPUpdateLight {
  public:
    HTTPUpdateLight() {}

    // einfache URL-Variante -> erstelle lokalen Client
    HTTPUpdateResult update(const String& url, const String& currentVersion = "") {
      WiFiClient client;
      return httpUpdate.update(client, url, currentVersion);
    }

    // Variante mit vorgegebenem Client
    HTTPUpdateResult update(WiFiClient& client, const String& url, const String& currentVersion = "") {
      return httpUpdate.update(client, url, currentVersion);
    }

    void    rebootOnUpdate(bool reboot)        { httpUpdate.rebootOnUpdate(reboot); }
    int     getLastError() const               { return httpUpdate.getLastError(); }
    String  getLastErrorString() const         { return httpUpdate.getLastErrorString(); }

    // No-ops für "Light"-LED-API
    void setLedPin(int8_t, uint8_t) {}
    void setLedOn(uint8_t) {}
  };

#else
  // ESP8266: native Light-Implementierung nutzen
  #include <HTTPUpdateLight.h>
#endif
