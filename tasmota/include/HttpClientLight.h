#pragma once
// Leichter HTTP-Client für ESP32 – Wrapper um Arduino HTTPClient.
// Deckt die üblichen Tasmota-Aufrufe ab (GET/POST, Header, Timeout, Stream).

#if defined(ARDUINO_ARCH_ESP32)
  #include <Arduino.h>
  #include <WiFi.h>
  #include <WiFiClient.h>
  #include <HTTPClient.h>

  class HttpClientLight {
  public:
    HttpClientLight() : _timeout_ms(12000) {} // Tasmota-typischer Default

    // Begin mit URL (String oder C-String)
    bool begin(const String& url) {
      _http.setTimeout(_timeout_ms);
      return _http.begin(url);
    }
    bool begin(const char* url) {
      _http.setTimeout(_timeout_ms);
      return _http.begin(String(url));
    }
    // Begin mit existierendem Client (optional gebraucht)
    bool begin(WiFiClient& client, const String& url) {
      _http.setTimeout(_timeout_ms);
      return _http.begin(client, url);
    }

    // Header setzen
    void addHeader(const String& name, const String& value, bool first = true, bool replace = true) {
      (void)first; (void)replace; // HTTPClient kennt die Flags nicht – ignorieren
      _http.addHeader(name, value);
    }

    // Methoden
    int GET() { return _http.GET(); }

    int POST(const String& contentType, const String& payload) {
      _http.addHeader(F("Content-Type"), contentType);
      return _http.POST((uint8_t*)payload.c_str(), payload.length());
    }

    int PUT(const String& contentType, const String& payload) {
      _http.addHeader(F("Content-Type"), contentType);
      return _http.sendRequest("PUT", (uint8_t*)payload.c_str(), payload.length());
    }

    // Antwort
    String getString() { return _http.getString(); }
    int getSize() { return (int)_http.getSize(); }
    WiFiClient* getStreamPtr() { return _http.getStreamPtr(); }

    // Timeout/User-Agent (falls Tasmota das setzt)
    void setTimeout(uint16_t ms) { _timeout_ms = ms; _http.setTimeout(_timeout_ms); }
    void setUserAgent(const String& ua) { _http.setUserAgent(ua.c_str()); }

    // Ende
    void end() { _http.end(); }

    // Status/Fehler
    int getLastError() const { return (int)_http.errorToString(_last_err_code).length() ? _last_err_code : 0; }
    String getLastErrorString() const { return _http.errorToString(_last_err_code); }

  private:
    HTTPClient _http;
    uint16_t _timeout_ms;
    int _last_err_code{0};
  };

#else
  // Auf ESP8266 existiert ggf. ein natives HttpClientLight
  #include <HttpClientLight.h>
#endif
