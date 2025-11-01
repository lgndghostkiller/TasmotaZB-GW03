#pragma once
// Kompatibilitäts-Wrapper für Tasmota auf ESP32.
// Mappt "HTTPUpdateLight" auf den Core-HTTPUpdater.

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

    // einfache URL-Variante
    HTTPUpdateResult update(const String& url, const String& currentVersion = "") {
      return httpUpdate.update(url, currentVersion);
    }

    // mit vorgegebenem Client
    HTTPUpdateResult update(WiFiClient& client, const String& url, const String& currentVersion = "") {
      return httpUpdate.update(client, url, currentVersion);
    }

    // Kompatible No-ops/Forwarder
    void rebootOnUpdate(bool reboot) { httpUpdate.rebootOnUpdate(reboot); }
    int  getLastError() const { return httpUpdate.getLastError(); }
    String getLastErrorString() const { return httpUpdate.getLastErrorString(); }

    // LED-API existiert bei Light-Implementierungen teils — wir ignorieren sie sauber.
    void setLedPin(int8_t, uint8_t) {}
    void setLedOn(uint8_t) {}
  };

#else
  // Auf ESP8266 existiert die „Light“-Implementierung u.U. nativ.
  #include <HTTPUpdateLight.h>
#endif
