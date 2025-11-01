#pragma once
#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// --- ZWINGEND: Tasmota lädt diese Datei ---
#define USE_CONFIG_OVERRIDE

// ========================================
// ZIEL: ESP32 + EFR32 (EZSP) als reine TCP-Bridge
// Nur das, was NICHT in platformio_override.ini steht!
// ========================================

// === 1. SD KOMPLETT DEAKTIVIEREN (sicherheitshalber, falls Basis-Env SD aktiviert) ===
#undef USE_SD_CARD
#undef USE_SD_CARD_MMC
#undef USE_SDCARD

// === 2. UNNÖTIGE FEATURES DEAKTIVIEREN (falls nicht in INI) ===
#undef USE_BERRY
#undef USE_BERRY_PSRAM
#undef USE_ZIGBEE_ZNP
#undef USE_TLS
#undef USE_SCRIPT
#undef USE_DISPLAY
#undef USE_IR_REMOTE
#undef USE_IR_REMOTE_FULL
#undef USE_RC_SWITCH
#undef USE_RF_FLASH
#undef USE_EMULATION
#undef USE_EMULATION_HUE
#undef USE_EMULATION_WEMO

// === 3. PSRAM deaktivieren (ZB-GW03 hat keins) ===
#undef USE_PSRAM
#undef PIO_FRAMEWORK_ARDUINO_MMU_CACHE16_IRAM48_SECHEAP_SHARED

// === 4. ALLES ANDERE (Zigbee, Ethernet, GPIO, etc.) → in platformio_override.ini! ===
// NICHT hier definieren → vermeidet "redefined" Warnings!

#endif  // _USER_CONFIG_OVERRIDE_H_
