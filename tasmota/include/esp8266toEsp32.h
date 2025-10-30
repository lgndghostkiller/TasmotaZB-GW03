#pragma once
#include <stdint.h>
#include <stddef.h>

// ESP8266-typische Typaliases für ESP32 bereitstellen
typedef int8_t   sint8_t;
typedef int16_t  sint16_t;
typedef int32_t  sint32_t;

// Häufig genutzte Macros/No-ops für Kompatibilität
#ifndef ICACHE_RAM_ATTR
  #define ICACHE_RAM_ATTR
#endif
#ifndef ICACHE_RODATA_ATTR
  #define ICACHE_RODATA_ATTR
#endif
#ifndef PROGMEM
  #define PROGMEM
#endif
#ifndef pgm_read_byte
  #define pgm_read_byte(addr) (*(const uint8_t *)(addr))
#endif
#ifndef pgm_read_word
  #define pgm_read_word(addr) (*(const uint16_t *)(addr))
#endif
#ifndef pgm_read_dword
  #define pgm_read_dword(addr) (*(const uint32_t *)(addr))
#endif
