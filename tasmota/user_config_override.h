/*
  user_config_override.h – lokale Overrides für Tasmota-Builds

  Zweck:
  - EZSP (Silabs) statt ZNP (TI)
  - TCP-Bridge aktivieren
  - Berry entfernen (verhindert fehlendes berry.h)
  - TLS/SD-Kartenkram deaktivieren, damit die fehlenden IDF-Header nicht gezogen werden
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// WICHTIG: sicherstellen, dass der Override überhaupt gezogen wird
#ifndef USE_CONFIG_OVERRIDE
  #define USE_CONFIG_OVERRIDE
#endif

/*******************************************************
 * Feature-Flags
 *******************************************************/
#undef USE_ZIGBEE_ZNP     // TI ZNP aus
#undef USE_BERRY          // Berry-Script aus (vermeidet "berry.h" Fehler)
#undef USE_TLS            // Kein HTTPS-Light (vermeidet HTTPUpdateLight.h)
#undef USE_SDCARD         // Kein SD/SD_MMC (vermeidet SD_MMC.h)

#define USE_ZIGBEE        // Zigbee an
#define USE_ZIGBEE_EZSP   // Silabs EZSP
#define USE_TCP_BRIDGE    // TCP-Bridge (Zigbee over TCP)

/*******************************************************
 * Optional: weitere Schlankmacherei (bei Bedarf einkommentieren)
 *******************************************************/
// #undef USE_DISCOVERY
// #undef USE_WEBSERVER
// #undef USE_IR_REMOTE
// #undef USE_ONEWIRE
// #undef USE_MODBUS

/*******************************************************
 * Projekt-/Device-Strings (optional, nur wenn du magst)
 *******************************************************/
// #undef  FRIENDLY_NAME
// #define FRIENDLY_NAME         "ZB-GW03-EZSP"
// #undef  PROJECT
// #define PROJECT               "TasmotaZB-GW03"

#endif  // _USER_CONFIG_OVERRIDE_H_
