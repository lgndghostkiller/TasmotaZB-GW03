#pragma once
#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// --- ZWINGEND: Tasmota lädt diese Datei ---
#define USE_CONFIG_OVERRIDE

// ========================================
// ZIEL: ESP32 + EFR32 (EZSP) als reine TCP-Bridge
// Kein ZNP, Berry, TLS, SD, Script, Display, IR, RF
// ========================================

// === 1. EXPLIZIT DEAKTIVIEREN (verhindert Include-Fehler) ===
#undef USE_SD_CARD
#undef USE_SD_CARD_MMC
#undef USE_SDCARD
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

// === 2. ZIGBEE EZSP + TCP BRIDGE AKTIVIEREN ===
#define USE_ZIGBEE
#define USE_ZIGBEE_EZSP
#define USE_TCP_BRIDGE

// === 3. ZUSÄTZLICHE OPTIMIERUNGEN (optional, aber empfohlen) ===
// Ethernet für ZB-GW03
#define USE_ETHERNET

// EEPROM für Zigbee-Netzwerk (I2C, GPIO32/33)
#define USE_ZIGBEE_EEPROM

// Fixer Zigbee-Kanal (EU: 11–26, 11 = stabil)
#define USE_ZIGBEE_CHANNEL 11

// LittleFS für OTA & Config (statt SPIFFS)
#define USE_UFILESYS
#define USE_LITTLEFS

// Minimales Logging (spart RAM/Flash)
#define SERIAL_LOG_LEVEL 0  // Kein Serial-Log im Bridge-Modus

// === 4. GPIO / UART für EZSP (ZB-GW03 v1.2 Standard) ===
#define ZIGBEE_DOUT_GPIO 1   // TX → EFR32 (GPIO1)
#define ZIGBEE_DIN_GPIO  3   // RX ← EFR32 (GPIO3)

// === 5. Ethernet PHY (LAN8720) ===
#undef ETH_TYPE
#define ETH_TYPE 0
#undef ETH_CLKMODE
#define ETH_CLKMODE 3

// === 6. PSRAM deaktivieren (ZB-GW03 hat keins) ===
#undef USE_PSRAM
#undef PIO_FRAMEWORK_ARDUINO_MMU_CACHE16_IRAM48_SECHEAP_SHARED

// === 7. Sonstiges ===
#define ROTATE_ZIGBEE  // Optional: Zigbee-Reset bei Boot

#endif  // _USER_CONFIG_OVERRIDE_H_
