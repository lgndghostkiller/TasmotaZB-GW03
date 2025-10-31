#pragma once
#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// zwingt Tasmota, diese Datei zu laden
#define USE_CONFIG_OVERRIDE

/**************
 * Ziel: ESP32 + Zigbee EZSP (Silabs) als TCP-Bridge
 * -> Kein ZNP, kein Berry, kein TLS, keine SD_MMC
 **************/

// Safety: Alles, was Probleme machte, hart abwählen
#ifdef USE_BERRY
#undef USE_BERRY
#endif
#ifdef USE_ZIGBEE_ZNP
#undef USE_ZIGBEE_ZNP
#endif
#ifdef USE_TLS
#undef USE_TLS
#endif
#ifdef USE_SCRIPT
#undef USE_SCRIPT
#endif
#ifdef USE_SDCARD
#undef USE_SDCARD
#endif

// Wir wollen EZSP + TCP-Bridge — die Defines kommen primär aus der INI,
// hier nur als Fallback (schadet nicht, wenn doppelt identisch definiert).
#ifndef USE_ZIGBEE
#define USE_ZIGBEE
#endif
#ifndef USE_ZIGBEE_EZSP
#define USE_ZIGBEE_EZSP
#endif
#ifndef USE_TCP_BRIDGE
#define USE_TCP_BRIDGE
#endif

// Optional: Webserver schlank halten
//#ifdef USE_EMULATION
//#undef USE_EMULATION
//#endif

// Falls Dein Build PSRAM-Zeug nicht mag, auslassen:
// #ifdef PIO_FRAMEWORK_ARDUINO_MMU_CACHE16_IRAM48_SECHEAP_SHARED
// #undef PIO_FRAMEWORK_ARDUINO_MMU_CACHE16_IRAM48_SECHEAP_SHARED
// #endif

#ifdef USE_BERRY
#undef USE_BERRY
#endif

#ifdef USE_BERRY_PSRAM
#undef USE_BERRY_PSRAM
#endif
#undef USE_BERRY
#endif  // _USER_CONFIG_OVERRIDE_H_
