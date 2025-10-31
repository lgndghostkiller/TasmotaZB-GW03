#pragma once
#if defined(ARDUINO_ARCH_ESP32)
  #include <esp_spi_flash.h>
#else
  // Auf 8266 existiert das Original spi_flash.h
  #include_next "spi_flash.h"
#endif
