/*
  user_config_override.h – lokale Overrides
  Ziel:
   - EZSP/TCP-Bridge bauen
   - ZNP/Berry/TLS/SD-Karte zuverlässig AUS
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
#define _USER_CONFIG_OVERRIDE_H_

// sicherstellen, dass Overrides gezogen werden
#ifndef USE_CONFIG_OVERRIDE
  #define USE_CONFIG_OVERRIDE
#endif

// HART AUS: Sachen, die dir den Build kaputt machen
#undef USE_ZIGBEE_ZNP    // TI-Stack aus
#undef USE_BERRY         // vermeidet "berry.h"
#undef USE_TLS           // vermeidet HTTP(S)-Sonderkram
#undef USE_SDCARD        // verhindert SD/SD_MMC-Header

// Hinweis: EZSP/TCP aktivieren wir über die Build-Flags, um redefined-Warnungen zu vermeiden.

#endif  // _USER_CONFIG_OVERRIDE_H_
