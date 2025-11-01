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

  // Rückgabetyp wie im Core
  using HTTPUpdateResult = t_httpUpdate_return;

  class HTTPUpdateLight {
  public:
    HTTPUpdateLight() {}

    // einfache URL-Variante: intern eigenen Client erzeugen
    HTTPUpdateResult update(const String& url, const String& currentVersion = "") {
      WiFiClient client;
      return httpUpdate.update(client, url, currentVersion);
    }

    // Variante mit vorgegebenem Client
    HTTPUpdateResult update(WiFiClient& client, const String& url, const String& currentVersion = "") {
      return httpUpdate.update(client, url, currentVersion);
    }

    // Forwarder/Kompatibilität
    void   rebootOnUpdate(bool reboot)              { httpUpdate.rebootOnUpdate(reboot); }
    int    getLastError() const                     { return httpUpdate.getLastError(); }
    String getLastErrorString() const               { return httpUpdate.getLastErrorString(); }

    // Optional-API (no-ops)
    void setLedPin(int8_t, uint8_t) {}
    void setLedOn(uint8_t) {}
  };

#else
  // Für ESP8266 nutzt Tasmota üblicherweise die vorhandene Implementierung
  #include <ESP8266httpUpdate.h>
  using HTTPUpdateResult = t_httpUpdate_return;
  // Wenn du hier auch eine Light-Klasse brauchst, könnte man sie analog bauen.
#endif
