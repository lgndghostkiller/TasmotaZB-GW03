#pragma once
// Stub für Arduino-ESP32 Cores ohne esp_private/esp_gpio_reserve.h
// Verhindert Build-Fehler; Reservelogik ist für uns nicht kritisch.

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

static inline int esp_gpio_reserve(int gpio_num) {
  (void)gpio_num;
  return 0;               // 0 = OK
}

static inline void esp_gpio_release(int gpio_num) {
  (void)gpio_num;
}

#ifdef __cplusplus
}
#endif
